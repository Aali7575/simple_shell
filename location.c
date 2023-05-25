#include "main.h"

char *loc(char *pname)
{
	char *mypath, path2, mytoken, fullpath;
	int tokenlen, len;
	struct stat buf;

	mypath = getenv("PATH");

	if(mypath)
	{

	path2 = strdup(mypath);
	len = strlen(pname);
	mytoken = strtok(path2, ":");

	while(mytoken != NULL)
	{
	tokenlen = strlen(mytoken);
	fullpath = malloc(len + tokenlen + 2);
	strcpy(fullpath, mytoken);
	strcat(fullpath, "/");
	strcat(fullpath, pname);
	strcat(fullpath, "\0");

	if (stat(fullpath, &buf) == 0)
	{
		free(path2);

		return (fullpath);
	}
	else
	{
		free(fullpath);
		mytoken = strtok(NULL, ":");
	}
	
	}
	free(path2);

	if(stat(pname, &buf) == 0)
	{
		return (pname);
	}
	return (NULL);
	}
	return (NULL);




}

