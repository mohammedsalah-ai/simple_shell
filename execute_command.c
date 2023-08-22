#include "main.h"

/**
* execute_command - Executes a command and handle process status.
*
* @command: Pointer to NULL-terminated array of command.
* @errs: Pointer to the number of errors that occurred.
* @exit_code: Pointer to the shell's exit code.
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
