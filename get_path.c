#include "main.h"

/**
 * get_path - get the path and check if the executable exists
 * @cmd: executable command
 * Return: full path of executabe file
 */
char *get_path(char *cmd)
{
	char **pathtoks = NULL;
	char *str = NULL;
	char *e_path = NULL, *cmd_path = NULL;

	pathtoks = tokens_converter(str);
	if (pathtoks == NULL)
		return (NULL);

	e_path = _exec_path(pathtoks, cmd);
	if (e_path == NULL)
	{
		custom_free(pathtoks);
		return (NULL);
	}

	cmd_path = path_builder(e_path, cmd);
	if (cmd_path == NULL)
	{
		custom_free(pathtoks);
		return (NULL);
	}

	custom_free(pathtoks);
	return (cmd_path);
}
