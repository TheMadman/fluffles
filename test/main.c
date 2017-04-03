#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

CU_pTest (* const add_test)(CU_pSuite, const char*, CU_TestFunc) = CU_add_test;

void my_test()
{
        CU_ASSERT(0);
}

int main(int argc, char **argv)
{
        CU_pSuite suite;
        CU_pTest test;
        if (CU_initialize_registry() != CUE_SUCCESS) {
                puts("CUnit registry initialisation failed");
                exit(1);
        }
        suite = CU_add_suite("Test suite", 0, 0);
        test = add_test(suite, "My CUnit Test", my_test);

        CU_basic_run_tests();

        CU_cleanup_registry();
}
