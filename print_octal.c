#include "main.h"
/**
 * print_octal - prints unsigned interger in octal notation
 * @parameters: arguments
 * @bufferchar: array buffer that handles print
 * @flags:  gives calculations of active flags
 * @width: gives width
 * @precision: specification for precision
 * @size: size
 * Return: chararacters printed
 */
int print_octal(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int fig = va_arg(parameters, unsigned long int);
	unsigned long int init_num = fig;

	UNUSED(width);

	fig = convert_size_unsign(fig, size);

	if (fig == 0)
		bufferchar[i--] = '0';

	bufferchar[BUFF_SIZE - 1] = '\0';

	for (; fig > 0; fig /= 8)
	{
		bufferchar[i--] = (fig % 8) + '0';
	}

	if (flags & F_HASH && init_num != 0)
		bufferchar[i--] = '0';

	i++;

	return (write_unsign(0, i, bufferchar, flags, width, precision, size));
}

