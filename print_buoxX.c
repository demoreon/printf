#include "main.h"

/**
 * p_hex_helper - This prints values in hex.
 * @num: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */

int p_hex_helper(unsigned int num, int len)
{
	char a[] = "0123456789abcdef";
	char A[] = "0123456789ABCDEF";
	char *chr;

	if (len >= 1999)
		chr = A;
	else
		chr = a;

	if (num >= 16)
		len = p_hex_helper(num / 16, len);
	PRINT(chr[num % 16]);
	return (++len);
}

/**
 * p_hex - This prints values in hex.
 * @args: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */

int p_hex(va_list *args, int len)
{
	unsigned int num;

	num = va_arg(*args, unsigned int);
	if (num == 0)
	{
		PRINT(num + 48);
		len -= 2000;
		return (++len);
	}
	len = p_hex_helper(num, len);
	return (len >= 1999 ? len - 2000 : len);
}


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
		return (++len);
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
		PRINT(48);
		return (++len);
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
