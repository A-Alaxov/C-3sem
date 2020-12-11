#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "my_snprintf.h"


START_TEST(test_ordinary)
{
    long long number = 123;
    char num_str[LLD_MAX] = "";

    str_to_lld(num_str, number);
    ck_assert_str_eq(num_str, "123");
}
END_TEST


START_TEST(test_negative_number)
{
    long long number = -123;
    char num_str[LLD_MAX] = "";

    str_to_lld(num_str, number);
    ck_assert_str_eq(num_str, "-123");
}
END_TEST


START_TEST(test_zero_target)
{
    long long number = 0;
    char num_str[LLD_MAX] = "";

    str_to_lld(num_str, number);
    ck_assert_str_eq(num_str, "0");
}
END_TEST


START_TEST(test_max_len)
{
    long long number = -1234567891011121314;
    char num_str[LLD_MAX] = "";

    str_to_lld(num_str, number);
    ck_assert_str_eq(num_str, "-1234567891011121314");
}
END_TEST


Suite* str_to_lld_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("str_to_lld");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ordinary);
    tcase_add_test(tc_pos, test_negative_number);
    tcase_add_test(tc_pos, test_zero_target);
    tcase_add_test(tc_pos, test_max_len);
    suite_add_tcase(s, tc_pos);

    return s;
}
