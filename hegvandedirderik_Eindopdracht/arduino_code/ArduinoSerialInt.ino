#include "Ultrasonic.h"
Ultrasonic ultrasonic(12, 13);

int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);


  calibrate();
}

void loop() {

  int val_buffer = ultrasonic.Ranging(CM);

  if (val_buffer < 50) // als binnen de 50cm, dat kan de sensor, blokkeert onzinwaarden en ruis
  {
    val += (val_buffer - val) / 4;
  }

  //Start
  Serial.write(0x53);
  Serial.write(0x74);
  Serial.write(0x61);
  Serial.write(0x72);
  Serial.write(0x74);
  //Data
  sendInt(val);
  
  delay(50);
}

void sendInt(int i)
{
  byte hi = i >> 8;
  byte lo = i & B11111111;
  Serial.write(hi);
  Serial.write(lo);
}

void calibrate()
{
  long val_cali = 0;
  for (int i = 0; i < 10; i++)
  {
    int val_buffer = ultrasonic.Ranging(CM);
    if (val_buffer < 500) // als binnen de 5m, dat kan de sensor, blokkeert onzinwaarden en ruis
      val_cali += val_buffer;
  }
  val = val_cali / 10;
}

