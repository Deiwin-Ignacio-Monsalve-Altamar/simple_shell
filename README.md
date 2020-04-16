# 0x16. C - Simple Shell

## Description

Simple Shell is an end of semester project for students at Holberton where we explore, understand and build a working functional simple shell program.


## Environment

Simple Shell was built and tested in the Ubuntu 14.04 LTS via Vagrant in VirtualBox and compiled with GCC version 4.8.4

## Instructions

-   Compiling the program: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

-   Interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
-   Non-interactie mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Example
```
usuario@usuario-Latitude-E5440:~/simple_shell$ gcc -Wextra -Werror -Wall -pedantic *.c -g -o hsh
usuario@usuario-Latitude-E5440:~/simple_shell$ ./hsh
Holber->$ pwd
/home/usuario/simple_shell
Holber->$ ls -l
total 120
-rw-rw-r-- 1 usuario usuario   414 abr 13 18:50 AUTHORS
-rw-rw-r-- 1 usuario usuario  2050 abr 16 10:32 dobfreer.c
-rw-rw-r-- 1 usuario usuario  1838 abr 16 10:16 helper_f2.c
-rw-rw-r-- 1 usuario usuario  2152 abr 16 10:17 helper_fuctions.c
-rw-rw-r-- 1 usuario usuario  2021 abr 16 10:16 holberton.h
-rwxrwxr-x 1 usuario usuario 34528 abr 16 10:32 hs
-rwxr-xr-x 1 usuario usuario 34528 abr 16 10:35 hsh
-rw-rw-r-- 1 usuario usuario   717 abr 13 18:50 man_1_simple_shell
-rw-rw-r-- 1 usuario usuario   251 abr 15 21:37 other_functions.c
-rw-rw-r-- 1 usuario usuario  1835 abr 16 00:12 printenvi.c
-rw-rw-r-- 1 usuario usuario   365 abr 12 14:24 README.md
-rw-rw-r-- 1 usuario usuario   680 abr 15 22:29 simple_shell.c
-rw-rw-r-- 1 usuario usuario  1784 abr 16 10:16 _strtok.c
-rw-rw-r-- 1 usuario usuario    18 abr 14 10:19 texto
Holber->$ /bin/ls
AUTHORS     helper_f2.c        holberton.h  hsh			other_functions.c  README.md	   _strtok.c
dobfreer.c  helper_fuctions.c  hs	    man_1_simple_shell	printenvi.c	   simple_shell.c  texto
Holber->$ ls .l
ls: no se puede acceder a '.l': No existe el archivo o el directorio
Holber->$ ltewe
./hsh: 5: ltewe: not found
Holber->$ exit
usuario@usuario-Latitude-E5440:~/simple_shell$ 
```

## Respository Contenst

Simple Shell Files:

| File | Description
| ------------- |:-------------:|
| hoberton.h | Header file that contains all the functions and standard C library header file
| simple_shell.c | Contains the int main(int argc, char **argv, char **env)
| printenvi.c | It contains the functions: ***printenvi, e_exit, fork.***
| other_functions.c | Contains functions of help : ***print number***
| helper_functions.c |  Contains functions that handle all child proccess functionality: *** _getargs, _strlen, _strcpy, _putchar
| helper_f2.c | It contains other help functions such as: ***_strcmp, _prompt, _getline***
| dobfreer.c | Contains function that frees memory: ***dobfreer*** and functions that handle environment/path
| _strtok.c | Contains function that store commands in double pointer: ***_strtok, _strspn***
| man_1_simple_shell | man page simple_shell

 ## Requirements project

-   Allowed editors: vi, vim, emacs
-   All your files will be compiled on Ubuntu 14.04 LTS
-   Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
-   All your files should end with a new line
-   A README.md file, at the root of the folder of the project is mandatory
-   Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
-   Your shell should not have any memory leaks
-   No more than 5 functions per file
-   All your header files should be include guarded
-   Use system calls only when you need to (why?)

## Tasks

### 0. README, man, AUTHORS 
-   Write a README
-   Write a man for your shell.
-   You should have an AUTHORS file at the root of your repository, listing all

### 1. Betty would be proud
-   Write a beautiful code that passes the Betty checks

### 3. Simple shell 0.1 
-   Write a UNIX command line interpreter.

### 5. Simple shell 0.2
-   Simple shell 0.1 +

### 6. Simple shell 0.2.1
-   Simple shell 0.2 +
-   You are not allowed to use strtok

### 7. Simple shell 0.3
-   Simple shell 0.2 +

### 8. Simple shell 0.4 
-   Simple shell 0.3 +
-   Implement the exit built-in, that exits the shell
-   Usage: exit
-   You don’t have to handle any argument to the built-in exit

### 11. Simple shell 1.0 mandatory
-   Simple shell 0.4 +
-   Implement the env built-in, that prints the current environment

### 22. What happens when you type ls -l in the shell mandat
-   blog post describing step by step what happens when you type ls -l and hit Enter in a shell.
-   ***<https://www.linkedin.com/pulse/how-we-made-our-own-shell-nasser-abuchaibe>***

## Autors

-   ***Deiwin Ignacio Monsalve Altamar - <https://github.com/Deiwin-Ignacio-Monsalve-Altamar>***
-   ***Nasser Abraham Abuchaibe Gonzalez - <https://github.com/NasserAbuchaibe>***