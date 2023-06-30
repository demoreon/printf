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

/**
 * p_addr - This prints values in hex.
 * @args: list of variable auguments.
 * @len: char printed
 * Return: len of the printed char.
 */
int p_addr(va_list *args, int len)
{
	u_int64_t addr;
	int i, digit, chk = 0;
	void *s = va_arg(*args, void *);

	addr = (u_int64_t)s;
	putchar(48);
	putchar('x');
	len += 2;
	fflush(stdout);
	for (i = sizeof(void *) * 2 - 1; i >= 0; i--)
	{
		digit = (addr >> (i * 4)) & 0xF;
		if (digit == 0 && chk == 0)
			continue;
		PRINT(digit < 10 ? '0' + digit : 'a' + digit - 10);
		fflush(stdout);
		len++;
		chk = 1;
	}
	return (len);
}
