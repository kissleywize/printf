#include "main.h"

/**
 *_printf - function thats prints anything.
 * @format: String that contains parametters to print
 * Return: Size of the String printed.
 *
 */

int _printf(const char *format, ...)
{
	va_list print;
	char buffer[2048];
	int chr, bufflen, buffpos, *bufflenptr, *buffposptr;
	print_opc opc[] = {{"c", print_c},
			   {"s", print_s},
			   {"i", print_int},
			   {"d", print_int},
			   {"b", _print_binary},
			   {"u", print_u},
	};

	create_buffer(buffer);
	chr = buffpos = 0;
	bufflen = 1;
	bufflenptr = &bufflen;
	buffposptr = &buffpos;
	va_start(print, format);

	if (format == NULL || print == NULL)
		return (-1);

	chr = to_format(format, print, buffer,
			      bufflenptr, buffposptr, opc);

	write_buffer(buffer, bufflenptr, buffposptr);
	va_end(print);
	return (chr);
}

