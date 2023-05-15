#include <stdio.h>

/**
 * main - this is to just run betty
 * @argv: argument vector
 * @argc: argument count
 * Return: 0 on success -1 on failure
 */

int main(int argc, char **argv)
{
	int i;

	printf("argc: %d\n", argc);

	for (i = 0; i < argc; i++)
	printf("argv[%d]:, %s\n", i, argv[i]);

	return (0);
}
