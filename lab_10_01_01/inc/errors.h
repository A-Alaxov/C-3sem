#ifndef ERRORS_H
#define ERRORS_H

#define SONGS_MAX 100

#define WRONG_FILE_DATA -1
#define INCORRECT_INPUT -2
#define GETPOS_ERR -3
#define MEM_ALLOC_ERR -4
#define EMPTY_STR -5
#define WRONG_INPUT_FILE -6
#define WRONG_OUTPUT_FILE -7
#define OK 0

typedef struct song song_t;

struct song
{
    char *group;
    char *title;
};

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

#endif // ERRORS_H
