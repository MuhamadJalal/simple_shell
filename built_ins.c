#include "main.h"

/**
 * built_in - implements the exit and printenv built_in
 * @line: the buffer
 * @args: the parsed arguments
 * @env: the environment
 * @exit_status: the exit status
 * Return: void
 */
void built_in(char *line, char **args, char **env, int *exit_status)
{

	if (_strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(line);
		exit(*exit_status);
	}

	if (_strcmp(args[0], "env") == 0)
		printenv(env, exit_status);
}
