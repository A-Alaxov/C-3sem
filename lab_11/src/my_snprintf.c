#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "funcs.h"
#include "my_snprintf.h"

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...)
{
    size_t buf_cur = 0, format_cur = 0;
    char num_str[LLD_MAX + 1] = "", *temp_str = "";
    long long number;

    if ((num) && ((!buf) || (!format)))
    {
        return -1;
    }

    va_list v1;
    va_start(v1, format);

    while (format[format_cur] != '\0')
    {
        if (format[format_cur] == '%')
        {
            if (format[format_cur + 1] == 's')
            {
                temp_str = va_arg(v1, char*);
                if (temp_str)
                {
                    str_put(buf, temp_str, &buf_cur, num);
                }
                else
                {
                    temp_str = "(null)";
                    str_put(buf, temp_str, &buf_cur, num);
                }
                format_cur += 2;
            }
            else if ((format[format_cur + 1] == 'l') && (format[format_cur + 2] == 'l') && (format[format_cur + 3] == 'd'))
            {
                number = va_arg(v1, long long);
                str_to_lld(num_str, number);
                str_put(buf, num_str, &buf_cur, num);
                format_cur += 4;
            }
            else if (format[format_cur + 1] == '%')
            {
                if ((num) && (buf_cur < num - 1))
                {
                    buf[buf_cur] = '%';
                }
                buf_cur++;
                format_cur += 2;
            }
            else
            {
                if ((num) && (buf_cur < num - 1))
                {
                    buf[buf_cur] = '%';
                }
                buf_cur++;
                format_cur++;
            }
        }
        else
        {
            if ((num) && (buf_cur < num - 1))
            {
                buf[buf_cur] = format[format_cur];
            }
            buf_cur++;
            format_cur++;
        }
    }

    va_end(v1);

    if (buf_cur < num)
    {
        buf[buf_cur] = '\0';
    }
    else if (num)
    {
        buf[num] = '\0';
    }
    return buf_cur;
}
