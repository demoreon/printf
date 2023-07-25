#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%ld", LONG_MIN);
	len2 = printf("%ld", LONG_MIN);
	fflush(stdout);
	if (len != len2)
	{
		printf("len %d = len2 %d", len, len2);
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
