#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"
using namespace std;


int main()
{
    clsDate Date1;
    Date1.Print();

    clsDate Date2("31/1/2022");
    Date2.Print();

    clsDate Date3(20, 12, 2022);
    Date3.Print();

    clsDate Date4(250, 2022);
    Date4.Print();

    Date1.IncreaseDateByOneMonth();
    Date1.Print();

    Date3.PrintYearCalendar();

    cout << Date2.IsValid() << endl;

    cout << "\nMy Age in days :" << clsDate::CalculateMyAgeInDays(clsDate(6, 11, 1977)) << "\n";

    cout << Date4.IsDateBeforeDate2(Date3) << endl;

    clsPeriod Period1(clsDate(1, 1, 2022), clsDate(10, 1, 2022));
    Period1.Print();

    cout << "\n";

    clsPeriod Period2(clsDate(3, 1, 2022), clsDate(5, 1, 2022));
    Period2.Print();
    
    cout << Period1.IsOverLapWith(Period2) << endl;

    cout << clsPeriod::IsOverlapPeriods(Period1, Period2) << endl;

    
    system("pause>0");
    return 0;
}

