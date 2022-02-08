#include "TestHarness.h"

/* Swap: Write a function that swaps(exchanges the values of two integers).
** Use int* as the argument types.
** Write a second swap function using a reference(i.e., int&) as the argument types. 
** (Note : The C++ library has a std::swap.In most situations just use the library version.
** But, for this homework, write your own swap).
** Write CppUnitLite tests to verify correct behavior.
*/

void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void swapReference(int& n1, int& n2)
{
    int temp = n1; 
    n1 = n2;
    n2 = temp;
}

TEST(ByPointerReference, Swap)
{
    int n1 = 0;
    int n2 = 10;
    swapReference(n1, n2);
    CHECK_EQUAL(10, n1)
    CHECK_EQUAL(0, n2)

}

TEST(ByPointer, Swap)
{
    int value1 = 0;
    int value2 = 10;
    swap(&value1, &value2);
    CHECK_EQUAL(10, value1)
    CHECK_EQUAL(0, value2)
}