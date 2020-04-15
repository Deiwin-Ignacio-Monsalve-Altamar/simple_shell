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

extern char **environ;
/**
 * struct builtins - has builtins
 * @arg: builtins name
 * @builtin: Mathcing builtin fun
 *
 */

typedef struct builtins
{
	char *arg;
	void (*builtin)(char **args, char line, char **env);
} buil_t;

/* function free*/
void freerror1(char *buff);

/* function free doble pointers*/
void dobfreer(char **capt);

/*get arguments in functions*/
char **getargs(char *buff);

/* functions fail fork*/
void fail_fork(void);

/* functions copy a string */
char *_strcpy(char *dest, char *src);

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
int execute(char **buffer, char *av, char **env, int cont);

/* function  that get PATH */
char *_path(char *text, char **env);

/* string array with PATH directories */
char *env_variable(char *dir_tmp, char *text);

/* function  that concatenates strings */
char *_strcat(char *dest, char *src);

/* function  that get the value of the environment variable */
char *getenv_(const char *name, char **environ);

/* function  that print environment varibles */
void printenvi(char **text, char **environ);

/* produces output of simple_shell */
void e_exit(char **text);

int getline_aux(char *buff);

void ctrl_c(int sign);

char **getargs2(char *buff);

void print_error(char *text, char *av, int cont);

void no_intera(char *p);
#endif /*_HOLBERTON_H_ */
