#include "main.h"

/**
 * printenv - prints the environment variable
 * @env: the environment variable to print
 * @exit_status: exit status
 * Return: Always (0) for sucess
 */
int printenv(char **env, int *exit_status)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		print_str(env[i]);
		_putchar('\n');
		i++;
	}
	*exit_status = 0;
	return (EXIT_SUCCESS);
}
