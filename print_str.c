#include "main.h"
/**
 * print_str - it prints the string passed in
 * @parameters: arguments
 * @bufferchar: handles the buffer array
 * @flags:  finds active flags
 * @width:  width.
 * @precision: specification
 * @size: Size of the specifiers
 * Return: characters printed
 */
int print_str(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(parameters, char *);

	UNUSED(bufferchar);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = 0; i < (width - len); i++)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = 0; i < (width - len); i++)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
