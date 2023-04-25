#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>


#define EXIT -3
#define END_OF_FILE -2

/* Global environment */
extern char **environ;

/* Global program name */
char *name;

/* Global history counter */
int hist;


/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @char: Character as required
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 *
 * @name: The name of the builtin command.
 *
 * @f: A function pointer to the builtin command's function.
 *
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */

/* Global aliases linked list */
alias_t *aliases;

/* Helpers for Main */
list_t *get_path_dir(char *path);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *get_location(char *command);
char *_itoa(int num);
int execute(char **args, char **front);
void free_list(list_t *head);
char **_strtok(char *line, char *delim);


/* Helpers for Input  */
int handle_args(int *exe_ret);
void handle_line(char **line, ssize_t read);
char **replace_aliases(char **args);
char *get_args(char *line, int *exe_ret);
void variable_replacement(char **args, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int check_args(char **args);
void free_args(char **args, char **front);
int call_args(char **args, char **front, int *exe_ret);

/*  functions for Strings */
char *_strchr(char *s, char c);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);


/* Builtins */
int shellby_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_exit(char **args, char **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);
int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_alias(char **args, char __attribute__((__unused__)) **front);
int shellby_help(char **args, char __attribute__((__unused__)) **front);
int (*get_builtin(char *command))(char **args, char **front);

/* Builtin Helpers */
void free_env(void);
char **_copyenv(void);
char **_getenv(const char *var);

/* Error Handling */
char *error_126(char **args);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
int create_error(char **args, int err);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
char *error_127(char **args);

/* Linkedlist Helpers */
void free_alias_list(alias_t *head);
alias_t *add_alias_end(alias_t **head, char *name, char *value);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

void help_all(void);
void help_alias(void);
void help_history(void);
void help_exit(void);
void help_help(void);
void help_cd(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);


int proc_file_commands(char *file_path, int *exe_ret);
#endif /* _SHELL_H_ */
