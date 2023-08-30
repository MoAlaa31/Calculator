/* 
 * File:   Application.c
 * Author: Mohmed.Alaa
 *
 * Created on 10 April 2023, 02:23
 */

#include "Application.h"


uint8 val = ZERO_INIT;
char infix[100];
uint32 postfix[MAXSIZE];
uint32 result;
uint8 arr[11];
uint8 counter = 0, flag = 0, pos = 1, sup_pos = 1, res_counter = 0, equal_flag = 0;
uint8 op[2] = "\0"; 
uint8 operators[8] = {'/', 'E', '*', '-', '+', '=', 'D', 'C'};
uint32 num_1 = 0;
int main() {
    Std_ReturnType ret = E_NOT_OK;
    application_intialize();
       
    while(1){
        ret = keypad_get_value(&keypad_1, &val);
        if((val == 'A')&&(counter == 0)){
            led_turn_on(&led_1);
            val = '#';
            //The name of the calculator
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "CASIO");
            __delay_ms(500);
            ret =  lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
            counter++;
        }
        else if((val == 'A')&&(counter == 1)){
            counter = 0;
            led_turn_off(&led_1);
            ret =  lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
            memset(infix, '\0', 100);
            memset(postfix, '\0', 100);
            res_counter = 0;
            num_1 = 0;
            pos = 1;
            equal_flag = 0;
        }
        else{/*Nothing*/}
        
        
        for(int i = 0; i<7; i++){
            if(val == operators[i]){
                flag = 1;
                break;
            }
            else{/*Nothing*/}
        }
        if((flag != 1)&&(counter == 1)&&(val != '#')){
            if(equal_flag == 1){
                ret =  lcd_4bit_send_command(&lcd_1, _LCD_CLEAR);
                memset(infix, '\0', 100);
                memset(postfix, '\0', 100);
                res_counter = 0;
                num_1 = 0;
                pos = 1;
                equal_flag = 0;
            }
            infix[res_counter] = val;
            ret = lcd_4bit_send_char_data_pos(&lcd_1, 1, pos, val);
            res_counter++;
            pos++;
        }
        else if((flag == 1)&&(counter == 1)){
            switch (val){
                case ('/'):
                    op[0] = '*';
                    infix[res_counter] = '*';
                    res_counter++;
                    break;
                case ('E'):
                    op[0] = '/';
                    infix[res_counter] = '/';
                    res_counter++;
                    break;
                case ('*'):
                    op[0] = '-';
                    infix[res_counter] = '-';
                    res_counter++;
                    break;
                case ('+'):
                    op[0] = '+';
                    infix[res_counter] = '+';
                    res_counter++;
                    break;
                case ('='):
                    op[0] = '=';
                    equal_flag = 1;
                    infix[res_counter] = '\0';
                    break;
                default:;
            }
            ret = lcd_4bit_send_char_data_pos(&lcd_1, 1, pos, op[0]);
            if(op[0] == '='){
                infixToPostfix(infix, postfix);
                result = evaluate_Postfix(postfix);
                ret = convert_uint32_to_string(result, arr);
                ret = lcd_4bit_send_string_pos(&lcd_1, 4, 20-strlen(arr), arr);
                memset(infix, '\0', 100);
                memset(postfix, '\0', MAXSIZE);
            }
            pos++;
            num_1 = 0;
        }
        
        flag = 0;
        val = '#';
    }
    return (EXIT_SUCCESS);
}

void application_intialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_layer_intialize();
}
