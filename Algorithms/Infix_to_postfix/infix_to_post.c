#include "infix_to_post.h"


// Stack structure for holding operators during parsing
static uint32 operator_type(char input);
static int Are_equal(float num_1, float num_2);
static uint32 doMath(uint32 op, uint32 op1, uint32 op2);
static int Is_digit(float op);
static int check_digit (char c);
static void initialize_t(struct Stack_t *stack);
static void push_t(struct Stack_t *stack, uint32 c);
static uint32 pop_t(struct Stack_t *stack);
static int precedence(char op);


uint32 operator_type(char input) {
    if (input == '+'){
        return 4294967295;
    }
    else if (input == '*'){
        return 4294967294;
    }
    else if (input == '/'){
        return 4294967293;
    }
    else if (input == '-'){
        return 4294967292;
    }
    return 0;
}

int Are_equal(float num_1, float num_2){
    if (fabs(num_1 - num_2) < .0000001 * pow(10, -38)) {
            //Equal
        return 1;
    }
    else {
            //Not Equal
        return 0;
    }
}

uint32 doMath(uint32 op, uint32 op1, uint32 op2){
    if (op== 4294967294)
        return (op1*op2);
    else if (op== 4294967293)
        return (op1/op2);
    else if (op== 4294967295)
        return (op1+op2);
    else if (op== 4294967292)
        return (op1-op2);
    return 0;
}


int Is_digit(float op){
    if ((op== 4294967294)||(op== 4294967292)||(op== 4294967293)||(op== 4294967295)||(op== 4294967291)){
        return 0;
    }
    else{
        return 1;
    }
}
// Initialize the stack


void initialize_t(struct Stack_t *stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push_t(struct Stack_t *stack, uint32 c) {
    //printf("%f\n", c);
    stack->data[++stack->top] = c;
}

// Pop an element from the stack
uint32 pop_t(struct Stack_t *stack) {
    return stack->data[stack->top--];
}

int check_digit (char c) {
	if ((c>='0') && (c<='9')) return 1;
	return 0;
}

// Get the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0; // Assuming all other characters are operands
}

// Convert infix expression to postfix expression
void infixToPostfix(const char *infix, uint32 *postfix) {
    struct Stack_t operatorStack;
    initialize_t(&operatorStack);
    uint32 num_1 = 0;
    int i = 0;
    int j = 0;
    while (infix[i] != '\0') {
        char current = infix[i];

        if (current == ' ') {
            i++;
            continue; // Skip spaces
        }

        if (check_digit(current) || current == '.') {
            while (check_digit(infix[i]) || infix[i] == '.') {
                num_1 = num_1 * 10 + (infix[i] - '0');
                i++;
            }
            //printf("%f\n", num_1);
            postfix[j++] = num_1;
            num_1 = 0.0;
            postfix[j++] = 4294967291; // Space as a delimiter between operands

        } else { // Operator
            while (operatorStack.top != -1 && precedence(current) <= precedence(operatorStack.data[operatorStack.top])) {
                postfix[j++] = pop_t(&operatorStack);
            }
            push_t(&operatorStack, operator_type(current));
            //printf("%0.38f\n", operator_type(current));
            i++;
        }
    }

    while (operatorStack.top != -1) {
        postfix[j] = pop_t(&operatorStack);
        //printf("%0.38f\n", postfix[j]);
        j++;
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}

// Evaluate postfix expression

uint32 evaluate_Postfix(const uint32 *postfix){
    struct Stack_t operandStack;
    initialize_t(&operandStack);
    uint32 operand1 = 0, operand2 = 0, result = 0;
    int i = 0;
    while (postfix[i] != '\0') {
        uint32 current = postfix[i];

        if (Is_digit(current)){
            //printf("hello_1\n");
            push_t(&operandStack, postfix[i]);
            i++;
        }
        else if (current== 4294967291) {
            //printf("hello_2\n");
            i++;
        }
        else{
            //printf("hello_3\n");
            operand2 = pop_t(&operandStack);
            //printf("%f\n", operand2);
            operand1 = pop_t(&operandStack);
            //printf("%f\n", operand1);
            result = doMath(current, operand1, operand2);
            //printf("Result: %.2f\n", result);
            push_t(&operandStack, result);
            i++;
        }
        //i++;
    }
    return pop_t(&operandStack);
}
