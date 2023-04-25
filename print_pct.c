#include "main.h"
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
