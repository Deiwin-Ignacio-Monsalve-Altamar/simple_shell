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

#endif /*_HOLBERTON_H_ */
