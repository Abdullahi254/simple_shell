#include "main.h"
/**
 * path_builder - builds and executable path from command
 * @exec_path: path of the executable command
 * @cmd: the actual executable command
 * Return: full executable path of the command or NULL
 */
char *path_builder(char *exec_path, char *cmd)
{
	int size = 0;
	int i;
	char *path = NULL;

	if (exec_path == NULL || cmd == NULL)
		return (NULL);
	size = _strlen(exec_path) + _strlen(cmd) + 2;
	path = malloc(sizeof(char *) * size);
	if (path == NULL)
		return (NULL);
	_strcpy(path, exec_path);
	_strcat(path, "/");
	_strcat(path, cmd);
	_strcat(path, "\0");
	return (path);
}
