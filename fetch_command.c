#include "main.h"

/**
* fetch_command - Reads and processes a command input from the user.
*
* @sh: Pointer to control the shell's operations (switch on/off)
*
* Return: An array of pointers representing command tokens,
* or NULL if there's an issue.
*/
char **fetch_command(int *sh)
{
char **command = NULL;
char *line = NULL;
size_t size = 0;
ssize_t read;

if (isatty(STDIN_FILENO))
{
printf("$ ");
}
read = getline(&line, &size, stdin);

if (feof(stdin))
{
if (isatty(STDIN_FILENO))
printf("\n");
free(line);
*sh = 0;
return (NULL);
}
stripf(line);
if (strlen(line) == 0 || read == -1)
{
free(line);
return (NULL);
}
command = tokenizef(&line);
return (command);
}
