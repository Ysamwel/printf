#include "main.h"
/**
 * p_hexadecimal - prints unsigned interger in hexadecimal notation
 * @parameters: arguments
 * @bufferchar: array buffer that handles print
 * @flags:  gives calculation of active flags
 * @width: width
 * @precision: specification of precision
 * @size: the size
 * Return: chararacters printed
 */
int p_hexadecimal(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(parameters, "0123456789abcdef", bufferchar,
				flags, 'x', width, precision, size));
}

/**
 * print_hexa_upp - prints unsigned interger in uppercase hexadecimal notation
 * @parameters: arguments
 * @bufferchar: array buffer that handles print
 * @flags: gives calculation of active flags
 * @width: width
 * @precision: specification of precision
 * @size: specification of precision
 * Return: characters printed
 */
int print_hexa_upp(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(parameters, "0123456789ABCDEF", bufferchar,
				flags, 'X', width, precision, size));
}
/**
  * print_hexa - print hexadecimal integer in lower or upper
  * @parameters: arguments
  * @map_loc: array values to map integers
  * @bufferchar: array buffer that handles print
  * @flags: gives calculation of active flags
  * @flag_ch: gives calculation of active flags
  * @width: width
  * @precision: specification for precision
  * @size: size
  * Return: characters printed
  */int print_hexa(va_list parameters, char map_loc[], char bufferchar[],
		  int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int fig = va_arg(parameters, unsigned long int);
	unsigned long int init_num = fig;

	UNUSED(width);

	fig = convert_size_unsign(fig, size);

	if (fig == 0)
		bufferchar[i--] = '0';

	bufferchar[BUFF_SIZE - 1] = '\0';

	for (; fig > 0; fig /= 16)
	{
		bufferchar[i--] = map_loc[fig % 16];
	}

	if (flags & F_HASH && init_num != 0)
	{
		bufferchar[i--] = flag_ch;
		bufferchar[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, bufferchar, flags, width, precision, size));
}

