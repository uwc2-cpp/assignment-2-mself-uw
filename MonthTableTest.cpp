#include "TestHarness.h"
#include <sstream>
#include <string>
#include <array>
using namespace std;

constexpr auto NumMonths = 12; //global for avoiding magic number usage throughout

struct Month
{
    string name;
    int numDays;
};


void WriteCalTable(const array<string, NumMonths>& name, const array<int, NumMonths> days, stringstream& ss)
{
    for (auto n = 0; n < NumMonths; n++)
    {
        ss << name[n] << ": " << days[n] << endl;
    }
}

void WriteCalTable(const array<Month, NumMonths>& month, stringstream& ss)
{
    for (auto n = 0; n < NumMonths; n++)
    {
        ss << month[n].name << ": " << month[n].numDays << endl;
    }
}

void FillTestCompareSS(stringstream& ss)
{
    ss << "January: 31" << endl
       << "February: 28" << endl
       << "March: 31" << endl
       << "April: 30" << endl
       << "May: 31" << endl
       << "June: 30" << endl
       << "July: 31" << endl
       << "August: 31" << endl
       << "September: 30" << endl
       << "October: 31" << endl
       << "November: 30" << endl
       << "December: 31" << endl;
}

TEST(monthTable, twoArrays)
{
    const array<string, NumMonths> monthNames = { "January",
                                                  "February",
                                                  "March",
                                                  "April",
                                                  "May",
                                                  "June",
                                                  "July",
                                                  "August",
                                                  "September",
                                                  "October",
                                                  "November",
                                                  "December" };

    const array<int, 12> numDaysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    stringstream ss;
    WriteCalTable(monthNames, numDaysInMonth, ss);

    stringstream monthTable;
    FillTestCompareSS(monthTable);
    CHECK_EQUAL(monthTable.str(), ss.str())
}

TEST(monthTable, structure)
{
    const array<Month, NumMonths> monthInfo
    {
        {
            {"January", 31},
            {"February", 28},
            {"March", 31},
            {"April", 30},
            {"May", 31},
            {"June", 30},
            {"July", 31},
            {"August", 31},
            {"September",30},
            {"October", 31},
            {"November", 30},
            {"December", 31}
        }
    };

    stringstream ss;
    WriteCalTable(monthInfo, ss);

    stringstream monthTable;
    FillTestCompareSS(monthTable);
    CHECK_EQUAL(monthTable.str(), ss.str())
}