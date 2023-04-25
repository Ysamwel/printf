#include "main.h"

/**
 * fetch_flags - gives the sum of flags
 * @format: sring where argument is printed
 * @i: take a parameter.
 * Return: flags
 */
int fetch_flags(const char *format, int *i)
{
	int j, curr;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	curr = *i + 1;
	while (format[curr] != '\0')
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
		{
			if (format[curr] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}

		if (FLAGS_CH[j] == '\0')
			break;

		curr++;
	}

	*i = curr - 1;

	return (flags);
}
