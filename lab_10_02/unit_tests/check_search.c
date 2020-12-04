#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "tools.h"
#include "errors.h"


START_TEST(test_one_el)
{
    int rc = OK, pos;
    node_t *head = NULL, *head_2 = NULL;
    FILE *f = fopen("unit_tests/search_one_el.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&head_2, f))
            {
                rc = search(head, head_2, &pos);

                ck_assert_int_eq(rc, OK);
                ck_assert_int_eq(pos, 0);

                free(head_2);
            }
            free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_zero_pos)
{
    int rc = OK, pos;
    node_t *head = NULL, *head_2 = NULL;
    FILE *f = fopen("unit_tests/search_zero_pos.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&head_2, f))
            {
                rc = search(head, head_2, &pos);

                ck_assert_int_eq(rc, OK);
                ck_assert_int_eq(pos, 0);

                free(head_2);
            }
            free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_last_pos)
{
    int rc = OK, pos;
    node_t *head = NULL, *head_2 = NULL;
    FILE *f = fopen("unit_tests/search_last_pos.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&head_2, f))
            {
                rc = search(head, head_2, &pos);

                ck_assert_int_eq(rc, OK);
                ck_assert_int_eq(pos, 12);

                free(head_2);
            }
            free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_long_target)
{
    int rc = OK, pos;
    node_t *head = NULL, *head_2 = NULL;
    FILE *f = fopen("unit_tests/search_long_target.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&head_2, f))
            {
                rc = search(head, head_2, &pos);

                ck_assert_int_eq(rc, OK);
                ck_assert_int_eq(pos, 2);

                free(head_2);
            }
            free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_not_found)
{
    int rc = OK, pos;
    node_t *head = NULL, *head_2 = NULL;
    FILE *f = fopen("unit_tests/search_not_found.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&head_2, f))
            {
                rc = search(head, head_2, &pos);

                ck_assert_int_eq(rc, NOT_FOUND);

                free(head_2);
            }
            free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_empty_str)
{
    int rc = OK, pos;
    node_t *head = NULL, *head_2 = NULL;
    FILE *f = fopen("unit_tests/search_last_pos.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            rc = search(head, head_2, &pos);

            ck_assert_int_eq(rc, EMPTY_STR);

            free(head);
        }
        fclose(f);
    }
}
END_TEST


Suite* search_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("search");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_not_found);
    tcase_add_test(tc_neg, test_empty_str);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_one_el);
    tcase_add_test(tc_pos, test_zero_pos);
    tcase_add_test(tc_pos, test_last_pos);
    tcase_add_test(tc_pos, test_long_target);
    suite_add_tcase(s, tc_pos);

    return s;
}
