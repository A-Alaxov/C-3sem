#include <stdio.h>
#include <stdlib.h>
#include <check.h>

Suite* compact_suite(void);
Suite* concatenation_suite(void);
Suite* remove_duplicates_suite(void);
Suite* search_suite(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = compact_suite();
    runner = srunner_create(s);
    srunner_add_suite(runner, concatenation_suite());
    srunner_add_suite(runner, remove_duplicates_suite());
    srunner_add_suite(runner, search_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
