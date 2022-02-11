#include "TestHarness.h"
#include <optional>
using namespace std;

std::optional<int> ParseInt(const std::string& s)
{
    for (auto itr = s.begin(); itr != s.end(); ++itr)
    {
        if (isdigit(*itr))
        {
            return (optional<int>) stoi(s, nullptr);
        }
    }
    return nullopt;
}

TEST(ParseIntSuccess, Parse)
{
    auto result = ParseInt("99");

    CHECK(result.has_value());
    CHECK_EQUAL(99, *result);
}

TEST(ParseIntFailure, Parse)
{
    auto result = ParseInt("Hello");

    CHECK(!result.has_value());
}

TEST(Value_OR, Optional)
{
    auto hasInt = ParseInt("2022 is now");
    CHECK_EQUAL(2022, hasInt.value_or(0));

    auto noInt = ParseInt("Pickles");
    CHECK_EQUAL(0, noInt.value_or(0));
}

