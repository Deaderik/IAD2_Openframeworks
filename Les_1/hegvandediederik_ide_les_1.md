DIEDERIK VAN DE HEG </BR>
IAD 2B / OPENFRAMEWORKS<BR>
<BR>


Om deze installatie te maken heb je volgens mij het volgende nodig: 

<ul>
<li> Vitrine   </li>
<li>   Hoofd </li>
<li>  Waterpomp  </li>
<li>  Arduino  </li>
<li>  Camera  </li>
<li>  Water   </li>
</ul> 

De software zou volgens mij het volgende moeten doen. Zodra er iemand voor het hoofd gaat staan, kan een camera of andere sensor detecteren dat er een persoon staat. Dit zou dus kunnen door bijvoorbeeld een infrarood camera. Na x aantal seconden gaat er een signaal naar de waterpomp, en krijgt deze de opdracht op het water door de ogen te pompen. Zodra de persoon niet meer voor het hoofd staat, is er geen camerasignaal meer, en kan de pomp stoppen met pompen. 

In pseudococe zou het er dus ongeveer zo uit kunnen zien: 

if(Nobody in front of the head
{
Pump == false; 



} else {

Pump == true; 


}