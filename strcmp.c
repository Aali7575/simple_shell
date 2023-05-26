#include "titus.h"
/**
 * _strcmp - unction that compares two strings
 * @t1: first function
 * @t2: second function
 * Return: val
 */
int _strcmp(char *t1, char *t2)
{
	int cmp = 0;

	while (*t1 == *t2 && *t1 != '\0')
	{
		t1++;
		t2++;
	}
	if (t1 != t2)
		cmp = *t1 - *t2;

	return (cmp);
}
