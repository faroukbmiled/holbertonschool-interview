#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - entry point
 * @argc: number of command-line arguments
 * @argv: array of passed args
 *
 * Return: 0 on success, 1 otherwise
 */
int main(int argc, char **argv)
{
	char *num1, *num2;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit_string(num1) || !is_digit_string(num2))
	{
		printf("Error\n");
		return (98);
	}

	multiply_strings(num1, num2);

	return (0);
}

/**
 * is_digit_string - Check if a string only contains digits
 * @str: The string to check
 *
 * Return: 1 if the string only contains digits, if not 0
 */
int is_digit_string(char *str)
{
	if (str == NULL)
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}

/**
 * string_length - calculate string length
 * @str: string
 *
 * Return: string length
 */
int string_length(char *str)
{
	int length = 0;

	while (*str)
	{
		length++;
		str++;
	}

	return (length);
}

/**
 * multiply_strings - multiply two numbers represented as strings
 * @num1: first atg
 * @num2: second arg
 */
void multiply_strings(char *num1, char *num2)
{
	int len1 = string_length(num1);
	int len2 = string_length(num2);
	int len_result = len1 + len2;
	int *result;
	int i, j, carry, digit, prod;

	result = malloc(sizeof(int) * len_result);
	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < len_result; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1];
			digit = prod % 10;
			carry = prod / 10;
			result[i + j + 1] = digit;
		}
		result[i] += carry;
	}

	if (result[0] == 0)
		i = 1;
	else
		i = 0;

	for (; i < len_result; i++)
		_putchar(result[i] + '0');

	_putchar('\n');

	free(result);
}
