/* 
 * File:   ecu_layer_init.c
 * Author: 2m
 *
 * Created on 28 April 2023, 21:24
 */

#include "ecu_layer_init.h"

led_t led_1 = {
    .led_status = LED_OFF,
    .pin = GPIO_PIN0,
    .port_name = PORTA_INDEX
};

keypad_t keypad_1 = {
    .keypad_row_pins[0].port = PORTC_INDEX,
    .keypad_row_pins[0].pin = GPIO_PIN0,
    .keypad_row_pins[0].direction = GPIO_OUTPUT,
    .keypad_row_pins[0].logic = GPIO_LOW,
    .keypad_row_pins[1].port = PORTC_INDEX,
    .keypad_row_pins[1].pin = GPIO_PIN1,
    .keypad_row_pins[1].direction = GPIO_OUTPUT,
    .keypad_row_pins[1].logic = GPIO_LOW,
    .keypad_row_pins[2].port = PORTC_INDEX,
    .keypad_row_pins[2].pin = GPIO_PIN2,
    .keypad_row_pins[2].direction = GPIO_OUTPUT,
    .keypad_row_pins[2].logic = GPIO_LOW,
    .keypad_row_pins[3].port = PORTC_INDEX,
    .keypad_row_pins[3].pin = GPIO_PIN3,
    .keypad_row_pins[3].direction = GPIO_OUTPUT,
    .keypad_row_pins[3].logic = GPIO_LOW,
    .keypad_column_pins[0].port = PORTC_INDEX,
    .keypad_column_pins[0].pin = GPIO_PIN4,
    .keypad_column_pins[0].direction = GPIO_INPUT,
    .keypad_column_pins[0].logic = GPIO_LOW,
    .keypad_column_pins[1].port = PORTC_INDEX,
    .keypad_column_pins[1].pin = GPIO_PIN5,
    .keypad_column_pins[1].direction = GPIO_INPUT,
    .keypad_column_pins[1].logic = GPIO_LOW,
    .keypad_column_pins[2].port = PORTC_INDEX,
    .keypad_column_pins[2].pin = GPIO_PIN6,
    .keypad_column_pins[2].direction = GPIO_INPUT,
    .keypad_column_pins[2].logic = GPIO_LOW,
    .keypad_column_pins[3].port = PORTC_INDEX,
    .keypad_column_pins[3].pin = GPIO_PIN7,
    .keypad_column_pins[3].direction = GPIO_INPUT,
    .keypad_column_pins[3].logic = GPIO_LOW,
    .keypad_column_pins[4].port = PORTD_INDEX,
    .keypad_column_pins[4].pin = GPIO_PIN0,
    .keypad_column_pins[4].direction = GPIO_INPUT,
    .keypad_column_pins[4].logic = GPIO_LOW,
    .keypad_column_pins[5].port = PORTD_INDEX,
    .keypad_column_pins[5].pin = GPIO_PIN1,
    .keypad_column_pins[5].direction = GPIO_INPUT,
    .keypad_column_pins[5].logic = GPIO_LOW,
};

chr_lcd_4bit_t lcd_1 = {
    .lcd_rs.port = PORTD_INDEX,
    .lcd_rs.pin = GPIO_PIN2,
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_en.port = PORTD_INDEX,
    .lcd_en.pin = GPIO_PIN3,
    .lcd_en.direction = GPIO_OUTPUT,
    .lcd_en.logic = GPIO_LOW,
    .lcd_data[0].port = PORTD_INDEX,
    .lcd_data[0].pin = GPIO_PIN4,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[1].port = PORTD_INDEX,
    .lcd_data[1].pin = GPIO_PIN5,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[2].port = PORTD_INDEX,
    .lcd_data[2].pin = GPIO_PIN6,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[3].port = PORTD_INDEX,
    .lcd_data[3].pin = GPIO_PIN7,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
};

void ecu_layer_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = keypad_initialize(&keypad_1);
    ret = led_initialize(&led_1);
    ret = lcd_4bit_intialize(&lcd_1);
}