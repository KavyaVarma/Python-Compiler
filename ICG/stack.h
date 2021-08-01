#include<stdio.h>
#include<stdlib.h>
 
#define MAX 50

typedef struct stack
{
	char* stack[500];
	int top;
}stack;
 
void push(stack* the_stack, char* new_ele)
{
	the_stack->top=the_stack->top+1;
	the_stack->stack[the_stack->top]=new_ele;
}
 
void pop(stack* the_stack)
{
	the_stack->top=the_stack->top-1;
}

void stack_init(stack* the_stack)
{
	the_stack->top = -1;
}

char* top(stack* the_stack)
{
	return the_stack->stack[the_stack->top];
}