#include "main.h"

/**
 * print_unsigned_int - prints unsigned integer
 * @parameters: arguments
 * @bufferchar: array that handles print
 * @flags: gives calculation of active flags
 * @width: width
 * @precision: specification of precision
 * @size: for size
 * Return: printed characters
 */
int print_unsigned_int(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int fig = va_arg(parameters, unsigned long int);

	fig = cnvt_size_unsign(fig, size);

	if (fig == 0)
		bufferchar[i--] = '0';

	bufferchar[BUFF_SIZE - 1] = '\0';

	for (; fig > 0; fig /= 10)
	{
		bufferchar[i--] = (fig % 10) + '0';
	}

	i++;

	return (write_unsign(0, i, bufferchar, flags, width, precision, size));
}

