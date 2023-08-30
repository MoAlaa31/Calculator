/* 
 * File:   hal_timr0.c
 * Author: 2m
 *
 * Created on 16 July 2023, 11:11
 */

#include "hal_timr0.h"

#if INTERRUPT_FEATURE_ENABLE == TIMER0_INTERRUPT_FEATURE_ENABLE
    static void (*TMR0_InterruptHandler) (void) = NULL;
#endif  

static inline void Timer0_Prescaler_Config(const timer0_t *_timer);

Std_ReturnType Timer0_Init(const timer0_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{
        TIMER0_MODULE_DISABLE();
        Timer0_Prescaler_Config(_timer);
        #if INTERRUPT_FEATURE_ENABLE == TIMER0_INTERRUPT_FEATURE_ENABLE 
        INTERRUPT_GlobalInterruptEnable();
        INTERRUPT_PeripheralInterruptEnable();
        TIMER0_InterruptEnable();
        TIMER0_InterruptFlagClear();
        TMR0_InterruptHandler = _timer->TMR0_InterruptHandler;
        #endif
        TIMER0_MODULE_ENABLE();
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType Timer0_DeInit(const timer0_t *_timer){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{
        TIMER0_MODULE_DISABLE();
        #if INTERRUPT_FEATURE_ENABLE == TIMER0_INTERRUPT_FEATURE_ENABLE 
        TIMER0_InterruptEnable();
        #endif
        ret = E_OK;
    }
    return ret;
}

Std_ReturnType Timer0_Write_Value(const timer0_t *_timer, uint16_t _value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{

        ret = E_OK;
    }
    return ret;
}

Std_ReturnType Timer0_Read_Value(const timer0_t *_timer, uint16_t *_value){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == _timer){
        ret = E_NOT_OK;
    }
    else{

        ret = E_OK;
    }
    return ret;
}

#if INTERRUPT_FEATURE_ENABLE == TIMER0_INTERRUPT_FEATURE_ENABLE

void TMR0_ISR(void){
    TIMER0_InterruptFlagClear();
    if(TMR0_InterruptHandler){
        TMR0_InterruptHandler();
    }
}

#endif

static inline void Timer0_Prescaler_Config(const timer0_t *_timer){
    if(TIMER0_PRESCALER_ENABLE_CFG == _timer->prescaler_enable){
        TIMER0_PRESCALER_ENABLE();
        T0CONbits.T0PS = _timer->prescaler_value;
    }
    else if(TIMER0_PRESCALER_DISABLE_CFG == _timer->prescaler_enable){
        TIMER0_PRESCALER_DISABLE();
    }
    else{
        /* Nothing*/
    }
}