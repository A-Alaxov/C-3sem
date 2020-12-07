#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void front_back_split(node_t *head, node_t **back)
{
    node_t *cur = head;
    int len = 0, temp_len = 0;

    if (!head)
    {
        *back = NULL;
        return;
    }
    while (cur)
    {
        len++;
        cur = cur->next;
    }

    cur = head;
    while (temp_len < (len + 1) / 2 - 1)
    {
        cur = cur->next;
        temp_len++;
    }

    *back = cur->next;
    cur->next = NULL;
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    node_t *res, *cur, *a = *head_a, *b = *head_b;

    if ((!a) && (!b))
    {
        return NULL;
    }
    else if ((!b) || ((a) && (comparator(a->data, b->data) <= 0)))
    {
        res = a;
        a = a->next;
    }
    else
    {
        res = b;
        b = b->next;
    }

    cur = res;
    while ((a) || (b))
    {
        if ((a) && (((!b) || (comparator(a->data, b->data) <= 0))))
        {
            cur->next = a;
            a = a->next;
            cur = cur->next;
        }
        else
        {
            cur->next = b;
            b = b->next;
            cur = cur->next;
        }
    }

    cur->next = NULL;
    *head_a = a;
    *head_b = b;
    return res;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *end = NULL;
    front_back_split(head, &end);

    if ((head) && (head->next))
        head = sort(head, comparator);
    if ((end) && (end->next))
        end = sort(end, comparator);

    return sorted_merge(&head, &end, comparator);
}
