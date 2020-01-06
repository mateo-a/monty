#include "monty.h"
/**
 * push_opt - pushes an element to the stack
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void push_opt(stack_t **head, unsigned int ln)
{
	int node, i = 0;

	if (aux.val)
	{
		if (aux.val[0] == '-')
			i++;
		for (; aux.val[i] != '\0'; i++)
		{
			if (isdigit(aux.val[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln);
				fclose(aux.file);
				free(aux.line_inf);
				free_nodes(*head);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	node = atoi(aux.val);
	if (aux.flag_sq == 0)
		add_node(head, node);
	else
		add_node_end(head, node);
}

/**
 * pall_opt - prints all the values on the stack, starting from the
 *			  top of the stack
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void pall_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;
	(void)ln;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint_opt - prints the value at the top of the stack, followed by a new line
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void pint_opt(stack_t **head, unsigned int ln)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop_opt - removes the top element of the stack
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void pop_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}

/**
 * swap_opt - swaps the top two elements of the stack
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void swap_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;
	int len = 0, swap;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	swap = temp->n;
	temp->n = temp->next->n;
	temp->next->n = swap;
}
