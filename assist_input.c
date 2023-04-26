#include "carp.h"

char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);

/**
 * get_args - Gets a command from standard input.
 * @line: A buffer to store the command.
 * @exe_ret: The return value of the last executed command.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the stored command.
 */
char *get_args(char *line, int *exe_ret)
{
    size_t n = 0;
    ssize_t read;
    char *prompt = "$ ";

    if (line)
        free(line);

    read = _getline(&line, &n, STDIN_FILENO);
    if (read == -1)
        return (NULL);
    if (read == 1)
    {
        hist++;
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, prompt, 2);
        return (get_args(line, exe_ret));
    }

    line[read - 1] = '\0';
    variable_replacement(&line, exe_ret);
    handle_line(&line, read);

    return (line);
}

/**
 * call_args - Partitions operators from commands and calls them.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 * @exe_ret: The return value of the parent process' last executed command.
 *
 * Return: The return value of the last executed command.
 */
int call_args(char **args, char **front, int *exe_ret)
{
    int ret, index;

    if (!args[0])
        return (*exe_ret);
    for (index = 0; args[index]; index++)
    {
        if (_strncmp(args[index], "||", 2) == 0)
        {
            free(args[index]);
            args[index] = NULL;
            args = replace_aliases(args);
            ret = run_args(args, front, exe_ret);
            if (*exe_ret != 0)
            {
                args = &args[++index];
                index = 0;
            }
            else
            {
                for (index++; args[index]; index++)
                    free(args[index]);
                return (ret);
            }
        }
        else if (_strncmp(args[index], "&&", 2) == 0)
        {
            free(args[index]);
            args[index] = NULL;
            args = replace_aliases(args);
            ret = run_args(args, front, exe_ret);
            if (*exe_ret == 0)
            {
                args = &args[++index];
                index = 0;
            }
            else
            {
                for (index++; args[index]; index++)
                    free(args[index]);
                return (ret);
            }
        }
    }
    args = replace_aliases(args);
    ret = run_args(args, front, exe_ret);
    return (ret);
}

/**
 * run_args - Calls the execution of a command.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 * @exe_ret: The return value of the parent process' last executed command.
 *
 * Return: The return value of the last executed command.
 */
int run_args(char **args, char **front, int *exe_ret)
{
    int ret, i;
    int (*builtin)(char **args, char **front);

    builtin = get_builtin(args[0]);

    if (builtin)
    {
        ret = builtin(args + 1, front);
        if

