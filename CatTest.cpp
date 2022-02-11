#include "TestHarness.h"
using namespace std;

void CountChars(const char* str, int& numChars)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        numChars++;
    }
}

unique_ptr<char[]> Cat(const char* string_1, const char* string_2)
{
    int numChars = 0;
    CountChars(string_1, numChars);
    CountChars(string_2, numChars);

    auto concatenatedString = make_unique<char[]>(sizeof(char*) * numChars);

    for (;;)
    {
        int concatIndex = 0;
        for (int i = 0; string_1[i] != '\0'; i++, concatIndex++)
        {
            concatenatedString[concatIndex] = string_1[i];
        }
        for (int i = 0; string_2[i] != '\0'; i++, concatIndex++)
        {
            concatenatedString[concatIndex] = string_2[i];
        }
        return concatenatedString;
    }  
}

string Cat(const string& string1, const string& string2)
{
    return string1 + string2;
}


TEST(ConcatenateCharPointers, Concatenate)
{
    const char* string1 = "cheese";
    const char* string2 = "burger";

    unique_ptr<char[]> concatenatedString = Cat(string1, string2);

    CHECK_EQUAL("cheeseburger", concatenatedString.get())
}

TEST(ConcatenateStrings, Concatenate)
{
    string string1 = "steak";
    string string2 = "fries";

    string concatenatedString = Cat(string1, string2);

    CHECK_EQUAL("steakfries", concatenatedString)
}

//Utilizing the std::string over C style char* strings is preferrable. There is less chance for human error.