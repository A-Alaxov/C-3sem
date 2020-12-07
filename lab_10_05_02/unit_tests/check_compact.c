#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "task.h"
#include "tools.h"
#include "list_tools.h"
#include "errors.h"


START_TEST(test_ordinary)
{
    node_t *head = NULL, *res = NULL, *cur1, *cur2, *node;
    FILE *f = fopen("unit_tests/comapct.txt", "r");

    if (f)
    {
        node = node_create("He");
        if (node)
        {
            head = list_add_end(head, node);
            node = node_create(" run");
            if (node)
            {
                head = list_add_end(head, node);

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

                    list_free(res);
                }
            }
            list_free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_nothing_changes)
{
    node_t *head = NULL, *res = NULL, *cur1, *cur2, *node;
    FILE *f = fopen("unit_tests/comapct.txt", "r");

    if (f)
    {
        node = node_create("He r");
        if (node)
        {
            head = list_add_end(head, node);
            node = node_create("un");
            if (node)
            {
                head = list_add_end(head, node);

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

                    list_free(res);
                }
            }
            list_free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_first_empty)
{
    node_t *head = NULL, *res = NULL, *cur1, *cur2, *node;
    FILE *f = fopen("unit_tests/comapct.txt", "r");

    if (f)
    {
        node = node_create("");
        if (node)
        {
            head = list_add_end(head, node);
            node = node_create("He r");
            if (node)
            {
                head = list_add_end(head, node);
                node = node_create("un");
                if (node)
                {
                    head = list_add_end(head, node);

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

                        list_free(res);
                    }
                }
            }
            list_free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_empty_part)
{
    node_t *head = NULL, *res = NULL, *cur1, *cur2, *node;
    FILE *f = fopen("unit_tests/comapct.txt", "r");

    if (f)
    {
        node = node_create("He r");
        if (node)
        {
            head = list_add_end(head, node);
            node = node_create("");
            if (node)
            {
                head = list_add_end(head, node);
                node = node_create("un");
                if (node)
                {
                    head = list_add_end(head, node);

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

                        list_free(res);
                    }
                }
            }
            list_free(head);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_deletion_of_part)
{
    node_t *head = NULL, *res = NULL, *cur1, *cur2, *node;
    FILE *f = fopen("unit_tests/comapct.txt", "r");

    if (f)
    {
        node = node_create("He");
        if (node)
        {
            head = list_add_end(head, node);
            node = node_create(" ");
            if (node)
            {
                head = list_add_end(head, node);
                node = node_create("run");
                if (node)
                {
                    head = list_add_end(head, node);

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

                        list_free(res);
                    }
                }
            }
            list_free(head);
        }
        fclose(f);
    }
}
END_TEST


Suite* compact_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("compact");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ordinary);
    tcase_add_test(tc_pos, test_nothing_changes);
    tcase_add_test(tc_pos, test_first_empty);
    tcase_add_test(tc_pos, test_empty_part);
    tcase_add_test(tc_pos, test_deletion_of_part);
    suite_add_tcase(s, tc_pos);

    return s;
}
