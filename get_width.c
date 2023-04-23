#include "main.h"

/**
 * get_width - calculates
 * @format: formatted string
 * @i: arguments to be printed
 * @parameters: argument list
 * Return: the width.
 */
int get_width(const char *format, int *i, va_list parameters)
{
	int curr;
	int width = 0;

	for (curr = *i + 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			width *= 10;
			width += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			width = va_arg(parameters, int);
			break;
		}
		else
			break;
	}

	*i = curr - 1;

	return (width);
}
