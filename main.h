#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void prompt(void);
void execute_command(char *args[]);
char get_line(char **buffer, size_t *buffer_size);
#endif
