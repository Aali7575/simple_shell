#include "tito.h"
/**
 * _strncpy - copy n char
 * @pep: string argument
 * @src: string argument for src
 * @n: integer argument
 * Return: pep
 */
char *_strncpy(char *pep, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		pep[i] = src[i];
	}
	for (; i < n; i++)
	{
		pep[i] = '\0';
	}
	return (pep);
}
