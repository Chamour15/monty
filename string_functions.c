#include "monty.h"

/**
 * _strcmp - function that compares two strings.
 * @str1: first string.
 * @str2: second string.
 *
 * Return: -1 if str1 is less than str2, 0 if s1 and s2 are equals,
 * 1 if str1 is greater than str2.
 */
int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] < str2[i])
		{
			return (-1);
		}
		else if (str1[i] > str2[i])
		{
			return (1);
		}
		i++;
	}

	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return (0);
	}
	else if (str1[i] == '\0')
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}

/**
 * _strtok - function that splits a string into tokens based
 * on the specified delimiters.
 * @str: string to cut in parts
 * @delims: delimiters
 *
 * Return: splited string.
 */
char *_strtok(char *str, char *delims)
{
	static char *tmp_str;
	int i = 0, j = 0;

	if (!str)
	{
		str = tmp_str;
	}

	while (str[i] != '\0')
	{
		if (c_str(delims, str[i]) == 0 && str[i + 1] == '\0')
		{
			tmp_str = str + i + 1;
			*tmp_str = '\0';
			str = str + j;
			return (str);
		}
		else if (c_str(delims, str[i]) == 0 && c_str(delims, str[i + 1]) == 0)
		{
			i++;
		}
		else if (c_str(delims, str[i]) == 0 && c_str(delims, str[i + 1]) == 1)
		{
			tmp_str = str + i + 1;
			*tmp_str = '\0';
			tmp_str++;
			str = str + j;
			return (str);
		}
		else if (c_str(delims, str[i]) == 1)
		{
			j++;
			i++;
		}
	}

	return (NULL);
}

/**
 * c_str - function that searches for a character in a string.
 * @str: string to search in.
 * @c: character to search for.
 *
 * Return: true if the character is found or false if not found
 */
int c_str(const char *str, char c)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			return (1);
		}
	}

	return (0);
}

/**
 * input - function that checks if the file exists and
 * if the file can be opened or not.
 * @argumentsn: argument count
 * @arguments: argument vector
 *
 * Return: file to open.
 */
FILE *input(int argumentsn, char *arguments[])
{
	FILE *file;

	if (argumentsn == 1 || argumentsn > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(arguments[1], "r");

	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", arguments[1]);
		exit(EXIT_FAILURE);
	}

	return (file);
}

