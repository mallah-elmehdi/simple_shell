#include "shell.h"

/**
 * init - init
 * @info: param
 *
 * Return: vvoid
 */

void init(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
	info->line_count = 0;
	info->error_num = 0;
	info->linecount_flag = 0;
	info->fname = NULL;
	info->env = NULL;
	info->history = NULL;
	info->alias = NULL;
	info->environ = NULL;
	info->env_changed = 0;
	info->status = 0;
	info->cmd_buf = NULL;
	info->cmd_buf_type = 0;
	info->readfd = 0;
	info->histcount = 0;
}

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t *info = NULL;
	int fd = 2;

	init(info);
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_error_puts(av[0]);
				_error_puts(": 0: Can't open ");
				_error_puts(av[1]);
				_error_putchar('\n');
				_error_putchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	show_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
