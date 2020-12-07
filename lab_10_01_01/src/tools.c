#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

int comparator(const void *ptr1, const void *ptr2)
{
    if (strcmp(((song_t*)ptr1)->group, ((song_t*)ptr2)->group))
        return strcmp(((song_t*)ptr1)->group, ((song_t*)ptr2)->group);
    else
        return strcmp(((song_t*)ptr1)->title, ((song_t*)ptr2)->title);
}

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    node_t *cur1 = *head, *cur2 = *head, *temp;

    if (!cur1)
        return;

    while (cur1->next)
    {
        cur2 = cur1;
        while (cur2->next)
        {
            if (!comparator(cur1->data, cur2->next->data))
            {
                temp = cur2->next;
                cur2->next = temp->next;
                free(temp);
            }
            else
            {
                cur2 = cur2->next;
            }
        }
        if (cur1->next)
            cur1 = cur1->next;
    }
}

void print(node_t *head, FILE *f)
{
    node_t *cur = head;
    while (cur)
    {
        fprintf(f, "%s - %s\n", ((song_t*)cur->data)->group, ((song_t*)cur->data)->title);
        cur = cur->next;
    }
}
