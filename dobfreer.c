#include "holberton.h"
/**
 * dobfreer - free double pointer
 * @capt: double pointer to free
 * Return: void
 */

void dobfreer(char **capt)
{
	int count = 0;

	while (capt[count] != NULL)
	{
		free(capt[count]);
		count++;
	}
	free(capt);
}
/**
 * *_strcat - print character
 * @src: pointr character
 * @dest : poinr character
 * Return: *char
 */
char *_strcat(char *dest, char *src)
{
    int i, j;

    i = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    dest[i++] = '/';
    j = 0;
    while ((dest[i++] = src[j++]) != '\0')
    {
    }
    dest[i++] = '\0';
    return (dest);
}


/**
 * main - execve example
 *
 * Return: Always 0.
 */
char *env_variable(char *dir_tmp, char *text)
{

    char *path, *token;
    struct stat stark;

    token = strtok(dir_tmp, ":");
    while (token)
    {
        path = malloc(_strlen(token) + 1 + _strlen(text) + 1);
        _strcpy(path, token);
        _strcat(path, text);
        if (stat(path, &stark) == 0 && stark.st_mode & S_IXUSR)
            return (path);
        token = strtok(NULL, ":");
        free(path);
    }
    return (NULL);
}
/**
 * main - execve example
 *
 * Return: Always 0.
 */
char *_path(char *text, char **env)
{
   char *path, *dir_tmp;

    dir_tmp = getenv_("PATH", env);
    path = env_variable(dir_tmp, text);
    free(dir_tmp);
    return (path);
}
/**
 * main - execve example
 *
 * Return: Always 0.
 * 
 */

char *getenv_(const char *name, char **environ)
{
    char *token;
    int x = 0;
    char *tmp, *str;

    while (environ[x])
    {
        tmp = strdup(environ[x]);
        token = strtok(tmp, "=");
        if (strcmp(name, token) == 0)
        {
            token = strtok(NULL, "=");
            str = strdup(token);
            free(tmp);
            return (str);
        }
        free(tmp);
        x++;
    }
    return (NULL);
}