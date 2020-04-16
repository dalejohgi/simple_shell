#include "holberton.h"
/**
 * print_not_found - Prints error message when a command is not found
 * @entry: input by the user
 * @counter: Times that the shell has been executed
 */
void print_not_found(char *entry, int counter)
{
	char *imode_shell_name = "hsh";
	char *non_i_mode_shell_name = "./hsh";

	if (isatty(fileno(stdin)))
		write(2, imode_shell_name, 3);
	else
	{
		write(2, non_i_mode_shell_name, 5);
	}
	write(2, ": ", 2);
	print_numbers(counter);
	write(2, ": ", 2);
	write(2, entry, _strlen(entry));
	write(2, ": not found\n", 12);
}
