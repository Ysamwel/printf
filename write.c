#include "main.h"
/**
 * handle_write_char - It prints the string
 * @c: character types.
 * @bufferchar: it handles a buffer array
 * @flags: finds active flags
 * @width: gets width of char
 * @precision: finds the precision specifier
 * @size: the size specifier
 *
 * Return: character printed
 */
int handle_write_char(char c, char bufferchar[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	bufferchar[i++] = c;
	bufferchar[i] = '\0';

	if (width > 1)
	{
		bufferchar[BUFF_SIZE - 1] = '\0';
		i = 0;
		while (i < width - 1)
		{
			bufferchar[BUFF_SIZE - i - 2] = padd;
			i++;
		}

		if (flags & F_MINUS)
			return (write(1, &bufferchar[0], 1) +
					write(1, &bufferchar[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &bufferchar[BUFF_SIZE - i - 1], width - 1) +
					write(1, &bufferchar[0], 1));
	}

	return (write(1, &bufferchar[0], 1));
}

/**
 * write_number - prints the string
 * @is_negative: it list the arguments
 * @ind: character type
 * @bufferchar: handles the buffer array
 * @flags: finds the active flags
 * @width: gets the width of character
 * @precision: gets precision specifier
 * @size: the size specifier
 *
 * Return: characters printed.
 */
int write_number(int is_negative, int ind, char bufferchar[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', ext_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		ext_ch = '-';
	else if (flags & F_PLUS)
		ext_ch = '+';
	else if (flags & F_SPACE)
		ext_ch = ' ';

	return (write_num(ind, bufferchar, flags, width, precision,
				len, padd, ext_ch));
}
/**
 * write_num - writes a number using buffer
 * @ind: the index the buffer starts
 * @bufferchar: handles the buffer array
 * @flags: finds active flags
 * @width: width of characters
 * @precision:the character precision specifier
 * @len: its number length
 * @padd: the Padding of chararacters
 * @ext_c: Extra characters to be printed
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char bufferchar[],
		int flags, int width, int precision,
		int len, char padd, char ext_c)
{
	int i, padding_start = 1;

	if (precision == 0 && ind == BUFF_SIZE - 2 &&
			bufferchar[ind] == '0' && width == 0)
		return (0);
	if (precision == 0 && ind == BUFF_SIZE - 2 && bufferchar[ind] == '0')
		bufferchar[ind] = padd = ' ';
	if (precision > 0 && precision < len)
		padd = ' ';

	for (; precision > len; --ind, ++len)
		bufferchar[ind - 1] = '0';

	if (ext_c != 0)
		len++;

	if (width > len)
	{
		for (i = 1; i < width - len + 1; ++i)
			bufferchar[i] = padd;

		bufferchar[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (ext_c)
				bufferchar[--ind] = ext_c;
			return (write(1, &bufferchar[ind], len) + write(1, &bufferchar[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
			if (ext_c)
				bufferchar[--ind] = ext_c;
			return (write(1, &bufferchar[1], i - 1) + write(1, &bufferchar[ind], len));
		else if (!(flags & F_MINUS) && padd == '0')
			if (ext_c)
				bufferchar[--padding_start] = ext_c;
			return (write(1, &bufferchar[padding_start], i - padding_start) +
					write(1, &bufferchar[ind], len - (1 - padding_start)));
	}

	if (ext_c)
		bufferchar[--ind] = ext_c;
	return (write(1, &bufferchar[ind], len));
}
/**
 * write_unsign - prints the unsigned number
 * @is_negative: value indicating a negative number
 * @ind: Index at start of buffer
 * @bufferchar: handles buffer array
 * @flags; it finds a active flag
 * @width: width of character
 * @precision: the precision specification
 * @size: the size of specifiers
 *
 * Return: character printed
 */
int write_unsign(int is_negative, int ind,
		char bufferchar[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && bufferchar[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		padd = ' ';

	for (; precision > len; precision--, len++)
	{
		bufferchar[--ind] = '0';
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			bufferchar[i] = padd;

		bufferchar[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &bufferchar[ind], len) + write(1, &bufferchar[0], i));
		}
		else
		{
			return (write(1, &bufferchar[0], i) + write(1, &bufferchar[ind], len));
		}
	}

	return (write(1, &bufferchar[ind], len));
}
/**
 * write_pointer - it writes to the memomry
 * @bufferchar: its an arry of buffer array
 * @ind: its an index of start buffer
 * @len: len of the numbers
 * @width: width of chars
 * @flags: finds active flags
 * @padd: Characters standing for padding
 * @ext_c: characters that are extra
 * @padding_start: the index for padding start
 *
 * Return: characters printed
 */
int write_pointer(char bufferchar[], int ind, int len,
		int width, int flags, char padd, char ext_c, int padding_start)
{
	int i = 3;

	if (width > len)
	{
		while (i < width - len + 3)
		{
			bufferchar[i] = padd;
			i++;
		}
		bufferchar[i] = '\0';

		if (flags & F_MINUS && padd == ' ')
		{
			bufferchar[--ind] = 'x';
			bufferchar[--ind] = '0';
			if (ext_c)
				bufferchar[--ind] = ext_c;
			return (write(1, &bufferchar[ind], len) + write(1, &bufferchar[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
			bufferchar[--ind] = 'x';
		bufferchar[--ind] = '0';
		if (ext_c)
			bufferchar[--ind] = ext_c;
		return (write(1, &bufferchar[3], i - 3) + write(1, &bufferchar[ind], len));
		else if (!(flags & F_MINUS) && padd == '0')
			if (ext_c)
				bufferchar[--padding_start] = ext_c;
		bufferchar[1] = '0';
		bufferchar[2] = 'x';
		return (write(1, &bufferchar[padding_start], i - padding_start) +
				write(1, &bufferchar[ind], len - (1 - padding_start) - 2));
	}

	bufferchar[--ind] = 'x';
	bufferchar[--ind] = '0';
	if (ext_c)
		bufferchar[--ind] = ext_c;
	return (write(1, &bufferchar[ind], BUFF_SIZE - ind - 1));
}
