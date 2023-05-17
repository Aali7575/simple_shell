#include "main.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *prompt;
	ssize_t written;
	size_t len;
	(void)STDOUT_FILENO;

	prompt = ("Simple_shell $");
	len = strlen(prompt);
		

	written = write(STDOUT_FILENO, prompt, len);

	if (written == -1)
	{
		return (1);
	}
	return (0);
}


