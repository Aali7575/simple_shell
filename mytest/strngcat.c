#include "titus.h"
/**
 * _strncat - Concantenates two strings where n number
 *            of bytes are copied from source.
 * @pest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: n bytes to copy from src.
 *
 * Return: Pointer to pestination string.
 */
char *_strncat(char *pest, const char *src, size_t n)
{
	size_t dest_len = _strlen(pest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		pest[dest_len + i] = src[i];
	pest[dest_len + i] = '\0';

	return (pest);
}
