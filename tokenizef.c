#include "main.h"

/**
* tokenizef - tokenizes a string to its simple tokens.
*
* @line: string to be tokenized, delimiter is a space.
* Return: an array pointers that consists of the command tokens
*/
char **tokenizef(char **line)
{
char *tokena;
char *tokenb;
char *linecp = strdup(*line);
char **command = NULL;
int i;

if (line == NULL)
return (NULL);

tokena = strtok(*line, " ");
for (i = 0; tokena != NULL; i++)
tokena = strtok(NULL, " ");


command = malloc((i + 1) * sizeof(char *));
tokenb = strtok(linecp, " ");
for (i = 0; tokenb != NULL; i++)
{
command[i] = strdup(tokenb);
tokenb = strtok(NULL, " ");
}

command[i] = NULL;
free(*line);
free(linecp);

return (command);
}
