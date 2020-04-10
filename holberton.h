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
void prompt(void);
char *_getline(void);
int execute(char **buffer, char *av);
#endif /*_HOLBERTON_H_ */
