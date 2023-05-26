#include "monty.h"
/**
 * push - adds data to the top of the stack
 * @stack: doubly linkedlist
 * @line_number: line number in the file
 * Return: Nothing.
 */

void push(stack_t **stack, unsigned int line_number)
{
stack_t *new = NULL;
int num;
char *s = strtok(NULL, "\n");
if (args_check(s) == 0)
{
fprintf(stderr, "L%u: usage push integer \n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
num = atoi(s);
if (glob.s_or_q == 'q')
{
top_bot(stack, num);
}
else
{
new = malloc(sizeof(stack_t));
if (!new)
{
fprintf(stderr, "Error: malloc failed\n");
clean(glob.stk);
exit(EXIT_FAILURE);
}
new->n = num;
new->prev = NULL;
new->next = *stack;
if (*stack)
{
(*stack)->prev = new;
}
*stack = new;
}
}
/**
 * pall - prints all the values on the stack
 * @stack: doubly linked list
 * @line_number: line number in the file
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;
(void)line_number;
while (temp)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
/**
 * pint - prints the value at the top of the stack
 * @stack: doubly linked list
 * @line_number: line number in the file
 * Return: Nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (!*stack)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: doubly linkedlist
 * @line_number: line number in the file
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
if (!*stack)
{
fprintf(stderr, "L%u: Can't pop from an empty stack \n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
stack_del(stack);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: doubly linkedlist
 * @line_number: line number in the file
 * Return: Nothing.
 */

void swap(stack_t **stack, unsigned int line_number)
{
int temp;
if ((!*stack) || !(*stack)->next)
{
fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
temp = (*stack)->n;
(*stack)->n = (*stack)->next->n;
(*stack)->next->n = temp;
}
