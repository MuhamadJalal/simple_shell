#include "main.h"

/**
 * free_grid - frees a 2 dimensional grid of int pointers
 * @grid: Char double pointer to be freed
 * @height: int for height of 2D array to be passed
 * Return: void
 */

void free_grid(char **grid, int height)
{
	int k;

	for (k = 0; k < height; k++)
		free(grid[k]);

	free(grid);
}

/**
 * no_line - removes the new line with the NULL character
 * @l: the line
 * Return: nothing
 */
void no_line(char *l)
{

	int i = 0;

	while (l[i])
	{
		if (l[i] == '\n')
		{
			l[i] = '\0';
			return;
		}

		i++;
	}
}

/**
 * special_char - if the user types control d, it exits the shell and handles
 * the error when the user keeps on tabbing, it carries out the command
 * @bytes: the number of bytes read in from the user input
 * @buffer: the buffer
 * @exit_status: the exit status
 * Return: Always (0) for succcess
 */
int special_char(char *buffer, ssize_t bytes, int *exit_status)
{
	int i = 0;

	if (bytes == EOF && isatty(STDIN_FILENO) == 1)
	{
		_putchar('\n');
		free(buffer);
		exit(*exit_status);
	}

	if (bytes == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(buffer);
		exit(*exit_status);
	}

	if (_strcmp(buffer, "\n") == 0)
	{
		*exit_status = 0;
		return (127);
	}

	while (buffer[i] != '\n')
	{
		if (buffer[i] != ' ' && buffer[i] != '\t')
			return (0);

		++i;
	}

	*exit_status = 0;
	return (127);
}
