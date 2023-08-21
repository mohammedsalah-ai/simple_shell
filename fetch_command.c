#include "main.h"

/**
* fetch_command - gets the command from the user
*
* @sh: pointer to switch on or off the shell
*
* Return: an array pointers that consists of command tokens
* or NULL of something failed.
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
