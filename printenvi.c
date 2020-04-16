#include "holberton.h"

/**
 * printenvi - print environment variables
 * @env: pointer to string array with environment varibles
 * @text: pointer arrays for free
 * Return: void
 */
int printenvi(char **text, char **env)
{
	char *envi = "env";

	if ((_strcmp(envi, text[0])) == 0)
	{
		unsigned int cont, size;

		for (cont = 0; env[cont] != NULL; cont++)
		{
			size = _strlen(env[cont]);
			write(STDOUT_FILENO, env[cont], size);
			write(STDOUT_FILENO, "\n", 1);
		}
		return (1);
	}
	return (0);
}
/**
 * e_exit - produces output of simple_shell
 * @text: pointer arrays for free
 * Return: void
 */
void e_exit(char **text)
{
	char *exit_com = "exit";

	if ((_strcmp(exit_com, text[0])) == 0)
	{
		dobfreer(text);
		exit(0);
	}
}

/**
 * fork_- produces output of simple_shell
 * @program: pointers array
 * @buffer: pointer arrays for free
 * @env: pointers array
 * @av: pointer arrays for free
 * Return: integer
 */
int fork_(char *program, char **buffer, char **env, char *av)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(program, buffer, env) == -1)
			perror(av);
	}
	else
		waitpid(pid, &status, 0);
	free(program);
	return (status);
}
/**
 * ctrl_c - produces output of simple_shell
 * @sign: pointer arrays for free
 * Return: void
 */
void ctrl_c(int sign)
{
	sign = sign * 1;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "Holber->$ ", 10);
}
/**
 * print_e - produces output of simple_shell
 * @av: pointer arrays for free
 * @buffer: pointer arrays for free
 * @cont: integer point
 * Return: void
 */
int print_e(char *av, char *buffer, int cont)
{

	write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, ": ", 2);
	print(cont);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buffer, _strlen(buffer));
	write(STDERR_FILENO, ": not found\n", 12);
	return (127);
}