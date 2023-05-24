#include "main.h"
/**
 * print_env - prints environment variables
 * Return: void
 */
void print_env(void)
{
        extern char **env;
        char **local_env;

        local_env = env;
        while (*local_env != NULL)
        {
                printf("%s\n", *local_env);
                local_env++;
        }
}
