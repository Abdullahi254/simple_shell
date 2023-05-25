#include "main.h"
/**
 * get_full_path - get the full path of the executable command
 * @cmd: executable command
 * @tokens: array of PATH tokens
 *
 * Return: full path of executable file
 */
char *get_full_path(char **tokens, char *cmd)
{
	struct stat stat_buf;
	char *pwd = NULL, *buf = NULL;
	size_t size = 0;
	int status, i;

	pwd = getcwd(buf, size);
	if (pwd == NULL)
		return (NULL);

	if (cmd[0] == '/')
		cmd = cmd + 1;

	for (i = 0; tokens[i] != NULL; i++)
	{
		status = chdir(tokens[i]);
		if (status == -1)
		{
			perror("Error ");
			return (NULL);
		}
		status = stat(cmd, &stat_buf);
		if (status == 0)
		{
			chdir(pwd);
			free(pwd);
			return (tokens[i]);
		}
	}
	chdir(pwd);
	free(pwd);
	return (NULL);
}
