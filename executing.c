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
