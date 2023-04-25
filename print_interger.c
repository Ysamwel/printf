#include "main.h"
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

	j = cnvt_size_int(j, size);

	if (j == 0)
		bufferchar[i--] = '0';

	bufferchar[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)j;

	if (j < 0)
	{
		num = (unsigned long int)((-1) * j);
		is_negative = 1;
	}

	for (; j > 0; j /= 10)
	{
		bufferchar[i--] = (num % 10) + '0';
	}

	i++;

	return (write_number(is_negative, i, bufferchar,
				flags, width, precision, size));
}
