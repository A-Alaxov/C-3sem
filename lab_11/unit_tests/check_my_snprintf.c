#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "my_snprintf.h"


START_TEST(test_ordinary)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "", *str_in1 = "eleven", *str_in2 = "eleven";
    long long num1 = 11, num2 = 11;

    len1 = my_snprintf(str1, 50, "Number %s is %lld for sure", str_in1, num1);
    len2 = snprintf(str2, 50, "Number %s is %lld for sure", str_in2, num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_specifier_at_begin_of_format)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "", *str_in1 = "eleven", *str_in2 = "eleven";
    long long num1 = 11, num2 = 11;

    len1 = my_snprintf(str1, 50, "%s is %lld for sure", str_in1, num1);
    len2 = snprintf(str2, 50, "%s is %lld for sure", str_in2, num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_specifier_at_end_of_format)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "", *str_in1 = "eleven", *str_in2 = "eleven";
    long long num1 = 11, num2 = 11;

    len1 = my_snprintf(str1, 50, "Number %s is %lld", str_in1, num1);
    len2 = snprintf(str2, 50, "Number %s is %lld", str_in2, num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_two_specifiers_in_succession)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "", *str_in1 = "eleven", *str_in2 = "eleven";
    long long num1 = 11, num2 = 11;

    len1 = my_snprintf(str1, 50, "Number %s%lld for sure", str_in1, num1);
    len2 = snprintf(str2, 50, "Number %s%lld for sure", str_in2, num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_percent_without_specifier)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "";
    long long num1 = 11, num2 = 11;

    len1 = my_snprintf(str1, 50, "Number %y is %lld for sure", num1);
    len2 = snprintf(str2, 50, "Number %y is %lld for sure", num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_percent_specifier)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "";
    long long num1 = 11, num2 = 11;

    len1 = my_snprintf(str1, 50, "Number %% is %lld for sure", num1);
    len2 = snprintf(str2, 50, "Number %% is %lld for sure", num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_only_specifier)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "", *str_in1 = "eleven", *str_in2 = "eleven";

    len1 = my_snprintf(str1, 50, "%s", str_in1);
    len2 = snprintf(str2, 50, "%s", str_in2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_num_is_less_than_final_str)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "", *str_in1 = "eleven", *str_in2 = "eleven";
    long long num1 = 11, num2 = 11;

    len1 = my_snprintf(str1, 10, "Number %s is %lld for sure", str_in1, num1);
    len2 = snprintf(str2, 10, "Number %s is %lld for sure", str_in2, num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_empty_format)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "", *str_in1 = "eleven", *str_in2 = "eleven";
    long long num1 = 11, num2 = 11;

    len1 = my_snprintf(str1, 50, "", str_in1, num1);
    len2 = snprintf(str2, 50, "", str_in2, num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_zero_num)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "", *str_in1 = "eleven", *str_in2 = "eleven";
    long long num1 = 11, num2 = 11;

    len1 = my_snprintf(str1, 0, "Number %s is %lld for sure", str_in1, num1);
    len2 = snprintf(str2, 0, "Number %s is %lld for sure", str_in2, num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_null_str)
{
    int len1;
    char *str1 = NULL, *str_in1 = "eleven";
    long long num1 = 11;

    len1 = my_snprintf(str1, 50, "Number %s is %lld for sure", str_in1, num1);

    ck_assert_int_eq(len1, -1);
    ck_assert_ptr_eq(str1, NULL);
}
END_TEST


START_TEST(test_null_str_and_zero_num)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "", *str_in1 = "eleven", *str_in2 = "eleven";
    long long num1 = 11, num2 = 11;

    len1 = my_snprintf(NULL, 0, "Number %s is %lld for sure", str_in1, num1);
    len2 = snprintf(NULL, 0, "Number %s is %lld for sure", str_in2, num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(test_null_format)
{
    int len1;
    char str1[50] = "", *str_in1 = "eleven";
    long long num1 = 11;

    len1 = my_snprintf(str1, 50, NULL, str_in1, num1);

    ck_assert_int_eq(len1, -1);
    ck_assert_str_eq(str1, "");
}
END_TEST


START_TEST(test_number_max_len)
{
    int len1, len2;
    char str1[50] = "", str2[50] = "", *str_in1 = NULL, *str_in2 = NULL;
    long long num1 = -1234567891011121314, num2 = -1234567891011121314;

    len1 = my_snprintf(str1, 50, "Number %s is %lld for sure", str_in1, num1);
    len2 = snprintf(str2, 50, "Number %s is %lld for sure", str_in2, num2);

    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(str1, str2);
}
END_TEST


Suite* my_snprintf_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("my_snprintf");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_null_str);
    tcase_add_test(tc_neg, test_null_str_and_zero_num);
    tcase_add_test(tc_neg, test_null_format);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ordinary);
    tcase_add_test(tc_pos, test_specifier_at_begin_of_format);
    tcase_add_test(tc_pos, test_specifier_at_end_of_format);
    tcase_add_test(tc_pos, test_two_specifiers_in_succession);
    tcase_add_test(tc_pos, test_percent_without_specifier);
    tcase_add_test(tc_pos, test_percent_specifier);
    tcase_add_test(tc_pos, test_only_specifier);
    tcase_add_test(tc_pos, test_num_is_less_than_final_str);
    tcase_add_test(tc_pos, test_empty_format);
    tcase_add_test(tc_pos, test_zero_num);
    tcase_add_test(tc_pos, test_number_max_len);
    suite_add_tcase(s, tc_pos);

    return s;
}
