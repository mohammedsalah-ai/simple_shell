#ifndef MAIN_H
#define MAIN_H


#include <stddef.h>

size_t my_getline(char *buf, size_t size);
void env_builtin();
void split_command(char *input, char *command, char *args[]);
void execute_command(char *command, char *args[]);
char *find_command_path(char *command);
extern char **environ;
void execute_builtin_exit(char *args[]);



#endif
