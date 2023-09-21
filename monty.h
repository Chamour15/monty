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

/* string_functions.c */
int _strcmp(const char *str1, const char *str2);
char *_strtok(char *str, char *delims);
int c_str(const char *str, char c);
FILE *input(int argumentsn, char *arguments[]);

/* opcodes_functions1.c */
void _push(stack_t **head, unsigned int cmdline_n);
void _pall(stack_t **head, unsigned int cmdline_n);

#endif

