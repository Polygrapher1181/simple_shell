#include "carp.h"

/**
 * help_env - Displays information on the shellby builtin command 'env'.
 */
void help_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_setenv - Displays information on the shellby builtin command 'setenv'.
 */
void help_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new ";
	char *msg2 = "environment variable, or modifies an existing one.\n\n";
	char *msg3 = "\tUpon failure, prints a message to stderr.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	write(STDOUT_FILENO, msg2, _strlen(msg2));
	write(STDOUT_FILENO, msg3, _strlen(msg3));
}

/**
 * help_unsetenv - Displays information on the shellby builtin command 'unsetenv'.
 */
void help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";
	char *msg2 = "environmental variable.\n\n\tUpon failure, prints a ";
	char *msg3 = "message to stderr.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	write(STDOUT_FILENO, msg2, _strlen(msg2));
	write(STDOUT_FILENO, msg3, _strlen(msg3));
}

