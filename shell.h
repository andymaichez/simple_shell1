#ifndef SHELL_H
#define SHELL_H

double calculate_triangle_sum(double base, double height);
int is_interactive_mode(void);
void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
void run_shell(void);

#endif /* SHELL_H */
