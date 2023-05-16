#include "main.h"

/**
 * p_binary - validates the char if exist.
 * @args: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */

int p_binary(va_list *args, int len)
{
	int num = va_arg(*args, int);
	unsigned mask = 1 << (sizeof(int) * 8 - 1);
	int chk = 0;

	if (num == 0)
	{
		PRINT('0');
		len += 1;
		return (len);
	}

	while (mask)
	{	if (num & mask)
		{
			PRINT('1');
			chk = 1;
			len += 1;
		}
		else if (chk)
		{
			PRINT('0');
			len += 1;
		}
		mask = mask >> 1;
	}
	return (len);
}
