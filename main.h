#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
typedef struct fmt fmt_t;
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list parameters);
int get_precision(const char *format, int *i, va_list parameters);
int get_size(const char *format, int *i);
int _printf(const char *format, ...);
int _putchar(char c);
void print_buffer(char bufferchar[], int *buff_int);
int handle_write_char(char c, char bufferchar[],
			int flags, int width, int precision, int size);
int handle_print(const char *fmt, int *i,
		va_list parameters, char bufferchar[], int flags, int width, int precision, int size);
int is_digit(char);




#endif
