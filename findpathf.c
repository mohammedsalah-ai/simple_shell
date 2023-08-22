#include "main.h"

/**
* findpathf - searches through the directories in the PATH environment variables
* 		to locate the executable command.
*
* @cmdname: Pointer to the command to be executed.
*/
void findpathf(char **cmdname)
{
char *path = getenv("PATH");
char *pathcp = strdup(path);
char *token = strtok(pathcp, ":");
char *trypath = NULL;

while (token != NULL)
{
trypath = malloc(strlen(*cmdname) + strlen(token) + 2);
sprintf(trypath, "%s/%s", token, *cmdname);

if (access(trypath, X_OK) == 0)
{
free(*cmdname);
*cmdname = strdup(trypath);
free(trypath);
break;
}
free(trypath);
token = strtok(NULL, ":");
}

free(pathcp);

}
