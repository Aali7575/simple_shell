#include "main.h"

int main(int argc, char **argv)
{
	(void)argc;
	char *prompt;
	size_t prompt_len;
	ssize_t prompt_mess;
	ssize_t prompt_get;
	size_t line_size = 0;
	char *lineptr = NULL;
	char *token;
	const char *delim = (" \n");
	char *lineptr_copy;
	int tokens_number;
	int i;

	while(1)
	{
	prompt = ("$ ");
	prompt_len = strlen(prompt);
	prompt_mess = write(STDOUT_FILENO,prompt,prompt_len);

	prompt_get = getline(&lineptr,&line_size,stdin);

	if (prompt_get == -1)
	{
		perror("Exiting shell..");
		return (-1);
	}
	strcpy(lineptr_copy, lineptr);
	token = strtok(lineptr, delim);

	 while(token != NULL)
	 {
		 tokens_number++;
			 token = strtok(NULL, delim);
	 }

	 tokens_number++;

	 argv = malloc(sizeof(char *) * tokens_number);

	 for (i=0; token != NULL; i++)
	 {
		 argv[i] = malloc(sizeof(char) * strlen(token));
				 strcpy(argv[i], token);
				 token = strtok(NULL, delim);
				 }
				 argv[i] = NULL;


	}
	/*free(argv);*/
	/*free(argv[i]);*/

	free(lineptr);

	return (0);

}
