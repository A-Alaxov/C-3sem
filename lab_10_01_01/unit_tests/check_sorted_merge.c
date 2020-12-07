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
    node_t *head = NULL, *end = NULL;
    FILE *f = fopen("unit_tests/sorted_merge.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&head, songs, f))
            {
                front_back_split(head, &end);
                head = sorted_merge(&head, &end, comparator);

                song_t song1 = { "Coldplay", "Viva La Vida" };
                ck_assert_int_eq(comparator(&song1, head->data), 0);
                song_t song = { "Queen", "Bohemian Rhapsody" };
                ck_assert_int_eq(comparator(&song, head->next->data), 0);
                song_t song3 = { "Scorpions", "Humanity" };
                ck_assert_int_eq(comparator(&song3, head->next->next->data), 0);
                song_t song2 = { "The Rolling Stones", "Paint It Black" };
                ck_assert_int_eq(comparator(&song2, head->next->next->next->data), 0);

                list_free(head);
                list_free(end);
            }
            songs_free(songs);
        }
        fclose(f);
    }
}
END_TEST


START_TEST(test_empty_first_ptr)
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
                head = sorted_merge(&head, &end, comparator);

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


START_TEST(test_empty_second_ptr)
{
    node_t *head = NULL, *end = NULL;
    FILE *f = fopen("unit_tests/3_el.txt", "r");
    song_t **songs = NULL;

    if (f)
    {
        songs = calloc(SONGS_MAX, sizeof(song_t*));
        if (songs)
        {
            if (!read_from_file(&end, songs, f))
            {
                head = sorted_merge(&head, &end, comparator);

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


START_TEST(test_empty_ptrs)
{
    node_t *head = NULL, *end = NULL;

    head = sorted_merge(&head, &end, comparator);

    ck_assert_ptr_eq(head, NULL);
    ck_assert_ptr_eq(end, NULL);
}
END_TEST


Suite* sorted_merge_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("sorted_merge");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_empty_first_ptr);
    tcase_add_test(tc_neg, test_empty_second_ptr);
    tcase_add_test(tc_neg, test_empty_ptrs);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_ordinary);
    suite_add_tcase(s, tc_pos);

    return s;
}
