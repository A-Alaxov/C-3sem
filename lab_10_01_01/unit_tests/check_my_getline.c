#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "file_tools.h"
#include "errors.h"


START_TEST(test_ordinary)
{
    FILE *f = fopen("unit_tests/getline_ordinary.txt", "r");

    if (f)
    {
        int read;
        char *str = NULL;

        read = my_getline(&str, f);

        if (!read)
        {
            ck_assert_str_eq(str, "first string");
            ck_assert_int_eq(read, OK);

            free(str);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_one_string)
{
    FILE *f = fopen("unit_tests/getline_one_string.txt", "r");

    if (f)
    {
        int read;
        char *str = NULL;

        read = my_getline(&str, f);

        if (!read)
        {
            ck_assert_str_eq(str, "first string");
            ck_assert_int_eq(read, OK);

            free(str);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_empty_string)
{
    FILE *f = fopen("unit_tests/geltine_empty_string.txt", "r");

    if (f)
    {
        int read;
        char *str = NULL;

        read = my_getline(&str, f);
        ck_assert_int_eq(read, EMPTY_STR);

        fclose(f);
    }
}
END_TEST


Suite* my_getline_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("my_getline");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_empty_string);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ordinary);
    tcase_add_test(tc_pos, test_one_string);
    suite_add_tcase(s, tc_pos);

    return s;
}
