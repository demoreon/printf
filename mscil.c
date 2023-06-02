#include "main.h"

/**
 * buffer_pro - Handles buffer printingout
 * @buf: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */

int buffer_pro(char *buf, int len)
{
	int i = 0;

	while (buf[i] != '\0' && i < len)
	{
		PRINT(buf[i]);
		i++;
	}
	return (0);
}
