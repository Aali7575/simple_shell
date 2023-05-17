#include "main.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *prompt;
	ssize_t written;
	size_t len;
	(void)STDOUT_FILENO;
	char *buffer = NULL; /*this is for our getline function*/
	size_t bufsize;
	ssize_t gettext;
	ssize_t console;
	size_t length;
	const char *delim; /*this is for tokenization*/
	char *bufcopy;

	/*prompt for our shell*/
	prompt = ("Simple_shell $ ");
	len = strlen(prompt);
		
/*enabling it to print to the console*/
	while(1)
	{
	written = write(STDOUT_FILENO, prompt, len);

	if (written == -1)
	{
		return (1);
	}
	gettext = getline(&buffer,&bufsize,stdin);

	if (gettext == -1)
	{
		errno = EINVAL;
		perror("Exiting shell");
		return (-1);
	}

	length = strlen(buffer);
	console = write(STDOUT_FILENO,buffer,length);
	}
	free(buffer);
	return (0);
}


