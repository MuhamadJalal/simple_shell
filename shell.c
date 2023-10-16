#include "main.h"

/**
 * main - Program that is simple UNIX command interpreter
 * @argc: argument count
 * @argv: argument vector
 * @env: the environment
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *prompt = "$", *line = NULL, **args = NULL;
	int status = 0;
	static int exit_stat, tally;
	size_t len = 0, read = 0;
	(void)argc, (void)**argv;

	while (TRUE)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, 6);

		read = getline(&line, &len, stdin);
		++tally;
		if (special_char(line, read, &exit_stat) == 127)
			continue;

		no_line(line);

		args = parser(line);

		built_in(line, args, env, &exit_stat);

		status = _path(args[0], args, env, &exit_stat);

		execute(status, args, &exit_stat, &tally);

		fflush(stdin);
	}
	free(line);
	return (0);
}
