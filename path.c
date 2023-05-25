#include "tito.h"
/**
 * pathb - handle the path function
 * @rgv: rgv argument
 * @cmd: command set by the user
 * Return: command for exec
 */
char *pathb(char **rgv, char *cmd)
{
	char *path;

	path = malloc(_strlen("/bin/") + _strlen(cmd) + 1);
	if (!path)
	{
		free(path);
		return (NULL);
	}
	_strcpy(path, "/bin/");

	if (cmd[0] != '/')
	{
		rgv[0] = _strcat(path, cmd);
		return (rgv[0]);
	}
	free(path);
	return (cmd);
}