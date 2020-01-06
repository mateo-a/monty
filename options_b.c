#include "monty.h"
/**
 * add_opt - adds the top two elements of the stack
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void add_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;
	int len = 0, sum;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sum = temp->n + temp->next->n;
	temp->next->n = sum;
	*head = temp->next;
	free(temp);
}

/**
  *nop_opt- doesn’t do anything
 * @head: head of stack
 * @ln: line number
 * Return: void
 */
void nop_opt(stack_t **head, unsigned int ln)
{
	(void) ln;
	(void) head;
}

/**
  *sub_opt- subtracts the top element of the stack from the
  *			second top element of the stack
 * @head: head of stack
 * @ln: line number
 * Return: void
 */
void sub_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;
	int sub, nodes;

	temp = *head;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}

/**
 * div_opt - divides the second top element of the stack by
 *			 the top element of the stack
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void div_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;
	int len = 0, div;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
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
	div = temp->next->n / temp->n;
	temp->next->n = div;
	*head = temp->next;
	free(temp);
}

/**
 * mul_opt - multiplies the second top element of the stack with
 *			 the top element of the stack
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void mul_opt(stack_t **head, unsigned int ln)
{
	stack_t *temp;
	int len = 0, mul;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		fclose(aux.file);
		free(aux.line_inf);
		free_nodes(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	mul = temp->next->n * temp->n;
	temp->next->n = mul;
	*head = temp->next;
	free(temp);
}
