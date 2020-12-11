#include <stdio.h>
#include <stdlib.h>


void str_to_lld(char *str, long long num)
{
    int cur = 0, flag = 0;
    char symb;

    if (num < 0)
    {
        num *= -1;
        flag = 1;
    }

    if (!num)
    {
        str[cur] = num % 10 + '0';
        cur++;
    }

    while (num > 0)
    {
        str[cur] = num % 10 + '0';
        cur++;
        num /= 10;
    }

    if (flag)
    {
        str[cur] = '-';
        cur++;
    }
    str[cur] = '\0';

    for (int i = 0; i < cur / 2; i++)
    {
        symb = str[i];
        str[i] = str[cur - i - 1];
        str[cur - i - 1] = symb;
    }
}

void str_put(char *buf, char *str, size_t *buf_cur, size_t num)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ((num) && (*buf_cur < num - 1))
        {
            buf[*buf_cur] = str[i];
        }
        i++;
        (*buf_cur)++;
    }
}
