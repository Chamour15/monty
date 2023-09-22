#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define BUFF_SIZE 256
#define BUFFER 128
#define UNUSED(x) ((void)(x))

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct global_struct
{
        char *argm;
        char *buff;
        int lifo;
        unsigned int cnt;
        FILE *file;
        stack_t *head;
} global_var_t;

extern global_var_t glob;

/* opcodes.c */
void (*opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/* main.c */
void free_glbvar(void);

/* string_functions.c */
int _strcmp(const char *str1, const char *str2);
char *_strtok(char *str, char *delims);
int c_str(const char *str, char c);
FILE *input(int argumentsn, char *arguments[]);

/* linked_list.c */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* opcodes_functions1.c */
void _push(stack_t **head, unsigned int cmdline_n);
void _pall(stack_t **head, unsigned int cmdline_n);
void _pint(stack_t **head, unsigned int cmdline_n);
void _pop(stack_t **head, unsigned int cmdline_n);
void _swap(stack_t **head, unsigned int cmdline_n);

/* opcodes_functions2.c */
void _add(stack_t **head, unsigned int cmdline_n);
void _nop(stack_t **head, unsigned int cmdline_n);
void _sub(stack_t **head, unsigned int cmdline_n);
void _div(stack_t **head, unsigned int cmdline_n);
void _mul(stack_t **head, unsigned int cmdline_n);

/* opcodes_functions3.c */
void _mod(stack_t **head, unsigned int cmdline_n);
void _pchar(stack_t **head, unsigned int cmdline_n);
void _pstr(stack_t **head, unsigned int cmdline_n);
void _rotl(stack_t **head, unsigned int cmdline_n);
void _rotr(stack_t **head, unsigned int cmdline_n);

/* opcodes_functions4.c */
void _stack(stack_t **head, unsigned int cmdline_n);
void _queue(stack_t **head, unsigned int cmdline_n);

#endif

