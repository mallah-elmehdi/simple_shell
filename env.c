#include "shell.h"

/**
 * _env - env
 * @info: params
 * Return: ...
 */
int _env(info_t *info)
{
    print_list_str(info->env);
    return (0);
}

/**
 * _getenv - getenv()
 * @info: params
 * @name: params
 *
 * Return: ...
 */
char *_getenv(info_t *info, const char *name)
{
    list_t *node = info->env;
    char *p;

    while (node)
    {
        p = begin_with(node->str, name);
        if (p && *p)
            return (p);
        node = node->next;
    }
    return (NULL);
}

/**
 * set_env - set an env
 * @info: params
 *  Return: ...
 */
int set_env(info_t *info)
{
    if (info->argc != 3)
    {
        _error_puts("Incorrect number of arguements\n");
        return (1);
    }
    if (_setenv(info, info->argv[1], info->argv[2]))
        return (0);
    return (1);
}

/**
 * unset_env - unset
 * @info: params
 *  Return: ...
 */

int unset_env(info_t *info)
{
    int i;

    if (info->argc == 1)
    {
        _error_puts("Too few arguements.\n");
        return (1);
    }
    for (i = 1; i <= info->argc; i++)
        _unsetenv(info, info->argv[i]);

    return (0);
}

/**
 * show_env_list - show
 * @info: params
 * Return: ...
 */
int show_env_list(info_t *info)
{
    list_t *node = NULL;
    size_t i;

    for (i = 0; environ[i]; i++)
        add_node_end(&node, environ[i], 0);
    info->env = node;
    return (0);
}
