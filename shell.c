#include "holberton.h"
/**
 * main - This is a simple shell created by Marisol Ramirez Henao and David Alejandro Hincapié
 * for Holberton School
 * Return: 0 if success
*/
int main(void)
{
	ssize_t bytes_read = 0; /** Bytes leídos de un getline*/
	size_t buf_size = 0; /**Tamaño del buffer*/
	char *entry = NULL; /**input ingresado por el usuario*/
	char *arguments[20]; /**String de argumentos que ingresa el usr*/
	int counter = 1;
	int vf_stat = 0;
	int exist_stat = 0;/**Valor de retorno de exist, 0 si existe*/

	_printp("$ ", 2);/**prompt mini-shell*/
	bytes_read = getline(&entry, &buf_size, stdin);
	/**Almacena el input path de nbytes retorna bytes leídos o -1 (EOF))*/
	while (bytes_read != -1)
	{
		if (*entry != '\n')
		{
			fill_args(entry, arguments);
			exist_stat = exist(arguments[0]);/**Exist evalua si path ingresado existe*/
			if (exist_stat != 0)/**No encontró el archivo*/
			{
				vf_stat = verify_path(arguments);
				if (vf_stat == 0)
					exec(arguments);
				else
					print_not_found(entry, counter);
			}
			else /**Encontró el archivo*/
			{
				exec(arguments);
			}
			free(*arguments);
		}
		entry = NULL; /**Reinicializa el puntero, para getline en cada llamado */
		counter++;
		_printp("$ ", 2);/**prompt mini-shell*/
		bytes_read = getline(&entry, &buf_size, stdin);
	}
	_putchar('\n');
	free(entry); /**Libera el ultimo getline para el EOF*/
	return (0);
}
