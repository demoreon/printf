#include <unistd.h>

void _putchar(char c)
{
	write(STDOUT, &c, 1);
}
