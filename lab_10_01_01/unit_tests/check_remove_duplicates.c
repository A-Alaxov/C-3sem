#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "file_tools.h"
#include "tools.h"
#include "deletion.h"


START_TEST(test_ordinary)
{
    node_t *head = NULL;
    FILE *f = fopen("unit_tests/ordinary_duplicates.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&head, songs, f))
            {
                remove_duplicates(&head, comparator);

                song_t song = { "Queen", "Bohemian Rhapsody" };
                ck_assert_int_eq(comparator(&song, head->data), 0);
                song_t song1 = { "Coldplay", "Viva La Vida" };
                ck_assert_int_eq(comparator(&song1, head->next->data), 0);
                song_t song2 = { "Scorpions", "Humanity" };
                ck_assert_int_eq(comparator(&song2, head->next->next->data), 0);

                list_free(head);
            }
            songs_free(songs);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_first_el_duplicates)
{
    node_t *head = NULL;
    FILE *f = fopen("unit_tests/first_el_duplicates.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&head, songs, f))
            {
                remove_duplicates(&head, comparator);

                song_t song = { "Queen", "Bohemian Rhapsody" };
                ck_assert_int_eq(comparator(&song, head->data), 0);
                song_t song2 = { "The Rolling Stones", "Paint It Black" };
                ck_assert_int_eq(comparator(&song2, head->next->data), 0);

                list_free(head);
            }
            songs_free(songs);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_last_el_duplicates)
{
    node_t *head = NULL;
    FILE *f = fopen("unit_tests/last_el_duplicates.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&head, songs, f))
            {
                remove_duplicates(&head, comparator);

                song_t song2 = { "The Rolling Stones", "Paint It Black" };
                ck_assert_int_eq(comparator(&song2, head->data), 0);
                song_t song = { "Queen", "Bohemian Rhapsody" };
                ck_assert_int_eq(comparator(&song, head->next->data), 0);

                list_free(head);
            }
            songs_free(songs);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_no_duplicates)
{
    node_t *head = NULL;
    FILE *f = fopen("unit_tests/3_el.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&head, songs, f))
            {
                remove_duplicates(&head, comparator);

                song_t song = { "Queen", "Bohemian Rhapsody" };
                ck_assert_int_eq(comparator(&song, head->data), 0);
                song_t song1 = { "Coldplay", "Viva La Vida" };
                ck_assert_int_eq(comparator(&song1, head->next->data), 0);
                song_t song2 = { "The Rolling Stones", "Paint It Black" };
                ck_assert_int_eq(comparator(&song2, head->next->next->data), 0);

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
    node_t *head = NULL;

    remove_duplicates(&head, comparator);

    ck_assert_ptr_eq(head, NULL);
}
END_TEST


Suite* remove_duplicates_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("remove_duplicates");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_empty_ptr);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ordinary);
    tcase_add_test(tc_pos, test_first_el_duplicates);
    tcase_add_test(tc_pos, test_last_el_duplicates);
    tcase_add_test(tc_pos, test_no_duplicates);
    suite_add_tcase(s, tc_pos);

    return s;
}
