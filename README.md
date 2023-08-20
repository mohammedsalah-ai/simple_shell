This is The Simple Shell Project for the ALX Software Engineering Programm.

Team Members.
-------------------------------------------------------------------------------------------------
Name: Yusuf Yahaya
Email: feezynharmony@gmail.com
country: Nigeria
-------------------------------------------------------------------------------------------------
Name: Mohammed Salah
Email:
Country: Egpyt
-------------------------------------------------------------------------------------------------
Shell Concept Overview:

The implemented simple shell serves as a basic command-line interface, allowing users to interact with the underlying operating system through text-based commands. It embodies the fundamental principles of input parsing, command execution, and process management.

main.c:
The heart of the shell program resides in the main.c file. It sets up a continuous loop that prompts the user with a "$ " symbol, waiting for input. The custom my_getline function is used to read user input, ensuring the program doesn't exceed buffer limits. The input is then processed using the split_command function, extracting the command and its associated arguments.

If the command is a built-in one like "exit" or "env," the corresponding actions are executed immediately, handling program termination or displaying the environment variables. For external commands, the execute_command function is invoked. It first searches for the command's path using find_command_path, considering multiple possible locations. If the command is found, it's executed using execve, effectively replacing the current process with the specified command. This mechanism enables executing various external programs within the shell environment.

execute_commands.c:
This file houses the execute_command function, which orchestrates the execution of user commands. If the command is "exit" or "env," the respective built-in functions are called. For external commands, the shell attempts to locate the command's executable using find_command_path. If the executable is found, it is invoked with the provided arguments. Error handling is comprehensive, including checking for the successful execution of external commands and displaying appropriate error messages.

find_command_path.c:
This file contains the find_command_path function, responsible for locating the full path to an executable command. It searches through predefined paths, such as "/bin" and "/usr/bin," to identify the command's location. If the command is found, its full path is returned, enabling successful execution.

parse_command.c:
The parse_command function in this file is crucial for splitting user input into the actual command and its arguments. It processes the input string character by character, identifying spaces and tabs as separators between arguments. It stores the extracted command and arguments in designated memory locations, preparing the data for further processing and execution.

builtins.c:
This file hosts the implementations of the built-in shell commands "exit" and "env." The execute_builtin_exit function terminates the shell program with an optional exit status provided by the user. The env_builtin function displays the environment variables, providing insight into the current environment within the shell.

main.h:
The header file defines the function prototypes for various functions used throughout the shell program. It ensures that the functions declared in the header are consistent with their implementations in the source files. Additionally, it includes necessary system header files and variable declarations, such as extern char **environ for access to environment variables.

Overall Impact:
This simple shell demonstrates core principles of command-line interaction, input parsing, process management, and execution within a Unix-like environment. It offers users a glimpse into the intricacies of how a shell interprets commands, locates executables, and handles process execution. While basic in its scope, this shell sets the foundation for more complex shell implementations and offers a hands-on learning experience in systems programming.
