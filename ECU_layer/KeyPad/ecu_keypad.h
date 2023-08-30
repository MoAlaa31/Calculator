/* 
 * File:   ecu_keypad.h
 * Author: 2m
 *
 * Created on 28 April 2023, 18:19
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* Section : Includes */
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_keypad_cfg.h"

/* Section : Macro Declarations */
#define ECU_KEYPAD_ROWS     4

#if Type == Small_Calc
#define ECU_KEYPAD_COLUMNS  4
#endif

#if Type == Big_Clac
#define ECU_KEYPAD_COLUMNS  6
#endif
/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef struct{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROWS];
    pin_config_t keypad_column_pins[ECU_KEYPAD_COLUMNS];
}keypad_t;

/* Section : Functions Declarations */
Std_ReturnType keypad_initialize(const keypad_t *_keypad_obj);
Std_ReturnType keypad_get_value(const keypad_t *_keypad_obj, uint8 *value);

#endif	/* ECU_KEYPAD_H */

