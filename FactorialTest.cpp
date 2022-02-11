#include "TestHarness.h"

constexpr int CalculateFactorial(int num) 
{
    int factorial = num; 
    while (num > 1)
    {
        num--; 
        factorial *= num;
    }
    return factorial;
}

TEST(factorialCompileTime, constexpr)
{
    constexpr auto complileTimeResult = CalculateFactorial(5);
    CHECK_EQUAL(120, complileTimeResult)                        //determined at compile time
}

TEST(factorialRunTime, constexpr)
{
    auto runTimeResult = CalculateFactorial(6);                 //determined at run time
    CHECK_EQUAL(720, runTimeResult)                             //runTimeResult is NOT marked constexpr
}