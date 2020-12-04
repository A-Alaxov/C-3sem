#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "tools.h"
#include "list_tools.h"

node_t *concatenation(node_t *head_a, node_t **head_b)
{
    node_t *res = list_add_end(head_a, *head_b);
    *head_b = NULL;
    compact(res);
    return res;
}

void remove_duplicates(node_t *head)
{
    node_t *cur = head;
    size_t i = 0;

    if (!head)
    {
        return;
    }

    while (cur->next)
    {
        i = 0;
        while (i < strlen(cur->str) - 1)
        {
            if ((cur->str[i] == ' ') && (cur->str[i + 1] == ' '))
            {
                for (size_t j = i; j < strlen(cur->str); j++)
                {
                    cur->str[j] = cur->str[j + 1];
                }
            }
            else
            {
                i++;
            }
        }

        if ((cur->str[strlen(cur->str) - 1] == ' ') && (cur->str[strlen(cur->str) - 1] == cur->next->str[0]))
        {
            cur->str[strlen(cur->str) - 1] = '\0';
        }

        cur = cur->next;
    }

    i = 0;
    while (i < strlen(cur->str) - 1)
    {
        if ((cur->str[i] == ' ') && (cur->str[i + 1] == ' '))
        {
            for (size_t j = i; j < strlen(cur->str); j++)
            {
                cur->str[j] = cur->str[j + 1];
            }
        }
        else
        {
            i++;
        }
    }

    compact(head);
}

int search(node_t *head_1, node_t *head_2, int *pos)
{
    int start = 0;
    size_t pos1, pos2, start_pos;
    node_t *cur = head_1, *trg = NULL, *temp_cur = NULL;

    if ((!head_1) || (!head_2))
    {
        return EMPTY_STR;
    }

    while (cur)
    {
        start_pos = 0;

        while (start_pos < strlen(cur->str))
        {
            pos1 = start_pos;
            temp_cur = cur;
            pos2 = 0;
            trg = head_2;

            while (temp_cur->str[pos1] == trg->str[pos2])
            {
                pos1++;
                if ((pos1 == strlen(temp_cur->str)) && (temp_cur->next))
                {
                    pos1 = 0;
                    temp_cur = temp_cur->next;
                }

                pos2++;
                if ((pos2 == strlen(trg->str)) && (trg->next))
                {
                    pos2 = 0;
                    trg = trg->next;
                }
                else if ((pos2 == strlen(trg->str)) && (!trg->next))
                {
                    *pos = start;
                    return OK;
                }
            }
            start_pos++;
            start++;
        }
        cur = cur->next;
    }

    return NOT_FOUND;
}
