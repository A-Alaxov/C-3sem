#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "list_tools.h"

void print(node_t *head)
{
    node_t *cur = head;
    while (cur)
    {
        printf("%s", cur->str);
        cur = cur->next;
    }
}

int list_create(node_t **head, FILE *f)
{
    char temp_str[STR_MAX + 1], c = getc(f);
    int kol = 0;
    node_t *node = NULL;

    while (c != '\n')
    {
        temp_str[kol] = c;
        kol++;
        if (kol == STR_MAX)
        {
            temp_str[kol + 1] = '\0';
            node = node_create(temp_str);
            if (node)
            {
                kol = 0;
                *head = list_add_end(*head, node);
            }
            else
            {
                free(*head);
                return MEM_ALLOC_ERR;
            }
        }
        c = getc(f);
    }

    if (kol)
    {
        temp_str[kol] = '\0';
        node = node_create(temp_str);
        if (node)
        {
            kol = 0;
            *head = list_add_end(*head, node);
        }
        else
        {
            free(*head);
            return MEM_ALLOC_ERR;
        }
    }

    if (!node)
    {
        return EMPTY_STR;
    }

    return OK;
}

void compact(node_t *head)
{
    node_t *cur = head, *temp;

    if (!head)
    {
        return;
    }

    while (cur->next)
    {
        if (strlen(cur->str) + strlen(cur->next->str) < 4)
        {
            cur->str[strlen(cur->str) + strlen(cur->next->str)] = '\0';
            for (size_t i = 0; i < strlen(cur->next->str); i++)
            {
                cur->str[strlen(cur->str)] = cur->next->str[i];
            }

            temp = cur->next;
            cur->next = temp->next;
            free(temp);
        }
        else
        {
            while (strlen(cur->str) < 4)
            {
                cur->str[strlen(cur->str) + 1] = '\0';
                cur->str[strlen(cur->str)] = cur->next->str[0];
                for (size_t i = 0; i < strlen(cur->next->str); i++)
                {
                    cur->next->str[i] = cur->next->str[i + 1];
                }
            }
        }

        if (cur->next)
            cur = cur->next;
    }
}
