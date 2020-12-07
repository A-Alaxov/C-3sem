#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_tools.h"

node_t *node_create(char *value)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
    {
        return NULL;
    }

    for (int i = 0; i < STR_MAX + 1; i++)
        node->str[i] = '\0';

    strcpy(node->str, value);
    node->next = NULL;
    return node;
}

node_t *list_add_end(node_t *head, node_t *node)
{
    if (!head)
        return node;

    node_t *cur = head;
    while (cur->next)
        cur = cur->next;

    cur->next = node;
    return head;
}

void list_free(node_t *head)
{
    node_t *toto = head, *temp = toto;

    while (toto)
    {
        temp = toto->next;
        free(toto);
        toto = temp;
    }
}
