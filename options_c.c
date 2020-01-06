#include "monty.h"
/**
 * mod_opt - computes the rest of the division of the second top element of
 *			 the stack by the top element of the stack
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void mod_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;
	int len = 0, mod;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	mod = temp->next->n % temp->n;
	temp->next->n = mod;
	*head = temp->next;
	free(temp);
}

/**
 * pchar_opt - prints the char at the top of the stack, followed by a new line
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void pchar_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;

	temp = *head;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

/**
 * pstr_opt - prints the string starting at the top of the stack, followed
 *			  by a new line
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void pstr_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;
	(void)ln;

	temp = *head;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
  *rotl_opt- rotates the stack to the top
 * @head: head of stack
 * @ln: line number
 * Return: void
 */
void rotl_opt(stack_t **head,  __attribute__((unused)) unsigned int ln)
{
	stack_t *temp = *head, *temp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp2 = (*head)->next;
	temp2->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = temp2;
}

/**
  *rotr_opt- rotates the stack to the bottom
 * @head: head of stack
 * @ln: line number
 * Return: void
 */
void rotr_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;
	(void) ln;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
