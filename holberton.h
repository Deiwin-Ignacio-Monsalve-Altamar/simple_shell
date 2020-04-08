#ifdef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void freerror1(char *buff);
void dobfreer(**capt);
char **getargs(char *buff, ssize_t num_read);

#endif
