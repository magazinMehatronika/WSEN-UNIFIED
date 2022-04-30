/*
  --------------------------------------------------------------------
  TIDS/HIDS - Read Combination


  This example reads the humidity parameter from the HIDS sensor and
  temperature from the TIDS sensor, printing both out on the serial
  port.

  Due to possible errors during initial readout from the HIDS sensor,
  sketch skips first few readouts. This error is small (<5%) and does
  not happen on every bootup.

  Example by magazin Mehatronika, using modified WSEN_UNIFIED library.
  --------------------------------------------------------------------
*/

#include "WSEN_TIDS.h"
#include "WSEN_HIDS.h"


Sensor_TIDS sensor;
Sensor_HIDS sensor2;


int ODR = 1;

int firstRead = 4; //First read counter

void setup()
{

  Serial.begin(9600);


  //Initialize both sensors in continuous mode and assign addresses
  sensor.init(TIDS_ADDRESS_I2C_1);
  sensor2.init(HIDS_ADDRESS_I2C_0);
  sensor.SW_RESET();
  sensor.set_continuous_mode(ODR);
  sensor2.set_continuous_mode(ODR);



}

void loop()
{

  // Read and calculate the temperature
  I2CSetAddress(TIDS_ADDRESS_I2C_1); //Manual address set for TIDS; not implemented in the read_temperature() method
  float temperature = sensor.read_temperature();

  I2CSetAddress(HIDS_ADDRESS_I2C_0); //Manual address set for HIDS; not implemented in the get_Humidity() method
  float humidity = sensor2.get_Humidity();



  Serial.print(temperature);
  Serial.println(" degC");
  if (firstRead == 0){
  Serial.print(humidity);
  Serial.println(" %");
  Serial.println("---------------");

  } else { // Dropping the first few readouts due to possible wrong values right after sensor startup...
    Serial.println("Humidity initialization...");
    Serial.println("---------------");

    firstRead--;
  }

  int waitMillis = 1000 / ODR;

  delay(waitMillis);
}
