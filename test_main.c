#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "vm_stock.h"

static void test_loading_non_existent_file(void **state)
{
    int return_value = loadStockData("example.dat");
    assert_int_equal(-1, return_value);
}

static void test_loading_existent_file(void **state)
{
    int return_value = loadStockData("stock.dat");
    assert_int_equal(0, return_value);
}

int main(void) 
{
    const struct CMUnitTest tests[] = 
    {
        cmocka_unit_test(test_loading_non_existent_file),
        cmocka_unit_test(test_loading_existent_file),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}