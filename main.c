#include "main.h"

/**
* main - the main function
*
* @ac: number of args
* @av: args passed
* Return: 0 success.
*/
int main(int ac, char **av)
{
int shell = 1, errors = 0, exit_code = 0, isexe;
char **command = NULL;
ac = ac;

while (shell)
{
command = fetch_command(&shell);
if (command != NULL)
{
if (strcmp(command[0], "exit") == 0)
{
free_command(command);
break;
}
if (strcmp(command[0], "env") == 0)
{
penvf();
exit_code = 0;
free_command(command);
continue;
}
isexe = isexef(&command[0]);
if (isexe == 0)
{
(errors)++;
fprintf(stderr, "%s: %d: %s: not found\n", av[0], errors, command[0]);
exit_code = 127;
free_command(command);
continue;
}
else if (isexe == 1)
findpathf(&command[0]);

execute_command(command, &errors, &exit_code);
}
}
return (exit_code);
}
