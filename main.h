#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

char **fetch_command(char **lineptr, size_t *n, FILE *stream, const char *delim);

#endif /*_MAIN_H_*/
