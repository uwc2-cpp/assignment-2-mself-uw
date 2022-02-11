#include "TestHarness.h"

void swap(int* n1, int* n2)
{
    auto temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void swapReference(int& n1, int& n2)
{
    auto temp = n1; 
    n1 = n2;
    n2 = temp;
}

TEST(ByPointerReference, Swap)
{
    auto n1 = 0;
    auto n2 = 10;
    swapReference(n1, n2);
    CHECK_EQUAL(10, n1)
    CHECK_EQUAL(0, n2)
}

TEST(ByPointer, Swap)
{
    auto value1 = 0;
    auto value2 = 10;
    swap(&value1, &value2);
    CHECK_EQUAL(10, value1)
    CHECK_EQUAL(0, value2)
}