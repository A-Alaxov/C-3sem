#ifndef ERRORS_H
#define ERRORS_H

#define STR_MAX 4
#define INPUT_MAX 3

#define INCORRECT_INPUT -1
#define MEM_ALLOC_ERR -2
#define EMPTY_STR -3
#define NOT_FOUND -4
#define OK 0

typedef struct node node_t;

struct node
{
    char str[STR_MAX + 1];
    node_t *next;
};

#endif // ERRORS_H
