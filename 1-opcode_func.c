#include "monty.h"

/**
 * add - adds the top two in stack
 * @stack: doubly linked list
 * @line_number: line
 * Return: Nothing.
 */
void add(stack_t **stack, unsigned int line_number)
{
if (!*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
(*stack)->next->n += (*stack)->n;
stack_del(stack);
}
/**
 * sub - subtracts the top two in stack
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */
void sub(stack_t **stack, unsigned int line_number)
{
if (!*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
(*stack)->next->n -= (*stack)->n;
stack_del(stack);
}
/**
 * divi - divides the second top element of the stack by the top element
 * @stack: doubly linked list
 * @line_number: line
 * Return: Nothing.
 */
void divi(stack_t **stack, unsigned int line_number)
{
if (!*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
(*stack)->next->n /= (*stack)->n;
stack_del(stack);
}
/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: doubly linked list
 * @line_number: line
 * Return: Nothing.
 */
void mul(stack_t **stack, unsigned int line_number)
{
if (!*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
(*stack)->next->n *= (*stack)->n;
stack_del(stack);
}
/**
 * mod- mod of the second top element of the stack by the top element
 * @stack: doubly linked list
 * @line_number: line
 * Return: Nothing.
 */
void mod(stack_t **stack, unsigned int line_number)
{
if (!*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
(*stack)->next->n %= (*stack)->n;
stack_del(stack);
}
