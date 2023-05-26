#include "titus.h"
/**
 * main - main function
 * @arc: len argument
 * @abc: abc argument by user
 * @envp: envp argument env
 * Return: 0
 */
int main(int arc, char **abc, char **envp)
{
	bool interactive = (arc == 1 && isatty(STDIN_FILENO));

	prompt(abc, envp, interactive);
	return (0);
}
