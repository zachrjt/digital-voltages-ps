#include "main.h"

/*
 * (TODO)
 *  -Add ERROR checking indication via LED
 *    (https://github.com/SpenceKonde/megaTinyCore)
 *  -Improve the mode-switching button.
*/

//global constants

//global variables
bool value_state = false; //False=5V, True=3.3V

//Variables below are used in accumulated ADC-sample-to-BCD display conversion
float voltage = 0;
float current = 0;
String disp_volt = "";
String disp_amp = "";

uint8_t display_data[5] = {0,0,0,0,0};  // Stores the digit-values of the display

void setup()
{
  CLKCTRL.MCLKCTRLB = 0x00; // disable clock prescaling
  //Serial.pins(PIN_PC2 ,PIN_PC1); //hardware mod required for host uart-rx
  
  pinMode(CHIP_SELECT, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(MODE_PIN, INPUT);
  digitalWrite(CHIP_SELECT, HIGH);
  digitalWrite(LED_PIN, HIGH);
  
  DisplayInit();  //Initializes the display driver over I2C
}


void loop()
{
  Current_ADCReading();
  Voltage_ADCReading();
  
  DispUpdate(0x05, &display_data[0]);

  //Check if mode-button is being pressed (not the most efficent debouncing)
  if(digitalRead(MODE_PIN) == HIGH)
  {
    delay(60);
    if(digitalRead(MODE_PIN) == HIGH)
    {
      value_state = !(value_state);
      voltage = 0;
      current = 0;
    }
  }
}
