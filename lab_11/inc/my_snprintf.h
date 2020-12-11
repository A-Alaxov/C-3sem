#ifndef MY_SNPRINTF_H
#define MY_SNPRINTF_H

#define LLD_MAX 20

#define OK 0
#define NULL_STR -1

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...);

#endif // MY_SNPRINTF_H
