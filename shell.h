#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 64
#define PATH_DELIMITER

int is_interactive_mode(void);
void display_prompt(void);
char **parse_arguments(char *command, int *argc);
void execute_command(char **args);
void run_shell(void);
char *find_command_path(char *command);
char *get_full_path(char *directory, char *command);
char *search_in_path(char *command);
void exit_shell(void);
void env_shell(void);

#endif /* SHELL_H */
