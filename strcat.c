#include "titus.h"
/**
 * _strcat - This function appends the src string to the pest string
 * @pest: string agument
 * @src: string argument
 * Return: String
 */
char *_strcat(char *pest, char *src)
{
	int len = 0, lend = 0, j;

	while (src[len] != '\0')
	{
		len++;
	}
	while (pest[lend] != '\0')
	{
		lend++;
	}
	for (j = 0; j < len; j++)
	{
		pest[lend + j] = src[j];
	}
	pest[lend + len] = '\0';
	return (pest);
}
