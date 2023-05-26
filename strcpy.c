#include "titus.h"
/**
 * strcpyy - copy a string
 * @pest: pest string arg
 * @src: source arg
 * Return: string value
 */
char *strcpyy(char *pest, char *src)
{
	int i, len = 0;

	while (src[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		pest[i] = src[i];
	}
	pest[i] = '\0';
	return (pest);
}
