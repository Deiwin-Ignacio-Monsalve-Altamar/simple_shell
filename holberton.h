#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#define DELIMI " \n\t\a"

/* function free*/
void freerror1(char *buff);

/* function free doble pointers*/
void dobfreer(char **capt);

/*get arguments in functions*/
char **getargs(char *buff);

/* functions fail fork*/
void fail_fork(void);

/* functions copy a string */
char *_strncpy(char *dest, char *src, int n);

/* functions count a string */
int _strlen(char *s);

/* functions duplicates a string */
char *_strdup(char *str);

/* functions count the tokens */
int contokens(char *buff);

/* function that compares 2 strings */
int _strcmp(char *s1, char *s2);

/* function  that print the prompt */
void prompt(void);

/* function  that fetches data from the user */
char *_getline(void);

/* function  that fork and execute the user input */
int execute(char **buffer, char *av, char *line, char **env);

void path(char **text, char *buffer, char **env);

char **env_variable(char *text, char **env);

char *getenv_(const char *name, char *str);

char *_strcpytext(char *dest, char *str, char *text, int len1, int len2);
char **addpath(char **text, char **env);

int counter(char **env, char **text);

#endif /*_HOLBERTON_H_ */
