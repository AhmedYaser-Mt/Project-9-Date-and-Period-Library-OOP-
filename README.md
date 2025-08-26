# 📌 Project 9: Date & Period Libraries (OOP)

## 🔹 Overview
This project was implemented as part of **Course 10** in the **Programming Advices Track** [www.programmingadvices.com] by **Dr. Mohamed Abouhadhood**.  

The main idea is to **reuse all the date and period-related functions** we built earlier in **Course 8 – Algorithms & Problem Solving Level 4**, but instead of rewriting them, we collected them inside two **separate header files** (`clsDate.h` and `clsPeriod.h`) and wrapped them in **classes** to apply **Object-Oriented Programming (OOP) principles**.

---

## ✨ Features
- ✅ **Encapsulation**: All date and period logic is hidden inside well-structured classes.  
- ✅ **Reusability**: No need to rewrite functions—just call them from `clsDate` or `clsPeriod`.  
- ✅ **Multiple Constructors**: Initialize dates in various ways (system date, string, day/month/year, day-order in year).  
- ✅ **Static Functions**: Many utilities can be used directly without creating an object.  
- ✅ **Overloading**: Both static and instance methods are available for flexibility.  
- ✅ **Date Operations**: Add/subtract days, weeks, months, years, decades, centuries, millennia.  
- ✅ **Validation**: Check leap years, valid dates, weekdays, business days, etc.  
- ✅ **Calendars**: Print monthly or yearly calendars.  
- ✅ **Period Operations**: Overlap detection, period length calculation, counting overlap days, check if a date falls within a period.  

---

## 📂 Project Structure
📁 Project-9-Date-Period-Libraries-OOP

 - clsDate.h # Header file containing the clsDate class and all date functions
 - clsPeriod.h # Header file containing the clsPeriod class and all period functions
 - main.cpp # Sample code to demonstrate usage
 - README.md # Project documentation


---

## 🧾 Sample Demonstration
Here are some examples from the `main.cpp` file:

```cpp
#include <iostream>
#include "clsDate.h"
#include "clsPeriod.h"
using namespace std;

int main()
{
    clsDate Date1;
    Date1.Print();  // Prints today’s system date

    clsDate Date2("31/1/2022");
    Date2.Print();

    clsDate Date3(20, 12, 2022);
    Date3.Print();

    clsDate Date4(250, 2022); // 250th day of 2022
    Date4.Print();

    Date1.IncreaseDateByOneMonth();
    Date1.Print();

    Date3.PrintYearCalendar();  // Full calendar for 2022

    cout << Date2.IsValid() << endl;

    cout << "\nMy Age in days: " 
         << clsDate::CalculateMyAgeInDays(clsDate(6, 11, 1977)) 
         << "\n";

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
```

---

## 🖥️ Example Output:

- 20/8/2025   ← Today’s system date
- 31/1/2022
- 20/12/2022
- 7/9/2022    ← 250th day of 2022
- 20/9/2025   ← Date1 after adding one month
- [Year Calendar printed...]
- 1
- My Age in days: 17482
- 1
- Period Start: 1/1/2022
- Period End: 10/1/2022

- Period Start: 3/1/2022
- Period End: 5/1/2022
- 1
- 1

---

## 🙏 Acknowledgments

This project is part of the Programming Advices Training Track led by
- 👨‍🏫 Dr. Mohamed Abouhadhood
- 📚 Platform: Programming Advices
