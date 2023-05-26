#include "titus.h"
/**
 * strncopy - copy n char
 * @pest: string argument
 * @src: string argument for src
 * @n: integer argument
 * Return: pest
 */
char *strncopy(char *pest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		pest[i] = src[i];
	}
	for (; i < n; i++)
	{
		pest[i] = '\0';
	}
	return (pest);
}
