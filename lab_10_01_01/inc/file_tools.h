#ifndef FILE_TOOLS_H
#define FILE_TOOLS_H

#include <stdio.h>
#include "errors.h"

int my_getline(char **lineptr, FILE *stream);

int read_from_file(node_t **head, song_t **songs, FILE *f);

#endif // FILE_TOOLS_H
