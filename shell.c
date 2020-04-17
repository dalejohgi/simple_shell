#include "holberton.h"
/**
 * main - This is a simple shell created by
 * Marisol Ramirez Henao and David Alejandro Hincapié
 * for Holberton School
 * Return: 0 if success
 */
int main(void)
{
	ssize_t bytes_read = 0; /** Bytes leídos de un getline*/
	size_t buf_size = 0; /**Tamaño del buffer*/
	char *entry = NULL, *arguments[20]; /**String de args que ingresa el usr*/
	int counter = 1, vf_stat = 0, exist_stat = 0, exit_stat = 0;

	if (isatty(STDIN_FILENO))
		_printp("$ ", 2);/**prompt mini-shell*/
	bytes_read = getline(&entry, &buf_size, stdin); /**sizeof entry, o -1 (EOF))*/
	while (bytes_read != -1)
	{
		if (*entry != '\n')
		{
			fill_args(entry, arguments);
			if (arguments[0] != NULL)
			{
				exist_stat = exist(arguments[0]);/**Exist evalua si path ingresado existe*/
				if (exist_stat != 0)/**No encontró el archivo*/
				{
					vf_stat = verify_path(arguments);
					if (vf_stat == 0)
						exit_stat = exec(arguments), free(entry), free(*arguments);
					else
						exit_stat = print_not_found(arguments, counter), free(entry);
				}
				else /**Encontró el archivo*/
					exit_stat = exec(arguments), free(entry);
			}
			else
				free(entry);
		}
		else if (*entry == '\n')
			free(entry);
		entry = NULL, counter++;
		if (isatty(STDIN_FILENO))
			_printp("$ ", 2);/**prompt mini-shell*/
		bytes_read = getline(&entry, &buf_size, stdin);
	}
	last_free(entry); /**Libera el ultimo getline para el EOF*/
	return (exit_stat);
}
