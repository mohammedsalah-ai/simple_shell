#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "main.h"

/**
 * Basic shell program:
 *
 * This program implement a simple shell that reads user input, split it into command
 * and arguments, and execute the command with the provided arguments. it domestrate custom
 * getline and argument parsing fuctionalities.
 *
 * Key Concept:
 * -The program prompt the user with "$ ".
 *  -It reads user input using a custom getline function.
 *  -The input is split into a command and argument using split_command
 *  -The execute_command function runs the command with its argument.
 *  -Support built-in commands like 'exit' and 'env'.
 *  -Hsndles command execution usinf execve and waits for child processes.
 *
 *  Overall, this shell provides a basic command-line interface and showcase fundemental
 *  concept of input parsing and execution. 
 */
int main()	
{	
	while (1)
	{
		printf("$ ");

		char user_input[100];


		ssize_t read_chars = my_getline(user_input, sizeof(user_input));

		if (read_chars == -1)
		{
			printf("\n");
			break;
		}


		char command[50];
		char *args[10];
		split_command(user_input, command, args);

		execute_command(command, args);

		printf("$ ");
	
		if (strcmp(command, "exit") == 0)
		{
			if (args[1])
			{
				int exit_status = atoi(args[1]);
				exit(exit_status);
			}
			else
			{
			exit(0);
			}
			}
			}
			return 0;
			}
					
