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
            break;
        token = strtok(NULL, ":");
        free(path);
    }
    return (path);
}
/**
 * main - execve example
 *
 * Return: Always 0.
 */
char *_path(char *text, char **env)
{
   int i = 0;
   char *var = "PATH", *path, *token, *env_copy, *dir_tmp, *npath;

   while (env[i]) 
	{

	   env_copy = _strdup(env[i]);
	   token = strtok(env_copy, "=");
	   free(env_copy);
	   if (_strcmp(token, var) == 0) {
		   token = strtok(NULL, "=");
		   dir_tmp = _strdup(token);
		   path = env_variable(dir_tmp, text);
		    npath = _strdup(path);
		    free(path);
		   free(dir_tmp);
		   return (npath);
	   }
	   i++;
        }
    return (NULL);
}
