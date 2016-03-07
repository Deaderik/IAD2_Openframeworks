#include "Ball.h"

Ball::Ball(int size, int speedx, int speedy)
{
	x = ofRandom(0, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());

    speedX = ofRandom(-1, 1)*speedx;           // and random speed and direction
    speedY = ofRandom(-1, 1)*speedy;

    radius = size;

    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}

void Ball::update()
{
	if (x < 0 )
	{
        x = 0;
        speedX *= -1;
	}
	else if (x > ofGetWidth())
	{
        x = ofGetWidth();
        speedX *= -1;
    }

    if (y < 0 )
	{
        y = 0;
        speedY *= -1;
    }
	else if (y > ofGetHeight())
	{
        y = ofGetHeight();
        speedY *= -1;
    }

    x+=speedX;
    y+=speedY;
}

void Ball::draw()
{
    ofSetColor(color);
    ofCircle(x, y, radius);
}
