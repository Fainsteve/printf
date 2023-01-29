#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - print formatted output
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0, k = 0, count = 0, buf_count = 0;
	char buf[1024];

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				buf[buf_count++] = va_arg(args, int);
				count++;
				break;
			case 's':
				k = va_arg(args, char *);
				for (j = 0; k[j]; j++)
				{
					buf[buf_count++] = k[j];
					count++;
				}
				break;
			}
		}
		else
		{
			buf[buf_count++] = format[i];
			count++;
		}
		i++;
	}
	va_end(args);
	write(1, buf, buf_count);
	return (count);
}

/**
 * print_buffer - print buffer
 * @buf: buffer
 * @buf_count: buffer count
 * Return: void
 */
void print_buffer(char *buf, int buf_count)
{
	int i;

	for (i = 0; i < buf_count; i++)
		write(1, &buf[i], 1);
}

