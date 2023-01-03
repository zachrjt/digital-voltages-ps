#include "display.h"
#include <Wire.h>

/*
 * (TODO)
 *  -Improve wire code for faster TWI speeds per megaTinyCore
 *    (https://github.com/SpenceKonde/megaTinyCore)
 *  -Add self-test functionality with return value checking for DisplayInit
*/

void DisplayInit()
{
  Wire.begin();
  Wire.beginTransmission(i2c_addr);
  Wire.write(AS1115_I2C_SHUTDOWN_ADR);
  Wire.write(0x01); //normal operation, reset registers
  Wire.endTransmission();
  
  Wire.beginTransmission(i2c_addr);
  Wire.write(AS1115_I2C_FEATURE_ADR);
  Wire.write(0x04); // set hex decode, no blink, no reset, internal osc
  Wire.endTransmission();
  
  Wire.beginTransmission(i2c_addr);
  Wire.write(AS1115_I2C_DECODE_MODE_ADR);
  Wire.write(0x3F); // hex-decode for digits 0:5
  Wire.endTransmission();

  Wire.beginTransmission(i2c_addr);
  Wire.write(AS1115_I2C_GLOBAL_INTEN_ADR);
  Wire.write(0x0F); // 15/16 (max)
  //Wire.write(0x07); // 8/16 (medium)
  //Wire.write(0x00); // 1/16 (min)
  Wire.endTransmission();

  Wire.beginTransmission(i2c_addr);
  Wire.write(AS1115_I2C_SCAN_LIM_ADR);
  Wire.write(0x04); // display all digits 0:4, scan line
  Wire.endTransmission();

  //Perform Display Test (TODO)
  
  return;
}

void DispUpdate(const uint8_t seq_n, const uint8_t *value)
{
  uint8_t temp_val = 0x00;
  for (uint8_t i = 0; i < seq_n; i++)
  {
    temp_val = *(value+i);
    if ((i==0) || (i==2))
    {
      temp_val += 0x80; // Adds decimal place to 1st and 3rd digit
    }
    
    Wire.beginTransmission(i2c_addr);
    Wire.write((AS1115_I2C_DIG0_ADR + i));
    Wire.write(temp_val);
    Wire.endTransmission();
  }
  return;
}
  
