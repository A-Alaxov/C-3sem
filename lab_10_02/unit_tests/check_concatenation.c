#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "tools.h"
#include "errors.h"


START_TEST(test_ordinary)
{
    node_t *head = NULL, *head_2 = NULL, *res = NULL, *cur1, *cur2;
    FILE *f = fopen("unit_tests/concatenation_ordinary.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&head_2, f))
            {
                if (!list_create(&res, f))
                {
                    head = concatenation(head, &head_2);

                    cur1 = head;
                    cur2 = res;
                    while ((cur1) && (cur2))
                    {
                        ck_assert_str_eq(cur1->str, cur2->str);
                        cur1 = cur1->next;
                        cur2 = cur2->next;
                    }

                    free(res);
                }
                free(head_2);
            }
            free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_not_full_first)
{
    node_t *head = NULL, *head_2 = NULL, *res = NULL, *cur1, *cur2;
    FILE *f = fopen("unit_tests/concatenation_not_full_first.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&head_2, f))
            {
                if (!list_create(&res, f))
                {
                    head = concatenation(head, &head_2);

                    cur1 = head;
                    cur2 = res;
                    while ((cur1) && (cur2))
                    {
                        ck_assert_str_eq(cur1->str, cur2->str);
                        cur1 = cur1->next;
                        cur2 = cur2->next;
                    }

                    free(res);
                }
                free(head_2);
            }
            free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_first_null)
{
    node_t *head = NULL, *head_2 = NULL, *res = NULL, *cur1, *cur2;
    FILE *f = fopen("unit_tests/concatenation_null.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&res, f))
            {
                head = concatenation(head, &head_2);

                cur1 = head;
                cur2 = res;
                while ((cur1) && (cur2))
                {
                    ck_assert_str_eq(cur1->str, cur2->str);
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }

                free(res);
            }
            free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_second_null)
{
    node_t *head = NULL, *head_2 = NULL, *res = NULL, *cur1, *cur2;
    FILE *f = fopen("unit_tests/concatenation_null.txt", "r");

    if (f)
    {
        if (!list_create(&head_2, f))
        {
            if (!list_create(&res, f))
            {
                head = concatenation(head, &head_2);

                cur1 = head;
                cur2 = res;
                while ((cur1) && (cur2))
                {
                    ck_assert_str_eq(cur1->str, cur2->str);
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }

                free(res);
            }
            free(head_2);
        }
        fclose(f);
    }
}
END_TEST


Suite* concatenation_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("concatenation");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ordinary);
    tcase_add_test(tc_pos, test_not_full_first);
    tcase_add_test(tc_pos, test_first_null);
    tcase_add_test(tc_pos, test_second_null);
    suite_add_tcase(s, tc_pos);

    return s;
}
