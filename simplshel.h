#ifndef SIMPLSHEL_H
#define SIMPLSHEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>

#define _delim " \n\r\a\t"

extern char **environ;
int toknizor(char *comandl, int countl, char **argmt);
int _exec(char **command_lst, int i, char *comandl, int count, char **argmt);
char *_path(char *command);
char *directory(char *temporal_dir, char *command);
char *stringcpy(char *ptrdestin, char *ptrsorc);
void *_malloc1(unsigned int num_arry, unsigned int size);
void an_exit(char **text, int a, char *comandl, int exit_status);
void _envt(void);
void sig_handl(int signal __attribute__((unused)));
int _strlen(char *str);
char *_strncpy(char *destin, char *sorc, int n);
char *_strdup(char *strptr);
char *_strcat(char *destin, char *sorc);
int _strcomp(char *str1, char *str2);
int _putchr(char c);
void putint(int n);
void no_command(int ptrd, char **comand_lst, int count, char **argmt);


#endif
