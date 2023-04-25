#include "main.h"
/**
 * fetch_width - calculates
 * @format: formatted string
 * @i: arguments to be printed
 * @parameters: argument list
 * Return: the width.
 */
int fetch_width(const char *format, int *i, va_list parameters)
{
	int curr = *i + 1;
	int width = 0;

	while (format[curr] != '\0')
	{
		if (is_figure(format[curr]))
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
		{
			break;
		}
		curr++;
	}

	*i = curr - 1;

	return (width);
}
