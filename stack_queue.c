#include "monty.h"
/**
 * stack_opt - sets the format of the data to a stack (LIFO). This is
 *				the default behavior of the program
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void stack_opt(stack_t **head, unsigned int ln)
{
	(void)head;
	(void)ln;
	aux.flag_sq = 0;
}

/**
 * queue_opt - sets the format of the data to a queue (FIFO)
 * @head: head of stack
 * @ln: line number
 * Return: void
*/
void queue_opt(stack_t **head, unsigned int ln)
{
	(void)head;
	(void)ln;
	aux.flag_sq = 1;
}
