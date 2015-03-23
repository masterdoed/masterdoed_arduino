int sensorpin = A0;

void setup () {
 Serial.begin(9600);
}

void loop () {
  
  int sensorval = analogRead(sensorpin);
  //int tempC = map(sensorval, 353, 378, 28, 50);
  Serial.println ("### Analog ###");
  //Serial.print (tempC);
  //Serial.print (" ");
  Serial.println (sensorval);

  delay(1000);

}

