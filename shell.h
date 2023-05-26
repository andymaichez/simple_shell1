#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 64
#define PATH_DELIMITERS " \t\n\r\a"

int calculate_triangle_sum(int base, int height);
int is_interactive_mode(void);
void display_prompt(void);
char *read_command(void);
void handle_command(char **args, char *command);
char **parse_arguments(char *command, int *argc);
void execute_command(char **args, char *command);
void run_shell(void);
char *find_command_path(char *dir, char *command);
char *get_full_path(char *directory, char *command);
char *search_in_path(char *command);
void exit_shell(void);
void env_shell(char **environ);

#endif /* SHELL_H */
