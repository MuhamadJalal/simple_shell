#ifndef MAIN_H
#define MAIN_H

#define TRUE (1 == 1)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int _path(char *first, char **input, char **env, int *exit_status);

int printenv(char **env, int *exit_status);

void built_in(char *line, char **args, char **env, int *exit_status);
void execute(int status, char **args, int *exit_status, int *tal);

int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

int _putchar(char c);
void print_str(char *s);
char *pathstr(char *right, char *first);
char **parser(char *l);
void print_int(int *tal);

void no_line(char *l);
void free_grid(char **grid, int height);
int special_char(char *buffer, ssize_t bytes, int *exit_status);

#endif
