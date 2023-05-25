#include "monty.h"

/**
 * args_check - that check argument is it's an integer
 * @s: string to be checked
 * Return: zero if failed or 1 if it's an integer
 */
int args_check(char *s)
{
int i = 0;
if (!s)
{
return (0);
}
if (*s == '-')
{
s++;
}
while (s[i])
{
if (s[i] >= '0' && s[i] <= '9')
{
i++;
}
else
{
return (0);
}
}
return (1);
}

/**
 * clean - frees doubly linked list
 * @head: doubly linked list
 * Return: Nothing
 */
void clean(stack_t *head)
{
stack_t *temp = head;

while (head)
{
head = head->next;
free(temp);
temp = head;
}
if (glob.get_file)
{
fclose(glob.get_file);
}
}

/**
 * stack_del - pop stack
 * @stack: doubly linked list
 * Return: Nothing.
 */
void stack_del(stack_t **stack)
{
stack_t *tem = *stack;
*stack = (*stack)->next;
if (*stack)
{
(*stack)->prev = NULL;
}
free(tem);
}

/**
 * top_bot - bring the top node to bottom
 * @stack: doubly linked list
 * @i: num
 * Return: Nothing
 */
void top_bot(stack_t **stack, const int i)
{
stack_t *new = NULL;
stack_t *temp = *stack;
new = malloc(sizeof(stack_t));
if (!new)
{
return;
}
new->n = i;
new->next = NULL;
if (!*stack)
{
new->prev = NULL;
*stack = new;
return;
}
while (temp->next)
{
temp = temp->next;
}
temp->next = new;
new->prev = temp;
return;
}

/**
 * tb_del - delet node from given index
 * @stack: doubly linked list
 * @i: index
 * Return: Nothing.
 */
void tb_del(stack_t **stack, int i)
{
	stack_t *temp = *stack;
	int j = 0;

	if (!stack || !*stack)
		return;
	if (i == 0)
	{
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
		return;
	}
	while (temp)
	{
		temp = temp->next;
		j++;
	}
	if (i >= j)
	{
		return;
	}
	temp = *stack;
	while (temp && temp->next)
	{
		if (i == 0)
		{
			break;
		}
		i--;
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	if (temp->next)
	{
		temp->next->prev = temp->prev;
	}
	free(temp);
}
