#include "monty.h"
aux_t aux;

/**
* main - entry point
* @argc: argument count
* @argv: argument vector
* Return: 0
*/
int main(int argc, char **argv)
{
	char *line_inf;
	FILE *file;
	size_t size = 0;
	ssize_t fline = 1;
	stack_t *stack = NULL;
	unsigned int ln = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	aux.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fline > 0)
	{
		line_inf = NULL;
		fline = getline(&line_inf, &size, file);
		aux.line_inf = line_inf;
		ln++;
		if (fline > 0)
		{
			options(line_inf, &stack, ln, file);
		}
		free(line_inf);
	}
	free_nodes(stack);
	fclose(file);
return (0);
}

/**
* options - select options to run
* @stack: stack
* @ln: line number
* @file: file
* @line_inf: line string
* Return: void
*/
int options(char *line_inf, stack_t **stack, unsigned int ln, FILE *file)
{
	unsigned int i = 0;
	char *op;

	instruction_t opst[] = {
				{"push", push_opt}, {"pall", pall_opt}, {"pint", pint_opt},
				{"pop", pop_opt}, {"swap", swap_opt}, {"add", add_opt},
				{"nop", nop_opt}, {"sub", sub_opt}, {"div", div_opt},
				{"mul", mul_opt}, {"mod", mod_opt}, {"pchar", pchar_opt},
				{"pstr", pstr_opt}, {"rotl", rotl_opt}, {"rotr", rotr_opt},
				{"queue", queue_opt}, {"stack", stack_opt}, {NULL, NULL}
				};
	op = strtok(line_inf, " \n\t");
	if (op && op[0] == '#')
		return (0);
	aux.val = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, ln);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, op);
		fclose(file);
		free(line_inf);
		free_nodes(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
* free_nodes - free nodes
* @head: head of stack
*/
void free_nodes(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * add_node - adds a new node at the beginning
 * @head: head of stack
 * @n: value
 * Return: void
*/
void add_node(stack_t **head, int n)
{

	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}


/**
 * add_node_end - adds a new node at the end
 * @head: head of stack
 * @n: value
 * Return: void
*/
void add_node_end(stack_t **head, int n)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}
