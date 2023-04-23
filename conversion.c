#include "main.h"

/**
 * print_character - it prints a character
 * @parameters:arguments
 * @bufferchar: handles the buffer array
 * @flags:  finds active flags
 * @width: the width of the character
 * @precision: specification
 * @size: Size of the specifiers
 * Return: characters printed
 */
int print_character(va_list parameters, char bufferchar[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(parameters, int);

	return (handle_write_char(c, bufferchar, flags, width, precision, size));
}
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
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * print_pct - it prints out the percent sign
 * @parameters: arguments
 * @bufferchar: it handles the buffer array
 * @flags:  finds active flags
 * @width: width of the character
 * @precision: gets the precision specification
 * @size: specifiers size
 * Return: character printed
 */
int print_pct(va_list parameters, char bufferchar[],
	int flags, int width, int precision, int size)
{
	UNUSED(parameters);
	UNUSED(bufferchar);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - prints an interger
 * @parameters: arguments
 * @bufferchar: handles the buffer array
 * @flags:  finds active flags
 * @width: get width of the character.
 * @precision: finds specification
 * @size: Size specifier in the passed char
 * Return: characters printed
 */
int print_int(va_list parameters, char bufferchar[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int j = va_arg(parameters, long int);
	unsigned long int num;

	j = convert_size_number(j, size);

	if (j == 0)
		bufferchar[i--] = '0';

	bufferchar[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)j;

	if (j < 0)
	{
		num = (unsigned long int)((-1) * j);
		is_negative = 1;
	}

	while (j > 0)
	{
		bufferchar[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, bufferchar,
				flags, width, precision, size));
}

/**
 * print_binary - prints out the unisigned int
 * @parameters: arguments
 * @bufferchar: it handles the buffer array
 * @flags: finds the active flags
 * @width: get width of the char passed in
 * @precision: specifications
 * @size: specifiers size
 * Return: characters printed out.
 */
int print_binary(va_list parameters, char bufferchar[],
	int flags, int width, int precision, int size)
{
	unsigned int j, k, i, sum;
	unsigned int b[32];
	int count;

	UNUSED(bufferchar);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(parameters, unsigned int);
	k = 2147483648; /* (2 ^ 31) */
	b[0] = j / k;
	for (i = 1; i < 32; i++)
	{
		k /= 2;
		b[i] = (j / k) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += b[i];
		if (sum || i == 31)
		{
			char y = '0' + b[i];

			write(1, &y, 1);
			count++;
		}
	}
	return (count);
}
