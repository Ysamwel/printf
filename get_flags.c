#include "main.h"

/**
 * get_flags - gives the sum of flags
 * @format: sring where argument is printed
 * @i: take a parameter.
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr = *i + 1; format[curr] != '\0'; curr++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr - 1;

	return (flags);
}
