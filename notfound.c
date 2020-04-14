#include "holberton.h"
/**
 * print_not_found - Prints error message when a command is not found
 * @entry: input by the user
 * @counter: Times that the shell has been executed
 */

void print_not_found(char *entry, int counter)
{
	char *shell_name = "hsh";

	write(2, shell_name, 3);
	write(2, ": ", 2);
	print_numbers(counter);
	write(2, ": ", 2);
	write(2, entry, _strlen(entry));
	write(2, ": not found\n", 12);
}
