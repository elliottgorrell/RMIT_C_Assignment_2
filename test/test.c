#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
static void test(void **state)
{
    assert_int_equal(3, 3);
    assert_int_not_equal(4, 3);
}
int main(void) 
{
    const UnitTest tests[] = 
    {
        unit_test(test),
    };
    return run_tests(tests);
}