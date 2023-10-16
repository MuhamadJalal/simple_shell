#include "main.h"

/**
 * execute - executes in the main shell
 * @status: the status of the path, whether the file found is executable or not
 * @args: the parsed arguments
 * @exit_status: the exit status
 * @tal: tally of commands or attempted commands that were run
 * Return: void
 */
void execute(int status, char **args, int *exit_status, int *tal)
{
	if (status == 2)
	{
		if (access(args[0], X_OK) == 0)
		{
			if (fork() == 0)
				execve(args[0], args, NULL);

			else
				wait(NULL);
			*exit_status = 0;
		}
		else if (access(args[0], F_OK) != 0)
		{
			print_str("hsh: ");
			print_int(tal);
			print_str(": ");
			perror(args[0]);
			*exit_status = 127;
		}
		else if (access(args[0], F_OK) == 0 &&
			 access(args[0], X_OK) != 0)
		{
			print_str("hsh: ");
			print_int(tal);
			print_str(": ");
			perror(args[0]);
			*exit_status = 126;
		}
	}
	free(args);
}
