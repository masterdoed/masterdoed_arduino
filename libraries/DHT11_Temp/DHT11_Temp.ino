#include <dht11.h>



dht11 DHT11;

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  doDHT();
  delay(10000);
}

void doDHT() {
  //read
  int chk = DHT11.read(2);
  // check readings
  switch (chk)
  {
    case 0: /**Serial.println("OK")**/; break;
    case -1: Serial.println("Checksum error"); break;
    case -2: Serial.println("Time out error"); break;
    default: Serial.println("Unknown error"); break;
  }
  //do output
  //Serial.print("indoor_temp ");
  Serial.print((float)DHT11.temperature, DEC);
  Serial.print(",");
  //Serial.println("");
  //Serial.print("indoor_humidity ");
  Serial.print((float)DHT11.humidity, DEC);
  Serial.println("");
  }
