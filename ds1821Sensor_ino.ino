#include <OneWire.h>
#include <Wire.c> 

OneWire  ds(10);  // Datenpin 10

// Setup
void setup(void) {
  Serial.begin(9600);
  ds.reset();

}

// Function to read count bytes from OneWire BUS
unsigned int readBytes(int count)
{
    unsigned int val = 0;
    for (int i = 0; i < count; i++)
    {
        val |= (unsigned int)(ds.read() << i * 8);
    }
    return val;
}

// Main Funktion
void loop(void) {
  byte temp_read = 0;
  unsigned int count_remain = 0;
  unsigned int count_per_c = 0;
  byte configuration_register = 0;

  ds.reset();
  // Start Converting the temperatures 
  ds.write(0xEE);  
  
   do {
        delay(1);
        configuration_register = 0;
        ds.reset();
        ds.write(0xAC);

        // Read the configuration Register from the DS1821
        configuration_register = readBytes(1);
    } while ((configuration_register & (1 << 7)) == 0); // If Bit #8 is 1 then we are finished converting the temp

  
    // Get Temp
    ds.reset();
    ds.write(0xAA);
    temp_read = readBytes(1); ;

    // Get Count Remaining
    ds.reset();
    ds.write(0xA0);
    count_remain = readBytes(2);

    // Load The Counter to populate the slope accumulator
    ds.reset();
    ds.write(0x41);

    // Read Count Per Deg
    ds.reset();
    ds.write(0xA0);
    count_per_c = readBytes(2);

    // If we are reading above the 200 mark then we are below 0 and need to compensate the calculation
    if (temp_read >= 200) temp_read -= 256;
    
    // equation from ds1821 specs
    float highResTemp = (float)temp_read - .5 + (((float)count_per_c - (float)count_remain) / (float)count_per_c);
    
    // write on serial bus
    Serial.print(highResTemp);
    Serial.println(" Celsius");
   
   // wait one minute
   delay(60000);
}
