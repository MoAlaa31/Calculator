/* 
 * File:   infix_to_post.h
 * Author: 2m
 *
 * Created on 29 August 2023, 21:59
 */

#ifndef INFIX_TO_POST_H
#define	INFIX_TO_POST_H

/* Section : Includes */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../../MCAL_layer/mcal_std_types.h"

#define MAXSIZE    20

struct Stack_t {
    uint32 data[MAXSIZE]; // Assuming a maximum of 100 characters
    int top;
};

/* Section : Functions Declarations */
void infixToPostfix(const char *infix, uint32 *postfix);
uint32 evaluate_Postfix(const uint32 *postfix);
#endif	/* INFIX_TO_POST_H */

