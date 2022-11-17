#include "shell.h"

/**
 * interactive - interactive mode
 * @info: param
 *
 * Return: 1 or 0
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_dlm - check
 * @c: params
 * @dlm: params
 * Return: Return: 1 or 0
 */

int is_dlm(char c, char *dlm)
{
    while (*dlm)
        if (*dlm++ == c)
            return (1);
    return (0);
}

/**
 * _isalpha - checks
 * @c: params
 * Return: 1 or 0
 */

int _isalpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 * _atoi - convet
 * @s: params
 * Return: ...
 */

int _atoi(char *s)
{
    int i, sign = 1, flag = 0, out;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
            sign *= -1;

        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        out = -result;
    else
        out = result;

    return (out);
}
