#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "sort.h"
#include "file_tools.h"
#include "creation.h"
#include "deletion.h"

int main(int argc, char**argv)
{
    FILE *f_in, *f_out;
    int rc = OK;
    node_t *head = NULL;
    song_t **songs = NULL;

    if (argc != 4)
    {
        rc = INCORRECT_INPUT;
    }
    else
    {
        f_in = fopen(argv[1], "r");
        if (f_in == NULL)
        {
            rc = WRONG_INPUT_FILE;
        }
        else
        {
            f_out = fopen(argv[2], "w");
            if (f_out == NULL)
            {
                rc = WRONG_OUTPUT_FILE;
            }
            else
            {
                songs = calloc(SONGS_MAX, sizeof(song_t*));
                if (songs)
                {
                    rc = read_from_file(&head, songs, f_in);

                    if (!rc)
                    {
                        if (!strcmp(argv[3], "pf"))
                        {
                            pop_front(&head);
                            print(head, f_out);
                        }
                        else if (!strcmp(argv[3], "pb"))
                        {
                            pop_back(&head);
                            print(head, f_out);
                        }
                        else if (!strcmp(argv[3], "rd"))
                        {
                            remove_duplicates(&head, comparator);
                            print(head, f_out);
                        }
                        else if (!strcmp(argv[3], "s"))
                        {
                            head = sort(head, comparator);
                            print(head, f_out);
                        }
                        else
                        {
                            rc = INCORRECT_INPUT;
                        }
                        list_free(head);
                    }
                    songs_free(songs);
                }
                fclose(f_out);
            }
            fclose(f_in);
        }
    }

    if (rc == -1)
        printf("Wrong file data\n");
    else if (rc == -2)
        printf("Incorrect input\n");
    else if (rc == -4)
        printf("Memory allocation error\n");
    else if (rc == -6)
        printf("Wrong input file\n");
    else if (rc == -7)
        printf("Wrong output file\n");

    return rc;
}
