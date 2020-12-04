#include <stdio.h>
#include <stdlib.h>
#include "deletion.h"

void free_song(song_t *el)
{
    if (el)
    {
        free(el->group);
        free(el->title);
    }
    free(el);
}

void list_free(node_t *head)
{
    node_t *toto = head, *temp = toto;

    while (toto)
    {
        temp = toto->next;
        free_song(toto->data);
        free(toto);
        toto = temp;
    }
}

void *pop_front(node_t **head)
{
    if (!*head)
        return NULL;

    void *res = (*head)->data;
    node_t *temp = *head;

    *head = (*head)->next;
    free(temp);
    return res;
}

void *pop_back(node_t **head)
{
    if (!*head)
        return NULL;

    node_t *cur = *head;
    void *res = cur->data;

    if (!cur->next)
    {
        res = cur->data;
        free(cur);
        *head = NULL;
    }
    else
    {
        while (cur->next->next)
            cur = cur->next;

        res = cur->next->data;
        free(cur->next);
        cur->next = NULL;
    }
    return res;
}
