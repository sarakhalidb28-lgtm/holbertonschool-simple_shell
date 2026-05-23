#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* Function Prototypes */
char *find_path(char *command);
int handle_builtins(char **args, char *line, int *status);

#endif /* MAIN_H */
