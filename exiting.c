#include "titus.h"
/**
 * exitt - function that terminate the prog when
 * user types "exit".
 * @cmd: the string to be read.
 * Return: nothing.
 *
 */
void exitt(char *cmd)
{
	if (_strcmp("exit", cmd) == 0)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}
}

