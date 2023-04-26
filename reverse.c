#include "main.h"
/**
 * p_reverse - prints reverse string.
 * @parameters: the arguments
 * @bufferchar: array output is printed here
 * @flags:  takes calculatin of active flags
 * @width: gives width
 * @precision: specifics of precision
 * @size: states the size
 * Return: printed characters
 */
int p_reverse(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	char *string;
	int i, count = 0;

	UNUSED(flags);
	UNUSED(bufferchar);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	string = va_arg(parameters, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")Null(";
	}
	for (i = 0; string[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = string[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
