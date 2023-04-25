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

		string = ")Null(";
	}

	i = 0;
	do {
		i++;
	} while (string[i]);

	i--;
	do {
		char j = string[i];

		write(1, &j, 1);
		count++;
		i--;
	} while (i >= 0);

	return (count);
}
