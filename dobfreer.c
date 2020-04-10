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
 * addpath - add new argument to PAHT copy
 * @text: data entered by the user
 * @env: pointer to environment variables
 * Return: string with arguments to the execute function
 */
char **addpath(char **text, char **env)
{
	char *token, *str, *aux, *tmp, **npath;
	int x = 0, y = 0, z, size;

	size = counter(env, text);
	npath = malloc(sizeof(char *) * size + 1);
	aux = "PATH";
	while (env[x])
	{
		tmp = _strdup(env[x]);
		token = strtok(tmp, "=");
		if (_strcmp(aux, token) == 0)
		{
			token = strtok(NULL, "=");
			str = _strdup(token);
			token = strtok(str, ":");
			while (token != NULL)
			{
				npath[y] =  token;
				y++;
				token = strtok(NULL, ":");
			}
			for (z = 0; text[z] != NULL; z++)
			{
				npath[y] = text[z];
				y++;
			}
			npath[y] = NULL;
			free(tmp);
			free(str);
			return (npath);
		}
		x++;
		free(tmp);
	}
	return (NULL);
}

/**
 * counter - calculate size for new string
 * @text: data entered by the user
 * @env: pointer to environment variables
 * Return: zise new stringg
 */
int counter(char **env, char **text)
{
	int ntoken, numtext;

	ntoken = contokens(*env);
	for (numtext = 0; text[numtext] != NULL; numtext++)
	{
		ntoken += 1;
	}
	return (ntoken);
}
