#include <stdio.h>
#include <stdlib.h>
#include <check.h>

Suite* front_back_split_suite(void);
Suite* my_getline_suite(void);
Suite* pop_back_suite(void);
Suite* pop_front_suite(void);
Suite* remove_duplicates_suite(void);
Suite* sort_suite(void);
Suite* sorted_merge_suite(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = front_back_split_suite();
    runner = srunner_create(s);
    srunner_add_suite(runner, my_getline_suite());
    srunner_add_suite(runner, pop_back_suite());
    srunner_add_suite(runner, pop_front_suite());
    srunner_add_suite(runner, remove_duplicates_suite());
    srunner_add_suite(runner, sort_suite());
    srunner_add_suite(runner, sorted_merge_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
