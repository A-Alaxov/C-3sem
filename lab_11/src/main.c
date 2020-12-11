#include <stdio.h>
#include <stdlib.h>
#include "my_snprintf.h"

int main()
{
    int len;
    char str[50] = "";
    long long num = -1234567891011121314;
    len = my_snprintf(str, 40, "Number %s is %lld for sure", "five", num);
    printf("len = %d, str = %s\n\n", len, str);

    len = snprintf(str, 40, "Number %s is %lld for sure", "five", num);
    printf("len = %d, str = %s", len, str);
    return 0;
}
