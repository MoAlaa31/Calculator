/* 
 * File:   Application.h
 * Author: Mohmed.Alaa
 *
 * Created on 11 April 2023, 07:09
 */

#ifndef APPLICATION_H
#define	APPLICATION_H


/* Section : Includes */
#include "ECU_layer/ecu_layer_init.h"

/* Section : Macro Declarations */
#define _XTAL_FREQ 8000000UL

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
extern keypad_t keypad_1;
extern led_t led_1;
extern chr_lcd_4bit_t lcd_1;
extern chr_lcd_8bit_t lcd_2;

/* Section : Functions Declarations */
void application_intialize(void);


#endif	/* APPLICATION_H */

