#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>


extern char **environ;
char *READ_LINE(void);
int _EXECUTE(char **COMMAND, char **argv, int IDX);
char **TOKENIZER(char *line);
char *_getenv(char *var);
char *_getpath(char *cmd);

/* =============== STRING.c ================ */
char *my_strdup(const char *str);
int my_strcmp(char *s1, char *s2);
int my_strlen(char *s);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char *src);


/* =========== TOOLS.c ================= */
void FREE2Darr(char **arr);
void printerror(char *name, char *CMD, int IDX);
void reverse_string(char *str, int len);
char *_itoa(int n);

/* =================== builtin_handler.c ============== */
int my_builtin(char *COMMAND);
void builtin_handler(char **COMMAND, char **argv, int *status, int IDX);
void the_shell_exit(char **COMMAND, char **argv, int *status, int IDX);
void theprint_env(char **COMMAND, int *status);

/* ============= 2en_TOOLS.c ============== */
int _atoi(char *str);
int _positive_num(char *str);


#endif /* SHELL_H */
