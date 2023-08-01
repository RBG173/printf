#include "main.h"

/**
 * get_precision - Calculates the precision for printing.
 * @format: The formatted string in which to print the arguments.
 * @i: Pointer to the current index in the formatted string.
 * @args_list: The list of arguments.
 *
 * Return: The calculated precision, or -1 if not found.
 */
int get_precision(const char *format, int *i, va_list args_list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	/* Initialize precision with 0 */
	precision = 0;

	/* Calculate the precision value */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			/* Convert digit characters to the integer value */
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			/* Get precision from the variadic argument list */
			precision = va_arg(args_list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
