#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "tools.h"
#include "errors.h"


START_TEST(test_ordinary)
{
    node_t *head = NULL, *res = NULL, *cur1, *cur2;
    FILE *f = fopen("unit_tests/remove_duplicates_ordinary.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&res, f))
            {
                remove_duplicates(head);

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


START_TEST(test_spaces_at_start)
{
    node_t *head = NULL, *res = NULL, *cur1, *cur2;
    FILE *f = fopen("unit_tests/remove_duplicates_start.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&res, f))
            {
                remove_duplicates(head);

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


START_TEST(test_spaces_at_end)
{
    node_t *head = NULL, *res = NULL, *cur1, *cur2;
    FILE *f = fopen("unit_tests/remove_duplicates_end.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&res, f))
            {
                remove_duplicates(head);

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


START_TEST(test_spaces_between_nodes)
{
    node_t *head = NULL, *res = NULL, *cur1, *cur2;
    FILE *f = fopen("unit_tests/remove_duplicates_between.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&res, f))
            {
                remove_duplicates(head);

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


START_TEST(test_str_max_spaces)
{
    node_t *head = NULL, *res = NULL, *cur1, *cur2;
    FILE *f = fopen("unit_tests/remove_duplicates_str_max.txt", "r");

    if (f)
    {
        if (!list_create(&head, f))
        {
            if (!list_create(&res, f))
            {
                remove_duplicates(head);

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


Suite* remove_duplicates_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("remove_duplicates");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ordinary);
    tcase_add_test(tc_pos, test_spaces_at_start);
    tcase_add_test(tc_pos, test_spaces_at_end);
    tcase_add_test(tc_pos, test_spaces_between_nodes);
    tcase_add_test(tc_pos, test_str_max_spaces);
    suite_add_tcase(s, tc_pos);

    return s;
}
