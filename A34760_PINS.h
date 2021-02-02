#ifndef __A34760_PINS_H
#define __A34760_PINS_H

#include <p30f6014a.h>
#include "Config.h"

#define TRIS_OUTPUT_MODE 0
#define TRIS_INPUT_MODE  1



//------------------- High Voltage Lambda I/O ------------------------- //
// HV Lambda Ouput Pins
#define PIN_HV_LAMBDA_ENABLE                 _LATD11
#define TRIS_PIN_HV_LAMBDA_ENABLE            _TRISD11
#define OLL_HV_LAMBDA_ENABLED                1

#define PIN_HV_LAMBDA_INHIBIT                _LATD0
#define TRIS_PIN_HV_LAMBDA_INHIBIT           _TRISD0

// HV Lambda Input Pins
#ifdef __PFN_800_HZ
// This is an 800Hz PFN, use the alternate EOC input
#define PIN_HV_LAMBDA_EOC_INPUT              _RB7   // PIN22 / RB7 / AN7
#define TRIS_PIN_HV_LAMBDA_EOC_INPUT         _TRISB7
#define ILL_HV_LAMBDA_AT_EOC                 1
#define OLL_HV_LAMBDA_INHIBITED              0

#else
// This is a 400Hz PFN, use the standard EOC input
#define PIN_HV_LAMBDA_EOC_INPUT              _RD2
#define TRIS_PIN_HV_LAMBDA_EOC_INPUT         _TRISD2
#define ILL_HV_LAMBDA_AT_EOC                 0
#define OLL_HV_LAMBDA_INHIBITED              1

#endif


#define PIN_HV_LAMBDA_SUM_FAULT              _RC14
#define TRIS_PIN_HV_LAMBDA_SUM_FAULT         _TRISC14
#define ILL_HV_LAMBDA_SUM_FAULT_FAULTED      0

#define PIN_HV_LAMBDA_HV_ON_READBACK         _RC13
#define TRIS_PIN_HV_LAMBDA_HV_ON_READBACK    _TRISC13
#define ILL_HV_LAMBDA_READBACK_HV_ON         0

// This pin moved to IO Expander
//#define PIN_HV_LAMBDA_TEMP_FAULT             _RE3
//#define TRIS_PIN_HV_LAMBDA_TEMP_FAULT        _TRISE3
//#define ILL_HV_LAMBDA_OVER_TEMP_FAULT        0

// This pin moved to IO Expander
//#define PIN_HV_LAMBDA_INTLK_FLT              _RE2
//#define TRIS_PIN_HV_LAMBDA_INTLK_FLT         _TRISE2
//#define ILL_HV_LAMBDA_INTLK_FAULTED          0

// This pin moved to IO Expander
//#define PIN_HV_LAMBDA_LOAD_FLT               _RE1
//#define TRIS_PIN_HV_LAMBDA_LOAD_FLT          _TRISE1
//#define ILL_HV_LAMBDA_LOAD_FAULTED           0

// This pin moved to IO Expander
//#define PIN_HV_LAMBDA_PHASE_LOSS_FLT        _RE0
//#define TRIS_PIN_HV_LAMBDA_PHASE_LOSS_FLT   _TRISE0
//#define ILL_HV_LAMBDA_PHASE_FAULT           0

#define PIN_HV_LAMBDA_POWER_UP              _RD1
#define TRIS_PIN_HV_LAMBDA_POWER_UP         _TRISD1
#define ILL_PIN_HV_LAMBDA_DID_NOT_POWER_UP  1






//------------------- Magnetron Magnet I/O ------------------------- //
// Magnetron Magnet Output Pins
#define PIN_MAGNETRON_MAGNET_ENABLE          _LATD9
#define TRIS_PIN_MAGNETRON_MAGNET_ENABLE     _TRISD9
#ifdef __MK_POWER_SUPPLIES
#define OLL_MAGNETRON_MAGNET_ENABLED         1
#else
#define OLL_MAGNETRON_MAGNET_ENABLED         0
#endif

#define PIN_MAGNETRON_MAGNET_SO              _LATD10
#define TRIS_PIN_MAGNETRON_MAGNET_SO         _TRISD10
#define OLL_MAGNETRON_MAGNET_OUTPUT_SHUT_OFF 0


//------------------- Magnetron Heater I/O ------------------------- //
// Magnetron Heater Output Pins
#define PIN_MAGNETRON_FILAMENT_ENABLE        _LATD8
#define TRIS_PIN_MAGNETRON_FILAMENT_ENABLE   _TRISD8
#define OLL_MAGNETRON_FILAMENT_ENABLED       1



// ----------------- Digital Optical Input Pins -------------------- //
#define PIN_MODULATOR_DRIVE_INPUT            _RA12 
#define TRIS_PIN_MODULATOR_DRIVE_INPUT       _TRISA12
#define ILL_MODULATOR_DRIVE_ACTIVE           1

#define PIN_A_B_MODE_SELECT                  _RA13
#define TRIS_PIN_A_B_MODE_SELECT             _TRISA13
#define ILL_A_MODE_SELECTED                  1

#ifndef __A36760
// The third optical input is used for Serial RX2 or for generic Optical input on RF4
#else
#define PIN_CAN2_RX                          _RG0
#define TRIS_PIN_CAN2_RX                     _TRISG0
#define ILL_CAN2_LIGHT_IN                    1
#endif

// ------------------ Digital Optical Output Pins ------------------ //


#define PIN_SUM_FAULT_FIBER                  _LATA7
#define TRIS_PIN_SUM_FAULT_FIBER             _TRISA7
#define OLL_SUM_FAULT_FIBER_FAULT            0


#ifndef __A36760
//#define PIN_SPARE_OPTICAL_OUT                _LATA9
//#define TRIS_PIN_SPARE_OPTICAL_OUT           _TRISA9
//#define OLL_SPARE_OPTICAL_OUT_LIGHT_ON       1
#else
#define PIN_CAN1_TX                            _LATF1
#define TRIS_PIN_CAN1_TX                       _TRISF1
#define OLL_CAN1_TX_LIGHT_ON                   1  
#endif


#ifndef __A36760
// Note this is the same pin as spare optical out, it just uses different names
#define PIN_FAST_RESTART_STORAGE_CAP_INPUT   _RA9
#define PIN_FAST_RESTART_STORAGE_CAP_OUTPUT  _LATA9
#define TRIS_PIN_FAST_RESTART_STORAGE_CAP    _TRISA9
#else
#define PIN_FAST_RESTART_STORAGE_CAP_INPUT   _RB15
#define PIN_FAST_RESTART_STORAGE_CAP_OUTPUT  _LATB15
#define TRIS_PIN_FAST_RESTART_STORAGE_CAP    _TRISB15
#endif
#define OLL_DO_FAST_RESTART                  0
#define ILL_DO_FAST_RESTART                  0


#ifndef __A36760
#define PIN_UART2_TX                         _LATF5
#define TRIS_PIN_UART2_TX                    _TRISF5
#else
#define PIN_CAN2_TX                         _LATG1
#define TRIS_PIN_CAN2_TX                    _TRISG1

#endif
#define OLL_PIN_UART2_TX_LIGHT_ON            1
#define OLL_PIN_CAN2_TX_LIGHT_ON             OLL_PIN_UART2_TX_LIGHT_ON






// The thyratron optical trigger output is just fed through the board.  It can be inhibited by the pic but is not generated by a pic output pin



// ---- Digital Input Pins ------------ //
// Control Input Pins
#define PIN_FP_MODULATOR_ENABLE_INPUT        _RA14  
#define TRIS_FP_PIN_MODULATOR_ENABLE_INPUT   _TRISA14
#define ILL_MODULATOR_ENABLED                0

#define PIN_FP_MODULATOR_HV_ON_INPUT         _RA15  
#define TRIS_FP_PIN_MODULATOR_HV_ON_INPUT    _TRISA15
#define ILL_MODULATOR_HV_ON                  0

#define PIN_FP_MODULATOR_RESET               _RG13
#define TRIS_FP_PIN_MODULATOR_RESET          _TRISG13
#define ILL_MODULATOR_RESET                  0

#define PIN_FP_FAST_RESTART                 _RG12
#define TRIS_FP_PIN_FAST_RESTART            _TRISG12
#define ILL_FAST_RESTART                    0

// PIN_FP_SPARE_INPUT_1, PIN_FP_SPARE_INPUT_4

#define PIN_GANTRY_PORTAL_SELECT                _RG15
#define TRIS_PIN_GANTRY_PORTAL_SELECT           _TRISG15
#define ILL_GANTRY_MODE                         0


#define PIN_FP_SPARE_2_SAMPLE_VPROG_INPUT       _RG14
#define TRIS_FP_PIN_SPARE_2_SAMPLE_VPROG_INPUT  _TRISG14
#define ILL_SAMPLE_VPROG_INPUT                  0

// Fault Input pins
#define PIN_PULSE_OVER_CUR_LATCH             _RD4
#define TRIS_PIN_PULSE_OVER_CUR_LATCH        _TRISD4
#define ILL_PULSE_OVER_CURRENT_FAULT         0

#define PIN_PULSE_MIN_CUR_LATCH              _RD7
#define TRIS_PIN_PULSE_MIN_CUR_LATCH         _TRISD7
#define ILL_PULSE_MIN_CURRENT_FAULT          1

#define PIN_MAGNET_CURRENT_OOR_LATCH         _RD12
#define TRIS_PIN_MAGNET_CURRENT_OOR_LATCH    _TRISD12
#define ILL_MAGNET_CURRENT_OOR_FAULT         0

#define PIN_FILAMENT_OV_LATCH                _RD13
#define TRIS_PIN_FILAMENT_OV_LATCH           _TRISD13
#define ILL_FILAMENT_OV_FAULT                0



#define PIN_INTERLOCK_1                      _RC3                 
#define TRIS_PIN_INTERLOCK_1                 _TRISC3
#define ILL_INTERLOCK_OPEN                   1                                       

#define PIN_INTERLOCK_2                      _RC4                 
#define TRIS_PIN_INTERLOCK_2                 _TRISC4

#define PIN_INTERLOCK_3                      _RG8                 
#define TRIS_PIN_INTERLOCK_3                 _TRISG8

#define PIN_INTERLOCK_4                      _RG9              
#define TRIS_PIN_INTERLOCK_4                 _TRISG9

#define PIN_4_20_DRVR_FLT                    _RA10
#define TRIS_PIN_4_20_DRVR_FLT               _TRISA10
#define ILL_4_20_DRIVER_FAULT                0 

// ---- Digital Output Pins ------------ //

#define PIN_THYRATRON_TRIGGER_ENABLE         _LATA6
#define TRIS_PIN_THYRATRON_TRIGGER_ENABLE    _TRISA6
#define OLL_THYRATRON_TRIGGER_ENABLED        1

#define PIN_SUM_FAULT_COPPER                 _LATC2
#define TRIS_PIN_SUM_FAULT_COPPER            _TRISC2
#define OLL_SUM_FAULT_COPPER_FAULT           0

#define PIN_LATCH_RESET                      _LATD3
#define TRIS_PIN_LATCH_RESET                 _TRISD3
#define OLL_RESET_LATCH                      0
#define DELAY_LATCH_RESET                    60  // 2uS at 30 MHz Clock

#ifndef __A36760
#define PIN_PULSE_LATCH_RESET                _LATG1
#define TRIS_PIN_PULSE_LATCH_RESET           _TRISG1
#else
#define PIN_PULSE_LATCH_RESET                _LATF5
#define TRIS_PIN_PULSE_LATCH_RESET           _TRISF5
#endif
#define OLL_PULSE_LATCH_RESET                0
#define DELAY_PULSE_LATCH_RESET              3000 // 100uS at 30 MHz Clock 


#define OLL_LED_ON                           0


#ifndef __A36760
#define PIN_MAIN_CONTACTOR_CLOSE             _LATF0
#define TRIS_PIN_MAIN_CONTACTOR_CLOSE        _TRISF0
#else

#define PIN_LED1                             _LATB7
#define TRIS_PIN_LED1                        _TRISB7

#define PIN_LED3                             _LATB6
#define TRIS_PIN_LED3                        _TRISB6  

#define PIN_UART2_TX                         PIN_LED3
#define TRIS_PIN_UART2_TX                    TRIS_PIN_LED3


#define PIN_MAIN_CONTACTOR_CLOSE             PIN_LED1
#define TRIS_PIN_MAIN_CONTACTOR_CLOSE        TRIS_PIN_LED1

#define PIN_CAN1_RX                          _LATF0
#define TRIS_CAN1_RX                         _TRISF0
#define OLL_CAN1_RX_LIGHT_ON                 1
#endif
#define OLL_MAIN_CONTACTOR_CLOSED            1

#define PIN_SAMPLE_PFN_IREV                  _LATB2
#define TRIS_PIN_SAMPLE_PFN_IREV             _TRISB2
#define OLL_SAMPLE_PFN_IREV_TRIGGER          1

#ifndef __A36760
#define PIN_RS422_DE                         _LATG0
#define TRIS_PIN_RS422_DE                    _TRISG0
#else
#define PIN_RS422_DE                         _LATF4
#define TRIS_PIN_RS422_DE                    _TRISF4
#endif
#define OLL_RS422_DE_ENABLE_RS422_DRIVER     1

#define PIN_MCU_CLOCK_OUT_TEST_POINT         _LATC15
#define TRIS_PIN_MCU_CLOCK_OUT_TEST_POINT    _TRISC15

#define PIN_LAMBDA_VOLTAGE_SELECT            _LATB14
#define TRIS_PIN_LAMBDA_VOLTAGE_SELECT       _TRISB14
#define OLL_SELECT_LAMBDA_MODE_A_VOLTAGE     0

#define PIN_PULSE_IMON_CS                    _LATD6
#define TRIS_PIN_PULSE_IMON_CS               _TRISD6
#define OLL_SELECT_PULSE_IMON_ADC            0

#define PIN_PULSE_VMON_CS                    _LATD5  
#define TRIS_PIN_PULSE_VMON_CS               _TRISD5
#define OLL_SELECT_PULSE_VMON_ADC            0

#ifndef __A36760
#define PIN_PULSE_ADC_TRIGGER                _LATF1
#define TRIS_PIN_PULSE_ADC_TRIGGER           _TRISF1
#else
#define PIN_PULSE_ADC_TRIGGER                _LATA9
#define TRIS_PIN_PULSE_ADC_TRIGGER           _TRISA9
#endif
#define OLL_TRIGGER_PULSE_ADCS               1

// -----------------------  END IO PIN CONFIGURATION ------------------------ //



#endif
