#ifndef DISPLAY_H
#define DISPLAY_H

//Includes

//Macros

/* AS1115 Command Bytes: 8 Digit registers */
#define AS1115_I2C_DIG0_ADR     0x01
#define AS1115_I2C_DIG1_ADR     0x02
#define AS1115_I2C_DIG2_ADR     0x03
#define AS1115_I2C_DIG3_ADR     0x04
#define AS1115_I2C_DIG4_ADR     0x05
#define AS1115_I2C_DIG5_ADR     0x06
#define AS1115_I2C_DIG6_ADR     0x07
#define AS1115_I2C_DIG7_ADR     0x08

/* AS1115 Command Bytes: 11 Control registers */
#define AS1115_I2C_DECODE_MODE_ADR      0x09
#define AS1115_I2C_GLOBAL_INTEN_ADR     0x0A
#define AS1115_I2C_SCAN_LIM_ADR         0x0B
#define AS1115_I2C_SHUTDOWN_ADR         0x0C
#define AS1115_I2C_SELF_ADRS_ADR        0x0D
#define AS1115_I2C_FEATURE_ADR          0x0E
#define AS1115_I2C_DISP_TEST_ADR        0x0F
#define AS1115_I2C_DIG01_INTEN_ADR      0x10
#define AS1115_I2C_DIG23_INTEN_ADR      0x11
#define AS1115_I2C_DIG45_INTEN_ADR      0x12
#define AS1115_I2C_DIG67_INTEN_ADR      0x13

/* AS1115 Command Bytes: 10 Diagnostic registers */
#define AS1115_I2C_DIAG_DIG0_ADR     0x14
#define AS1115_I2C_DIAG_DIG1_ADR     0x15
#define AS1115_I2C_DIAG_DIG2_ADR     0x16
#define AS1115_I2C_DIAG_DIG3_ADR     0x17
#define AS1115_I2C_DIAG_DIG4_ADR     0x18
#define AS1115_I2C_DIAG_DIG5_ADR     0x19
#define AS1115_I2C_DIAG_DIG6_ADR     0x1A
#define AS1115_I2C_DIAG_DIG7_ADR     0x1B
#define AS1115_I2C_KEYA_ADR          0x1C
#define AS1115_I2C_KEYB_ADR          0x1D

//Function Declarations
void DisplayInit();
void DispUpdate(const uint8_t seq_n, const uint8_t *value);

#endif
