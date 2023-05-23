#include "main.h"

void exem(char **argv)
{
        char *pname = NULL;

        if(argv)
        {
                pname = argv[0];


if(execve(pname,argv,NULL) == -1)
{
        perror("Error");
}

}

}

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
	char *token2;
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

	lineptr_copy = strdup(lineptr);

	if (lineptr_copy == NULL)
	{
		perror("memory allocation error");
		return (-1);
	}
	token = strtok(lineptr, delim);

	 while(token != NULL)
	 {
		 tokens_number++;
			 token = strtok(NULL, delim);
	 }

	 tokens_number++;
	 token2 = strtok(lineptr_copy, delim);

	 argv = malloc(sizeof(char *) * tokens_number);

	 for (i=0; token2 != NULL; i++)
	 {
		 argv[i] = malloc(sizeof(char) * strlen(token2));
				 strcpy(argv[i], token2);
				 token2 = strtok(NULL, delim);
				 }
				 argv[i] = NULL;
				 free(argv[i]);
				 exem(argv);


	}

	free(lineptr);
	free(lineptr_copy);
	free(argv);

	return (0);

}
