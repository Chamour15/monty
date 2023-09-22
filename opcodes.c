#include "monty.h"

/**
* opcodes - selects the correct opcode to perform
* @opc: opcode passed by opened file.
*
* Return: pointer to the function that executes the opcode.
*/
void (*opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	int i;

	for (i = 0; opcodes[i].opcode; i++)
	{
		if (_strcmp(opcodes[i].opcode, opc) == 0)
		{
			break;
		}
	}

	return (opcodes[i].f);
}

