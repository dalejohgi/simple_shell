#include "holberton.h"
/**
 * exec - Creates a new child process,
 * executes a command and wait for the child process
 * to update the status
 * @arguments: Array of inputs by the user
 * Return: 0 if success
 */
int exec(char **arguments)
{
	pid_t pid = 0;/**Child process id*/
	int stat = 0;/**indica el status del child process*/

	pid = fork();/**Crea un proceso hijo*/
	if (pid == -1)/**Falló al crear*/
		_printp("failed\n", 7);
	else if (pid == 0)/**Es el hijo...*/
	{
		execve(arguments[0], arguments, environ);/**Ejecuta el comando*/
		exit(1);/**Terminar el child process con exito*/
	}
	else /**Es el padre*/
		wait(&stat);/**Detiene la ejecución del padre hasta que el child termine*/
	return (0);
}
