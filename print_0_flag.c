#include "main.h"
/**
 * p_pointer - prints value of pointer's variable
 * @parameters: arguments list
 * @bufferchar: output of buffer array
 * @flags: gets the calculation of active flags
 * @width: gives width
 * @precision: states precision specification
 * @size: gives size
 * Return: printed characters
 */
int p_pointer(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size)
{
	char ext_c = 0, pdd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, pdd_strt = 1;
	unsigned long fig_ads;
	char map_loc[] = "0123456789abcdef";
	void *ads = va_arg(parameters, void *);

	UNUSED(width);
	UNUSED(size);

	if (ads == NULL)
	{
		return (write(1, "(nil)", 5));
	}

	bufferchar[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	fig_ads = (unsigned long)ads;

	for (; fig_ads > 0; fig_ads /= 16)
	{
		bufferchar[ind--] = map_loc[fig_ads % 16];
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pdd = '0';
	if (flags & F_PLUS)
		ext_c = '+', len++;
	else if (flags & F_SPACE)
		ext_c = ' ', len++;

	ind++;
	return (write_pointer(bufferchar, ind, len,
				width, flags, pdd, ext_c, pdd_strt));

}
