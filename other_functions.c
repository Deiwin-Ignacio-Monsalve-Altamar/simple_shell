#include "holberton.h"
/**
 * print - print error
 * @n: integer
 * Return: void
 */
void print(long n)
{
	char nume[2];

	while (n / 10)
	{
		print(n / 10);
		break;
	}

	nume[0] = ((n % 10) + '0');
	nume[1] = '\0';
	write(STDERR_FILENO, nume, 1);
}
