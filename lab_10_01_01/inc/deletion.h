#ifndef DELETION_H
#define DELETION_H

#include "errors.h"

void songs_free(song_t **songs);

void list_free(node_t *head);

void *pop_front(node_t **head);

void *pop_back(node_t **head);

void free_song(song_t *el);

#endif // DELETION_H
