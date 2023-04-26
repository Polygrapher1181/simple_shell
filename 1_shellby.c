#include "carp.h"

/**
 * help_all - Displays all possible builtin shellby commands.
 */
void help_all(void)
{
	char *msg = "Shellby\nThese shell commands are defined internally.\n"
		"Type 'help' to see this list.\nType 'help name' to find "
		"out more about the function 'name'.\n\n"
		"  alias    \talias [NAME[='VALUE'] ...]\n"
		"  cd       \tcd [DIRECTORY]\n"
		"  exit     \texit [STATUS]\n"
		"  env      \tenv\n"
		"  setenv   \tsetenv [VARIABLE] [VALUE]\n"
		"  unsetenv \tunsetenv [VARIABLE]\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_alias - Displays information on the shellby builtin command 'alias'.
 */
void help_alias(void)
{
	char *msg = "alias: alias [NAME[='VALUE'] ...]\n"
		"\tHandles aliases.\n\n"
		"\talias: Prints a list of all aliases, one per line, in "
		"the format NAME='VALUE'.\n"
		"\talias name [name2 ...]: prints the aliases name, name2, etc. "
		"one per line, in the form NAME='VALUE'.\n"
		"\talias NAME='VALUE' [...]: Defines an alias for each NAME whose "
		"VALUE is given. If NAME is already an alias, replace its value with "
		"VALUE.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_cd - Displays information on the shellby builtin command 'cd'.
 */
void help_cd(void)
{
	char *msg = "cd: cd [DIRECTORY]\n"
		"\tChanges the current directory of the process to DIRECTORY.\n\n"
		"\tIf no argument is given, the command is interpreted as cd $HOME. "
		"If the argument '-' is given, the command is interpreted as cd $OLDPWD.\n\n"
		"\tThe environment variables PWD and OLDPWD are updated after a change of directory.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_exit - Displays information on the shellby builtin command 'exit'.
 */
void help_exit(void)
{
	char *msg = "exit: exit [STATUS]\n"
		"\tExits the shell.\n\n"
		"\tThe STATUS argument is the integer used to exit the shell. "
		"If no argument is given, the command is interpreted as exit 0.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_help - Displays information on the shellby builtin command 'help'.
 */
void help_help(void)
{
	char *msg = "help: help\n"
		"\tSee all possible Shellby builtin commands.\n\n"
		"\thelp [BUILTIN NAME]\n"
		"\tSee specific information on each builtin command.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}
