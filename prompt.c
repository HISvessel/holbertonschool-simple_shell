#include <stdio.h>
#include <stdlib.h>

/**
 * shell - a miniature terminal
 * @argc: void
 * @argv: void
 * return: 0 on success
 */
int main(void)
{
	char *prompt = "Insert& ";
	char *lineptr;
	size_t n = 0;

	while (1)
	{
		printf("%s", prompt);
		getline(&lineptr, &n, stdin);
		printf("%s", lineptr);
	}
	free (lineptr);
	return (0);
}
