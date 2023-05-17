#include "main.h"

/**
 * p_octal - This prints values in octal.
 * @args: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */

int p_octal(va_list *args, int len)
{
	unsigned int num = va_arg(*args, unsigned int);
	unsigned int oct;
	int i = 0;
	int a[12];

	if (num == 0)
	{
		PRINT(48);
		return (len++);
	}
	while (num)
	{
		oct = (num & 7);
		a[i] = oct;
		i++;
		num >>= 3;
	}
	i--;
	while (i >= 0)
	{
		PRINT(a[i] + 48);
		len++;
		i--;
	}
	return (len);
}

/**
 * p_usigned_int - This prints unsigned integers.
 * @args: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */

int p_usigned_int(va_list *args, int len)
{
	unsigned int num = va_arg(*args, unsigned int);
	unsigned int div = 1;

	if (num == 0)
	{
		PRINT('0');
		return (len++);
	}
	while (num / div >= 10)
		div *= 10;
	while (div > 0)
	{
		PRINT(num / div + 48);
		len++;
		num %= div;
		div /= 10;
	}
	return (len);
}

/**
 * p_binary - validates the char if exist.
 * @args: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */

int p_binary(va_list *args, int len)
{
	int num = va_arg(*args, int);
	int mask = 1 << (sizeof(int) * 8 - 1);
	int chk = 0;

	if (num == 0)
	{
		PRINT('0');
		len += 1;
		return (len);
	}

	while (mask)
	{
		if (num & mask)
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
