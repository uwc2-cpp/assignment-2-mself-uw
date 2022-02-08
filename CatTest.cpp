#include "TestHarness.h"

/* Cat (as in "concatenate"):
** 1. Write the function cat() that takes two C-style strings (i.e., char*) arguments 
**    and returns a std::unique<char[]> that contains the concatenation of the arguments. 
**    Use std::make_unique to use heap memory for the result. 
**    Write CppUnitLite tests to verify correct behavior.
** 2. Write a second function cat() that takes two const std::string& arguments and returns 
**    a std::string that is a concatenation of the arguments. 
**    The std::string version does not require new. 
**    Write CppUnitLite tests to verify correct behavior.
** 3. Which is the better approach? Explain your rationale for which is the better approach.
*/

//void swap(int* n1, int* n2) //make this the appropriate function
//{
//
//    //no peeking! your code goes here
//
//}
//
//TEST(ByPointerReference, Swap)
//{
//
//    //your test code goes here
//
//    //add more test cases as needed
//
//}