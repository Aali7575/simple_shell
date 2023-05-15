#include "main.h"

/**
 * main - display a prompt
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *prompt;
	char *lineptr;
	size_t x = 0;
	ssize_t checking;
	char *line_strtok;
	const char *delim = " \n";
	char *token;
	int num_tokens = 0;


	(void)argc;
	(void)argv;

	prompt = ("Shell $ ");
	while(1)
	{
			printf("%s", prompt);
			checking = getline(&lineptr,&x,stdin);
			if (checking == -1)
			{
				printf("Exiting shell...\n");
				return (-1);
			}
			line_strtok = malloc(sizeof(char) * checking);
			if (line_strtok == NULL)
			{
				perror("tsh: memory allocation error\n");
				return (-1);
			}
			strcpy(line_strok,lineptr);
			
			token = strtok(lineptr,delim);
			while(token == NULL)
			{
				num_tokens++;
				token = strtok(NULL, delim);
			}
			num_tokens++;

			argv = malloc(sizeof(char *) * num_tokens);
			token = strtok(line_strtok,
			printf("%s", lineptr);

			free(lineptr);
	}

	return (0);
}
