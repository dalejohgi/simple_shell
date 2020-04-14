#include "holberton.h"
/**
 * verify_path - Verify if the first command can be executed
 * @arguments: Array of entries by the user
 * Return: 0 if success, or -1 if the exe file doesn't exist
 */
int verify_path(char **arguments)
{
	char *global_path = NULL; /**"/usr/bin:/bin:/usr/games:/usr/local/games"*/
	char *global_dup = NULL;
	char *dir_path = NULL; /**"   /usr/bin    "*/
	char *command_path = NULL; /**"   /usr/bin/touch      "*/
	int exist_stat = -1;

	global_path = _getenv("PATH");
	global_dup = (_strdup(global_path));
	dir_path = strtok(global_dup, ":");
	free(global_path);
	while (exist_stat == -1 && dir_path != NULL)
	{
		command_path = append_command(dir_path, arguments[0]);
		exist_stat = exist(command_path);
		dir_path = strtok(NULL, ":");
	}
	free(global_dup);
	if (exist_stat == 0)
	{
		arguments[0] = command_path;
		return (0);
	}
	return (-1);
}
