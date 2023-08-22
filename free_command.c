#include "main.h"

/**
* free_command - Frees memory associated with a command array.
*
* @command: Pointer to the array of command tokens to be freed.
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
