#include "unity.h"
#include <ccore/data_structure/list/singly_linked_list.h>

void setUp(void) {} // this function runs before each test
void tearDown(void) {} // this function runs after each test

void test_sll_create(void)
{
    int value = 69;
    struct SLLNode* node = sll_create(value);
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL_INT(value, node->data);
    TEST_ASSERT_NULL(node->next);
    sll_delete(node);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_sll_create);
    return UNITY_END();
}
