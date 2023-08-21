#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

char **fetch_command(int *sh);
void stripf(char *line);
char **tokenizef(char **line);
int isexef(char **cmdname);
void findpathf(char **cmdname);
void penvf(void);
void execute_command(char **command, int *errs, int *exit_code);
void free_command(char **command);

#endif /*_MAIN_H_*/
