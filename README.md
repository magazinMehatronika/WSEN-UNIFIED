# WSEN-UNIFIED modified library for WE Sensor FeatherWing

The WSEN-UNIFIED is a fork of the original Wurth Sensor library for Wurth eiSos sensors, providing a combined way of reading from multiple sensors which can be found on the Wurth Sensor FeatherWing.

We tried optimizing the library for use with several sensors at once. There were several minor issues we tried to addess by unifying the four separate libraries (as offered by Wurth in the original repo).

This library might contain older code revisions and will not be actively mantained.

This library contains code created by the Wurth eiSos team.

## Usage notes

Installation of the library follows the same process as all manual Arduino library installations. Simply select the /libraries/WSEN-UNIFIED.zip file from the library manager.

Once that is complete, you should see WSEN_UNIFIED under the library list. Examples should also be loaded. If not, restart your IDE.

Examples are now sorted under the same folder, but in multiple subfolders with more descriptive names. To include multiple library files, use the same header files as you would normally.

Make sure to manually tell the MCU to set I2C addresses by using the `I2CSetAddress(<addr>);` command before every readout.

Example readout code:

```cpp
  // Read and calculate the temperature
  I2CSetAddress(TIDS_ADDRESS_I2C_1); //Manual address set for TIDS; not implemented in the read_temperature() method
  float temperature = sensor.read_temperature();

  I2CSetAddress(HIDS_ADDRESS_I2C_0); //Manual address set for HIDS; not implemented in the get_Humidity() method
  float humidity = sensor2.get_Humidity();
  ```
  
  ## Examples
  
  Included in the library are all examples provided by Wurth, as well as an example created to utilize two separate sensors reading in continous mode. For more in-depth explanations about sensor modes, consult the parent repository.
