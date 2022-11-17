#include "shell.h"

/**
 * _history - displays the history
 * @info: params
 *  Return: ...
 */

int _history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_an_alias - sets alias
 * @info: params
 * @str: params
 *
 * Return: ...
 */

int unset_an_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = dlt_nd_by_idx(&(info->alias),
						get_nd_by_idx(info->alias, nd_bgn_wt(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_an_alias - sets alias to string
 * @info: params
 * @str: params
 *
 * Return: ...
 */
int set_an_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_an_alias(info, str));

	unset_an_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_an_alias - prints an alias string
 * @node: params
 *
 * Return: Always 0 on success, 1 on error
 */
int print_an_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _alias - alias
 * @info: params
 *  Return: ...
 */

int _alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_an_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_an_alias(info, info->argv[i]);
		else
			print_an_alias(nd_bgn_wt(info->alias, info->argv[i], '='));
	}

	return (0);
}
