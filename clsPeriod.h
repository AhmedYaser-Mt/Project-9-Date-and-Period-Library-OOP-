#pragma once
#pragma warning (disable : 4996)
#include <iostream>
#include "clsString.h"
#include "clsDate.h"
#include<ctime>
#include<vector>
#include<string>
using namespace std;


class clsPeriod
{
public:

    clsDate StartDate;
    clsDate EndDate;

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->StartDate = StartDate;
        this->EndDate = EndDate;

    }

    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After
            )
            return false;
        else
            return true;

    }

    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        StartDate.Print();

        cout << "Period End: ";
        EndDate.Print();
    }

    static int PeriodLengthInDays(clsPeriod& Period, bool IncludeEndDay = false)
    {
        return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
    }

    int PeriodLengthInDays(bool IncludeEndDay = false)
    {
        return PeriodLengthInDays(*this, IncludeEndDay);
    }

    static bool IsDateWithinPeriod(clsPeriod& Period, clsDate& Date)
    {
        return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before
            || clsDate::CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After);
    }

    bool IsDateWithinPeriod(clsDate& Date)
    {
        return IsDateWithinPeriod(*this, Date);
    }

    static int CountOverLapDays(clsPeriod Period1, clsPeriod Period2)
    {
        int Period1Length = PeriodLengthInDays(Period1, true);
        int Period2Length = PeriodLengthInDays(Period2, true);
        int OverLapDays = 0;

        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        if (Period1Length < Period2Length)
        {
            while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
            {
                if (IsDateWithinPeriod(Period2, Period1.StartDate))
                    OverLapDays++;

                Period1.StartDate = clsDate::IncreaseDateByOneDay(Period1.StartDate);
            }
        }
        else
        {
            while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
            {
                if (IsDateWithinPeriod(Period1, Period2.StartDate))
                    OverLapDays++;

                Period2.StartDate = clsDate::IncreaseDateByOneDay(Period2.StartDate);
            }
        }

        return OverLapDays;
    }

    int CountOverLapDays(clsPeriod Period2)
    {
        return CountOverLapDays(*this, Period2);
    }
};

