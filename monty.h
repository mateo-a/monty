#ifndef MONTY_H
#define MONTY_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
#include<fcntl.h>
#include<sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct aux_s - auxiliar structure
 * @val: value
 * @file: file
 * @line_inf: line string
 * @flag_sq: flag
 * Description: auxiliar structure
 */
typedef struct aux_s
{
	char *val;
	FILE *file;
	char *line_inf;
	int flag_sq;
}  aux_t;
extern aux_t aux;
void push_opt(stack_t **, unsigned int);
void pall_opt(stack_t **, unsigned int);
void pint_opt(stack_t **, unsigned int);
void pop_opt(stack_t **, unsigned int);
void swap_opt(stack_t **, unsigned int);
void add_opt(stack_t **, unsigned int);
void nop_opt(stack_t **, unsigned int);
void sub_opt(stack_t **, unsigned int);
void div_opt(stack_t **, unsigned int);
void mul_opt(stack_t **, unsigned int);
void mod_opt(stack_t **, unsigned int);
void pchar_opt(stack_t **, unsigned int);
void pstr_opt(stack_t **, unsigned int);
void rotl_opt(stack_t **, unsigned int);
void rotr_opt(stack_t **, unsigned int);
void stack_opt(stack_t **, unsigned int);
void queue_opt(stack_t **, unsigned int);
void add_node(stack_t **, int);
void add_node_end(stack_t **, int);
int options(char *, stack_t **, unsigned int, FILE *);
void free_nodes(stack_t *);
#endif
