#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "task.h"
#include "list_tools.h"

int main()
{
    int rc = OK, pos;
    node_t *head = NULL, *head_2 = NULL;
    char input[INPUT_MAX + 2];

    if (fgets(input, INPUT_MAX + 2, stdin))
    {
        if (!strcmp(input, "out\n"))
        {
            rc = list_create(&head, stdin);
            if (!rc)
            {
                print(head);
            }
        }
        else if (!strcmp(input, "cat\n"))
        {
            rc = list_create(&head, stdin);
            if (!rc)
            {
                rc = list_create(&head_2, stdin);
                if (!rc)
                {
                    head = concatenation(head, &head_2);
                    print(head);
                }
            }
        }
        else if (!strcmp(input, "sps\n"))
        {
            rc = list_create(&head, stdin);
            if (!rc)
            {
                remove_duplicates(head);
                print(head);
            }
        }
        else if (!strcmp(input, "pos\n"))
        {
            rc = list_create(&head, stdin);
            if (!rc)
            {
                rc = list_create(&head_2, stdin);
                if (!rc)
                {
                    rc = search(head, head_2, &pos);
                    if (!rc)
                    {
                        printf("%d", pos);
                    }
                }
            }
        }
        else
        {
            rc = INCORRECT_INPUT;
        }

        if (head)
            list_free(head);
        if (head_2)
            list_free(head_2);
    }

    /*
    if (rc == -1)
        printf("Incorrect input\n");
    else if (rc == -2)
        printf("Memory allocation error\n");
    else if (rc == -3)
        printf("Empty string\n");
    */

    return rc;
}
