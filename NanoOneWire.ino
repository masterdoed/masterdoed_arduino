#include <OneWire.h> 

int DS18S20_Pin = 3; //DS18S20 Signal pin on digital 2
int sensorpin = A0;

OneWire ds(DS18S20_Pin); // on digital pin 2

void setup () {
 Serial.begin(9600);
}

void loop () {

  delay(1000);
  
int sensorval = analogRead(sensorpin);
int tempC = map(sensorval, 353, 378, 28, 50);
Serial.println ("### Analog ###");
Serial.print (tempC);
Serial.print (" ");
Serial.println (sensorval);


//OneWire
Serial.println ("### OneWire ###");

 byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];
 
  if ( !ds.search(addr)) {
      Serial.print("Keine weiteren Addressen.\n");
      ds.reset_search();
      return;
  }
 
  Serial.print("R=");
  for( i = 0; i < 8; i++) {
    Serial.print(addr[i], HEX);
    Serial.print(" ");
  }
 
  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.print("CRC nicht gültig!\n");
      return;
  }
 
  if ( addr[0] == 0x10) {
      Serial.print("Gerät ist aus der DS18S20 Familie.\n");
  }
  else if ( addr[0] == 0x28) {
      Serial.print("Gerät ist aus der DS18B20 Familie.\n");
  }
  else {
      Serial.print("Gerätefamilie nicht erkannt : 0x");
      Serial.println(addr[0],HEX);
      return;
  }
 
  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);         // start Konvertierung, mit power-on am Ende
 
 
 
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Wert lesen
 
  Serial.print("P=");
  Serial.print(present,HEX);
  Serial.print(" ");
  for ( i = 0; i < 9; i++) {           // 9 bytes
    data[i] = ds.read();
    Serial.print(data[i], HEX);
    Serial.print(" ");
  }
  Serial.print(" CRC=");
  Serial.print( OneWire::crc8( data, 8), HEX);
  Serial.println();


delay(500);
}

