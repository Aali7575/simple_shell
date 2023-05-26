#include "titus.h"
/**
 * pathhandler - handle the path function
 * @rgv: rgv argument
 * @cmd: command set by the user
 * Return: command for exec
 */
char *pathhandler(char **rgv, char *cmd)
{
	char *path;

	path = malloc(_strlen("/bin/") + _strlen(cmd) + 1);
	if (!path)
	{
		return (NULL);
	}
	strcpyy(path, "/bin/");

	if (cmd[0] != '/' && cmd[0] != '.')
	{
		rgv[0] = _strcat(path, cmd);
		return (rgv[0]);
	}
	free(path);
	return (cmd);
}

