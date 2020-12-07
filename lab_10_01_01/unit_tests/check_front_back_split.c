#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "file_tools.h"
#include "tools.h"
#include "deletion.h"


START_TEST(test_even_count)
{
    node_t *head = NULL, *end = NULL;
    FILE *f = fopen("unit_tests/4_el.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&head, songs, f))
            {
                front_back_split(head, &end);

                song_t song = { "Queen", "Bohemian Rhapsody" };
                ck_assert_int_eq(comparator(&song, head->data), 0);
                song_t song1 = { "Coldplay", "Viva La Vida" };
                ck_assert_int_eq(comparator(&song1, head->next->data), 0);

                song_t song2 = { "The Rolling Stones", "Paint It Black" };
                ck_assert_int_eq(comparator(&song2, end->data), 0);
                song_t song3 = { "Scorpions", "Humanity" };
                ck_assert_int_eq(comparator(&song3, end->next->data), 0);

                list_free(head);
                list_free(end);
            }
            songs_free(songs);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_odd_count)
{
    node_t *head = NULL, *end = NULL;
    FILE *f = fopen("unit_tests/3_el.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&head, songs, f))
            {
                front_back_split(head, &end);

                song_t song = { "Queen", "Bohemian Rhapsody" };
                ck_assert_int_eq(comparator(&song, head->data), 0);
                song_t song1 = { "Coldplay", "Viva La Vida" };
                ck_assert_int_eq(comparator(&song1, head->next->data), 0);

                song_t song2 = { "The Rolling Stones", "Paint It Black" };
                ck_assert_int_eq(comparator(&song2, end->data), 0);

                list_free(head);
                list_free(end);
            }
            songs_free(songs);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_one_el)
{
    node_t *head = NULL, *end = NULL;
    FILE *f = fopen("unit_tests/1_el.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&head, songs, f))
            {
                front_back_split(head, &end);

                song_t song = { "Queen", "Bohemian Rhapsody" };
                ck_assert_int_eq(comparator(&song, head->data), 0);

                ck_assert_ptr_eq(end, NULL);

                list_free(head);
            }
            songs_free(songs);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_empty_ptr)
{
    node_t *head = NULL, *end = NULL;

    front_back_split(head, &end);

    ck_assert_ptr_eq(head, NULL);
    ck_assert_ptr_eq(end, NULL);
}
END_TEST


Suite* front_back_split_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("front_back_split");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_empty_ptr);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_even_count);
    tcase_add_test(tc_pos, test_odd_count);
    tcase_add_test(tc_pos, test_one_el);
    suite_add_tcase(s, tc_pos);

    return s;
}
