#include "main.h"

/**
* free_command - frees commands
*
* @command: command to be freed.
*/
void free_command(char **command)
{
int i = 0;

while (command[i] != NULL)
{
free(command[i]);
i++;
}

free(command[i]);
free(command);
}
