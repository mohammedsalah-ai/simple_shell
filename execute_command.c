#include "main.h"

/**
* execute_command - a function that executes a command
*
* @command: a NULL terminated pointer of command tokens
* @errs: number of errors that occurred
* @exit_code: shell exit code.
*/
void execute_command(char **command, int *errs, int *exit_code)
{
pid_t pid;
int status;
pid = fork();
if (pid == -1)
{
perror("Fork failed");
return;
}
else if (pid == 0)
{
if (execve(command[0], command, environ) == -1)
{
(*errs)++;
perror("Execve failed");
}
free_command(command);
}
else
{
wait(&status);
if (WIFEXITED(status))
*exit_code = WEXITSTATUS(status);
else if (WIFSIGNALED(status))
{
fprintf(stderr, "Child process killed by signal: %d\n", WTERMSIG(status));
*exit_code = WTERMSIG(status);
}
free_command(command);
}
}
