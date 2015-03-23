#include <dht.h>

#include <OneWire.h>
#include <dht.h>

#define DHT11PIN 5 

     
// DS18S20 Temperaturchip i/o
OneWire ds(10);  // an pin 10
dht11 DHT11;
     
void setup(void) {
  Serial.begin(9600);
}
     
void loop(void) {
  doDHT();
  delay(10000);
}


// ***************************
// DHT11 Sensor Readings
void doDHT() {
  //read
  int chk = DHT11.read(5);
  // check readings
  switch (chk)
  {
    case 0: /**Serial.println("OK")**/; break;
    case -1: Serial.println("Checksum error"); break;
    case -2: Serial.println("Time out error"); break;
    default: Serial.println("Unknown error"); break;
  }
  //do output
  /
  Serial.print("outdoor_temp=");
  Serial.print((float)DHT11.temperature, DEC);
  Serial.println("");
  Serial.print("outdoor_humidity=");
  Serial.print((float)DHT11.humidity, DEC);
  Serial.println("");
  Serial.print("outdoor_dew=")
  Serial.print(DHT11.dewPointFast(), DEC);
  Serial.println();
}





