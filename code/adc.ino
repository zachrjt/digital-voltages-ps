#include "adc.h"
/*
 * (TODO)
 *  -Transistion ADC code over to the megaTinycore non-standard functions for 
 *  hardware based 8 & 12bit burst sampling.
 *    (https://github.com/SpenceKonde/megaTinyCore/blob/master/megaavr/extras/Ref_Analog.md)
 *  -Create dibble-dabble or lut table conversion of ADC samples (depends on transistioned ADC code).
 *    Current adc sample conversion is HIGHLY inefficient (int32->string->int8).
*/
 
void Voltage_ADCReading()
{
  int temp_adc_value = 0x00;
  uint8_t input_pin = (value_state) ? PIN_PA1 : PIN_PA2; //False(default) = 3.3V, True = 5V
  
  analogReference(INTERNAL4V096);
  analogReadResolution(10);
  analogSampleDuration(10);
  delay(1);
  
  for (int i = 0x00; i < 0xFF; i++)
  {
    temp_adc_value = analogRead(input_pin);
    voltage = voltage + (temp_adc_value * (4.096/1024));
  }
  voltage = voltage/(128);
  
  disp_volt = String(voltage, 3);
  display_data[0] = (uint8_t)(disp_volt[0]) - 0x30;
  display_data[1] = (uint8_t)(disp_volt[2]) - 0x30;
  return;
}



void Current_ADCReading()
{
  int temp_adc_value = 0x00;
  uint8_t input_pin = (value_state) ? PIN_PA7 : PIN_PA6; //False(default) = 3.3V, True = 5V
  
  analogReference(EXTERNAL);
  analogReadResolution(12);
  analogSampleDuration(10);
  delay(1);
  
  for (int i = 0x00; i < 0xFF; i++)
  {
    temp_adc_value = analogRead(input_pin);
    current = current + (temp_adc_value * (2.08333333/4096));
  }
  current = current/(256);
  
  disp_amp = String(current, 4);
  display_data[2] = (uint8_t)(disp_amp[0]) - 0x30;
  display_data[3] = (uint8_t)(disp_amp[2]) - 0x30;
  display_data[4] = (uint8_t)(disp_amp[3]) - 0x30;
  return;
}


//legacy code
/*
void Voltage_ADCInitialize()
{
  //
  //Calibrate offset
  ADC0.CTRLA = 0x21; // Not run in standby sleep mode, low latency EN, ADC EN
  ADC0.CTRLB = 0x00; // Lowest prescale (div 2)
  ADC0.CTRLC = 0x07; // Internal 4.096V reference
  ADC0.CTRLE = 0x0; // 
  ADC0.CTRLF = 0x00;
  ADC0.CTRLD = 0x00; // Disable window comparator
  ADC0.INTCTRL = 0x01; // EN result ready interrupt
  ADC0.MUXPOS = 0x30; // NO PGA, Internal GND Connection
  delay(1);
  analogReference(INTERNAL4V096); //Requires VDD > 4.596V
  analogReadResolution(10);
  analogSampleDuration(6);
  return;
}

void Current_ADCInitialize()
{
  return;
}
*/
