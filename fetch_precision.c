#include "main.h"
/**
 * fetch_precision - precision for printing
 * @format:  prints the arguments
 * @i:arguments to be printed.
 * @parameters: list of arguments.
 * Return: precision
 */
int fetch_precision(const char *format, int *i, va_list parameters)
{
	int curr = *i + 1;
	int precision = -1;

	if (format[curr] != '.')
		return (precision);

	precision = 0;
	curr++;

	while (format[curr] != '\0')
	{
		if (is_figure(fmt[curr]))
		{
			precision *= 10;
			precision += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			precision = va_arg(parameters, int);
			break;
		}
		else
		{
			break;
		}
		curr++;
	}

	*i = curr - 1;

	return (precision);
}

