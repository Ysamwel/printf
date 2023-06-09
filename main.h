#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define UNUSED(x) (void)(x)
#define LONG 2
#define SHORT 1

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
/**
 * struct fmt - struct op
 * @fmt: format
 * @fn: associated function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
typedef struct fmt fmt_t;
int fetch_flags(const char *format, int *i);
int fetch_width(const char *format, int *i, va_list parameters);
int fetch_precision(const char *format, int *i, va_list parameters);
int fetch_size(const char *format, int *i);
int _printf(const char *format, ...);
int _putchar(char c);
void print_buffer(char bufferchar[], int *buff_int);
int handle_write_char(char c, char bufferchar[],
		int flags, int width, int precision, int size);
int handle_print(const char *fmt, int *i,
		va_list parameters, char bufferchar[], int flags,
		int width, int precision, int size);
int is_figure(char);
int print_characters(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int print_str(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int print_pct(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int print_int(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int print_binary(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int print_unsigned_int(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int print_octal(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int p_hexadecimal(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int print_hexa_upp(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);

int print_hexa(va_list parameters, char map_loc[],
		char bufferchar[], int flags, char flag_ch,
		int width, int precision, int size);
int p_rot13str(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int p_reverse(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int p_pointer(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int p_non_print(va_list parameters, char bufferchar[],
		int flags, int width, int precision, int size);
int handle_write_char(char c, char bufferchar[],
		int flags, int width, int precision, int size);
int write_number(int is_negative, int ind, char bufferchar[],
		int flags, int width, int precision, int size);
int write_num(int ind, char bufferchar[],
		int flags, int width, int precision,
		int len, char padd, char ext_c);
int write_unsign(int is_negative, int ind,
		char bufferchar[],
		int flags, int width, int precision, int size);
int write_pointer(char bufferchar[], int ind, int len,
		int width, int flags, char padd, char ext_c, int padding_start);
int is_print(char c);
int app_hex_code(char ascii_code, char bufferchar[], int i);
int is_figure(char c);
long int cnvt_size_int(long int fig, int size);
int is_figure(char c);
long int cnvt_size_int(long int fig, int size);
long int cnvt_size_unsign(unsigned long int fig, int size);
#endif
