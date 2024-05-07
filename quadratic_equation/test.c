#include <check.h>
#include "quadratic_equation.h"

START_TEST(test_two_roots) {
    double root1, root2;
    int num_roots = solve_equation(1.0, -3.0, 2.0, &root1, &root2);
    ck_assert_int_eq(num_roots, 2);
    ck_assert((root1 == 2.0 && root2 == 1.0) || (root1 == 1.0 && root2 == 2.0));
}
END_TEST

START_TEST(test_one_root) {
    double root1, root2;
    int num_roots = solve_equation(1.0, -2.0, 1.0, &root1, &root2);
    ck_assert_int_eq(num_roots, 1);
    ck_assert_double_eq(root1, 1.0);
}
END_TEST

START_TEST(test_no_roots) {
    double root1, root2;
    int num_roots = solve_equation(1.0, 0.0, 1.0, &root1, &root2);
    ck_assert_int_eq(num_roots, 0);
}
END_TEST

START_TEST(test_linear_one_root) {
    double root1, root2;
    int num_roots = solve_equation(0.0, 2.0, -4.0, &root1, &root2);
    ck_assert_int_eq(num_roots, 1);
    ck_assert_double_eq(root1, 2.0);
}
END_TEST

START_TEST(test_linear_no_roots) {
    double root1, root2;
    int num_roots = solve_equation(0.0, 0.0, 1.0, &root1, &root2);
    ck_assert_int_eq(num_roots, 0);
}
END_TEST

START_TEST(test_linear_infinite_roots) {
    double root1, root2;
    int num_roots = solve_equation(0.0, 0.0, 0.0, &root1, &root2);
    ck_assert_int_eq(num_roots, -1);
}
END_TEST

Suite* quadratic_equation_suite() {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Quadratic Equation");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_two_roots);
    tcase_add_test(tc_core, test_one_root);
    tcase_add_test(tc_core, test_no_roots);
    tcase_add_test(tc_core, test_linear_one_root);
    tcase_add_test(tc_core, test_linear_no_roots);
    tcase_add_test(tc_core, test_linear_infinite_roots);

    suite_add_tcase(s, tc_core);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = quadratic_equation_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}