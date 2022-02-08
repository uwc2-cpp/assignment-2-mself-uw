#include "TestHarness.h"

/* Factorial: Write a function that returns the factorial of its single int argument. 
** Declare the function constexpr. Add comments in your unit test to specify an example 
** where the factorial result is determined at compile-time, and another where the factorial 
** result is determined at run time. Write unit tests that verify both the compile-time and run-time usage.
*/
constexpr int CaculateFactorial(int num) 
{
    int factorial = num; 
    while (num >= 1)
    {
        num--; 
        factorial *= num;
    }
    return factorial;
}

TEST(ByPointerReference, Swap)
{

    //your test code goes here

    //add more test cases as needed

}