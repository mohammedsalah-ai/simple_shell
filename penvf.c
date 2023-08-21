#include "main.h"

/**
* penvf - prints the environment variables
*
*/
void penvf(void)
{
char **envp = environ;

for (; envp != NULL && *envp != NULL; envp++)
printf("%s\n", *envp);
}
