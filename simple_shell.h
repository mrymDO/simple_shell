#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>  
#include <stddef.h> 


extern char **environ;

char *_getenv(const char *varname);
void _putchar(char c);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(const char *s, char c);
char *_strdup(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
void *_realloc(void *ptr, unsigned int size);
char *_memcpy(char *dest, char *src, unsigned int n);




int execute_cmd(char **args, char **argv, char **env);
char **fill_arr_by_tokens(char *buf_copy, char **args);
void forking(char *args[]);
void free_arr_of_strs(char **arr);
unsigned int get_num_tokens(char *buf);
char *get_path(char *cmd);
int is_input_env(char **args, char **env);
void is_input_exit(char **args);
int is_path(char *cmd);
char *read_line();
char **split_dirs(char *env_dirs);
void set_env(char **args, char **env);
int change_dir(char **args);
void unset_env(char **args, char **env);
char **check_for_comts(char **args);

#endif
