#include "main.h"

/**
 * main - writing a UNIX command line
 * @argc: argument count
 * @argv: argument vector
 * Return: 1 if sucessful
 */

int main(int argc, char *argv[])
{
	char *prompt;
	ssize_t get;
	size_t size = 0;
	char *lineptr = NULL;
	ssize_t written;
	int len;


	prompt = "$ ";
	len = strlen(prompt);
	written = write(STDOUT_FILENO,prompt,len);

	get = getline(&lineptr,size,stdin);
	if (get == NULL)
	{
		perror("Exiting shell...");
		return (-1);
	}
	free(lineptr);
	return (0);
}

