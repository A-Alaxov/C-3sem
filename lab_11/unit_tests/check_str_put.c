#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "my_snprintf.h"


START_TEST(test_ordinary)
{
    size_t buf_cur = 7, num = 10;
    char *temp_str = " 5", buf[50] = "2 * 2 =";

    str_put(buf, temp_str, &buf_cur, num);
    ck_assert_str_eq(buf, "2 * 2 = 5");
    ck_assert_int_eq((int)buf_cur, 9);
}
END_TEST


START_TEST(test_empty_buf)
{
    size_t buf_cur = 0, num = 10;
    char *temp_str = "2 * 2 = 5", buf[50] = "";

    str_put(buf, temp_str, &buf_cur, num);
    ck_assert_str_eq(buf, "2 * 2 = 5");
    ck_assert_int_eq((int)buf_cur, 9);
}
END_TEST


START_TEST(test_empty_temp_str)
{
    size_t buf_cur = 9, num = 10;
    char *temp_str = "", buf[50] = "2 * 2 = 5";

    str_put(buf, temp_str, &buf_cur, num);
    ck_assert_str_eq(buf, "2 * 2 = 5");
    ck_assert_int_eq((int)buf_cur, 9);
}
END_TEST


START_TEST(test_result_str_longer_than_num)
{
    size_t buf_cur = 7, num = 10;
    char *temp_str = " 10", buf[50] = "2 * 5 =";

    str_put(buf, temp_str, &buf_cur, num);
    ck_assert_str_eq(buf, "2 * 5 = 1");
    ck_assert_int_eq((int)buf_cur, 10);
}
END_TEST


Suite* str_put_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("str_put");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ordinary);
    tcase_add_test(tc_pos, test_empty_buf);
    tcase_add_test(tc_pos, test_empty_temp_str);
    tcase_add_test(tc_pos, test_result_str_longer_than_num);
    suite_add_tcase(s, tc_pos);

    return s;
}
