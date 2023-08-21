#include "main.h"

/**
* stripf - removes leading and trailing whitespaces,
* also leaves only while space between tokens
*
* @line: string to be stripped
*/
void stripf(char *line)
{
int length = strlen(line);
int start = 0;
int end = length - 1;
int i, j;
int insideToken = 0;

if (line == NULL)
return;

while (isspace(line[start]))
start++;


while (end >= start && isspace(line[end]))
end--;


for (i = start, j = start; i <= end; i++)
{
if (isspace(line[i]))
{
if (!insideToken)
{
line[j++] = ' ';
insideToken = 1;
}
}
else
{
line[j++] = line[i];
insideToken = 0;
}
}

line[j] = '\0';

memmove(line, line + start, j - start + 1);
}
