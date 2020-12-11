#include <stdio.h>
#include <stdlib.h>
#include <check.h>

Suite* str_to_lld_suite(void);
Suite* str_put_suite(void);
Suite* my_snprintf_suite(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = str_to_lld_suite();
    runner = srunner_create(s);
    srunner_add_suite(runner, str_put_suite());
    srunner_add_suite(runner, my_snprintf_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
