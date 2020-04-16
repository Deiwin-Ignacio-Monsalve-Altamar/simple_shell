#include "holberton.h"
/**
 * _strtok - breaks string str into a series of tokens using the delimiter del
 * @s: string to modified and broken into smaller strings (tokens).
 * @del: string containing the delimiters.
 * Return: pointer to the first token found in the string. A null pointer is 
 * returned if there are no tokens left to retrieve.
 */
char *_strtok(char *s, const char *del)
{
	char *token = NULL;
	static char *ptr;

	 if (s == NULL)
	{
		s = ptr;
		if (s == NULL)
			return (NULL);
	}
	s += _strspn(s, del);
	if (*s == '\0')
	{
		ptr = NULL;
		return (NULL);
	}
	token = s;
	s = _strpbrk(token, del);
	if (s != NULL)
	{
		*s = '\0';
		ptr = s + 1;
	}
	else
		ptr = NULL;
	return (token);
	
}

/**
 * _strspn - Write a function that locates a character in a string
 * @s: The Target string in which search has to be made.
 * @accept: Argument string containing characters to match in target string.
 * Return: the number of characters before the 1st occurrence
 * of character present in both the string.
 */
unsigned int _strspn(char *s, const char *accept)
{
	unsigned int x, y, count;

	count = 0;

	for (x = 0; s[x] != '\0'; x++)
	{
		for (y = 0; s[y] != '\0'; y++)
		{
			if (s[x] == accept[y])
			{
				count++;
				break;
			}
		}
		if (s[x] != accept[y])
		{
			break;
		}
	}
	return (count);
}


/**
 * _strpbrk - function that locates a character in a string
 * @s: string to be scanned.
 * @accept: containing the characters to match.
 * Return: pointer to the character in s that matches one of the characters in
 * accept, or NULL if no such character is found.
 */
char *_strpbrk(char *s, const char *accept)
{
	int y;

	while (*s)
	{
		for (y = 0; accept[y]; y++)
		{
			if (*s == accept[y])
			{
				return (s);
			}
		}
		s++;
	}
	return ('\0');
}

