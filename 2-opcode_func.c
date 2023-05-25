#include "monty.h"

/**
 * nop - doesn’t do anything
 * @stack: doubly linked list
 * @line_number: line
 *
 * Return: Nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
{
(void)stack;
(void)line_number;
}
}

/**
 * pchar - prints character
 * @stack: doubly linked list
 * @line_number: the line
 *
 * Return: Nothing.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
if (!*stack)
{
fprintf(stderr, "L%u: can't pchar, stack is empty\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
if ((*stack)->n < 0 || (*stack)->n > 127)
{
fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
clean(glob.stk);
exit(EXIT_FAILURE);
}
printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: doubly linked list
 * @line_number: the line
 * Retutn: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;
(void)line_number;
while (temp && (temp->n > 0 && temp->n <= 127))
{
printf("%c", temp->n);
temp = temp->next;
}
printf("\n");
}

/**
 * rotl - rotates stack to the top
 * @stack: doubly linked list
 * @line_number: the line
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
(void)line_number;
if (*stack && (*stack)->next)
{
top_bot(stack, (*stack)->n);
stack_del(stack);
}
}

/**
 * rotr - rotates stack to the bottom
 * @stack: doubly linked list
 * @line_number: the number line
 */
void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *new = NULL;
stack_t *temp = *stack;
int num;
int i = 0;
(void)line_number;
if (*stack && (*stack)->next)
{
while (temp)
{
if (!temp->next)
{
num = temp->n;
}
i++;
temp = temp->next;
}
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
tb_del(stack, i);
}
