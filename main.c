#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%X", 0);
	len2 = printf("%X", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("\n%d---%d_ Lengths differ.\n", len, len2);
		fflush(stdout);
		return (1);
	}
	return (0);
}
