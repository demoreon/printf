#include "main.h"

/**
 * p_hex_helper - This prints values in hex.
 * @num: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */

int p_hex_helper(long num, int len)
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
	long num;
	if (len >= 4999)
	{
		num = va_arg(*args, long);
		len -= 5000;
	}
	else
		num = va_arg(*args, int);
	if (num == 0)
	{
		PRINT(48);
		if (len >= 4499)
			return (++len - 4500);
		else if	(len >= 2499)
			return (++len - 2500);
		return (++len);
	}
	if (len >= 4499)
	{
		PRINT('0');
		PRINT('X');
		len -= 2498;
	}
	else if	(len >= 2499)
	{
		PRINT('0');
		PRINT('x');
		len -= 2498;
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
	long num;
	unsigned int oct;
	int i = 0;
	int a[12];
	char buf[BUF_MAX];
	int c = 0; /* buffer index tracker */

	if (len >= 4999)
	{
		num = va_arg(*args, long);
		len -= 5000;
	}
	else
		num = va_arg(*args, unsigned int);
	if (num == 0)
	{
		PRINT(48);
		if (len >= 2499)
			return (++len - 2500);
		return (++len);
	}
	if (len >= 2499)
	{
		PRINT('0');
		len -= 2499;
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
		if (c == BUF_MAX)
			c = buffer_pro(buf, c);
		buf[c] = a[i] + 48;
		c++;
		len++;
		i--;
	}
	buf[c] = '\0';
	if (c) /* Check buffer not empty */
		buffer_pro(buf, c);
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
	long num;
	unsigned int div = 1;
	char buf[BUF_MAX];
	int c = 0; /* buffer index tracker */

	if (len >= 4999)
	{
		num = va_arg(*args, long);
		len -= 5000;
	}
	else
		num = va_arg(*args, unsigned int);
	if (num == 0)
	{
		PRINT(48);
		return (++len);
	}
	while (num / div >= 10)
		div *= 10;
	while (div > 0)
	{
		if (c == BUF_MAX)
			c = buffer_pro(buf, c);
		buf[c] = num / div + 48;
		c++;
		len++;
		num %= div;
		div /= 10;
	}
	buf[c] = '\0';

	if (c) /* Check buffer not empty */
		buffer_pro(buf, c);
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
	unsigned int mask = 1 << (sizeof(int) * 8 - 1);
	int chk = 0;
	char buf[BUF_MAX];
	int i = 0; /* buffer index tracker */

	if (num == 0)
	{
		PRINT('0');
		len += 1;
		return (len);
	}

	while (mask)
	{
		if (i == BUF_MAX)
			i = buffer_pro(buf, i);
		if (num & mask)
		{
			buf[i] = '1';
			i++;
			chk = 1;
			len += 1;
		}
		else if (chk)
		{
			buf[i] = '0';
			i++;
			len += 1;
		}
		mask = mask >> 1;
	}
	buf[i] = '\0';
	if (i) /* Check buffer not empty */
		buffer_pro(buf, i);
	return (len);
}
