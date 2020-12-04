#include <stdio.h>
#include <stdlib.h>
#include "file_tools.h"
#include "creation.h"
#include "deletion.h"

int my_getline(char **lineptr, FILE *file)
{
    fpos_t start;
    int rc = fgetpos(file, &start);
    if (rc)
        return GETPOS_ERR;

    int count = 0;
    char c = fgetc(file);
    while ((c != '\n') && (c != EOF))
    {
        c = fgetc(file);
        count++;
    }

    if (count)
    {
        free(*lineptr);
        *lineptr = malloc((count + 1) * sizeof(char));
        if (!lineptr)
        {
            return MEM_ALLOC_ERR;
        }
        else
        {
            rc = fsetpos(file, &start);
            if (!rc)
            {
                *lineptr = fgets(*lineptr, count + 1, file);
                c = fgetc(file);
            }
            else
            {
                free(*lineptr);
            }
        }
    }
    else
    {
        rc = EMPTY_STR;
    }
    return rc;
}

int read_from_file(node_t **head, FILE *f)
{
    char *temp_title = NULL, *temp_group = NULL;
    int read1, read2;
    node_t *node;

    while ((!(read1 = my_getline(&temp_group, f))) &&
        (!(read2 = my_getline(&temp_title, f))))
    {
        node = node_create(song_create(temp_group, temp_title));
        if (node)
        {
            *head = list_add_end(*head, node);
        }
        else
        {
            list_free(*head);
            *head = NULL;
            return MEM_ALLOC_ERR;
        }

    }

    if (read1 != MEM_ALLOC_ERR)
        free(temp_title);
    if (read2 != MEM_ALLOC_ERR)
        free(temp_group);

    if ((!feof(f)) || (ferror(f)) || (read2))
    {
        return WRONG_FILE_DATA;
    }

    return OK;
}
