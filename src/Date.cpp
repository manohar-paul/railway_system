// Paul Manohar Pusuluri
//  

#include<iostream>
#include<iomanip>
#include<ctime>
#include<sstream>

#include"Date.h"
#include"BookingSystemExceptions.h"

using namespace std;

// Function body to the friend stream operator
ostream &operator<< (ostream &os, const Date &date) {
    return (os << setw(2) << setfill('0') << date.date_ << "/"
        << setw(2) << setfill('0') << date.month_ << "/" << date.year_);
}

// Body to the  constructor
Date::Date(unsigned int d, unsigned int m, unsigned int y) : date_(d), month_(m), year_(y) {
}

// Body to the copy constrcutor
Date::Date(const Date &date) : date_(date.date_), month_(date.month_), year_(date.year_) {
}

// Body to the static CreateDate function
Date Date::CreateDate(const string &dateStr) {
    unsigned int date, month, year;
    char slash;

    // Extracts the data from input dd/mm/yyyy string format
    // Throws exception if invalid format (this will come under the Exceptions being returned below)

    istringstream iss(dateStr);
    iss >> date >> slash >> month >> slash >> year;

    // Date Validations : 

    //  Out of range Error
    if (1900 <= year && year <= 2099) {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
            //  31 days Months check
            if (date <= 0 || date > 31)
                throw Bad_Date();
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            //  30 days Months check
            if (date <= 0 || date > 30)
                throw Bad_Date();
        }
        else if (month == 2) {
            if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
                //  Leap year 29 Feb days check
                if (date <= 0 || date > 29)
                    throw Bad_Date();
            }
            else if (date <= 0 && date > 28)
                // Non Leap year 29 Feb days check
                throw Bad_Date();
        }
        else
            // Invalid month check
            throw Bad_Date();
    }
    // Invalid year check
    else throw Bad_Date_OutOfRange();

    // For the following a copy constructor is required
    return Date(date, month, year);
}

// Destructor
Date::~Date() { }

// Creates a Date obejct that represents today's date
Date Date::Today() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    // Formatting and making it into the Date format by sending info to the ctr
    // returning the Object thus formed
    return Date(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
}

// Returns a double value that tells in the fractional sense 
// the time gap with the present - reference
double Date::GetTimeGap(const Date &reference) const {
    double age = (
        static_cast<int>(year_) - static_cast<int>(reference.year_) +
        (static_cast<int>(month_) - static_cast<int>(reference.month_)) / 12.0 +
        (static_cast<int>(date_) - static_cast<int>(reference.date_)) / 365.0
        );
    return age;
}

// Testing Function that will be called while testing
void Date::UnitTestDate() {

    cout << "---- CreateDate Function and Out Stream Operator----" << endl;
    cout << "\nTest Case 1 : Valid Date" << endl;
    cout << "Input : 12/09/2012" << endl;
    cout << "Output : " << endl;
    try {
        Date a = Date::CreateDate("12/09/2012");
        cout << "Test Case Passed. Date Created : " << a << endl;
    }
    catch (Bad_Date &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Failed. Found exception in correct ones too." << endl;
    }
    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception in correct ones too." << endl;
    }

    cout << "\nTest Case 2 : Out of Bounds" << endl;
    cout << "Input : 22/12/1002" << endl;
    cout << "Output : " << endl;
    try {
        Date a = Date::CreateDate("22/12/1002");
        cout << "Test Case Failed. Creating Date in invalid ones too" << endl;
    }
    catch (Bad_Date &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Passed. Found exception in unbound dates." << endl;
    }
    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception." << endl;
    }

    cout << "\nTest Case 3 : Leap Years Feb 29" << endl;
    cout << "Input : 29/02/2004" << endl;
    cout << "Output : " << endl;

    try {
        Date a = Date::CreateDate("29/02/2004");
        cout << "Test Case Passed. Date Created : " << a << endl;
    }

    catch (Bad_Date &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Failed. Found exception in correct ones too." << endl;
    }

    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception in correct ones too." << endl;
    }

    cout << "\nTest Case 4 : Non Leap Years Feb 29" << endl;
    cout << "Input : 29/02/2021" << endl;
    cout << "Output : " << endl;

    try {
        Date a = Date::CreateDate("29/02/2021");
        cout << "Test Case Failed. Creating Date in invalid ones too" << endl;
    }
    catch (Bad_Date &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Passed. Found exception in invalid dates." << endl;
    }
    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception." << endl;
    }

    cout << "\nTest Case 5 : 31 Day months 31st day" << endl;
    cout << "Input : 31/01/2021" << endl;
    cout << "Output : " << endl;

    try {
        Date a = Date::CreateDate("31/01/2021");
        cout << "Test Case Passed. Date Created : " << a << endl;
    }

    catch (Bad_Date &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Failed. Found exception in correct ones too." << endl;
    }

    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception in correct ones too." << endl;
    }

    cout << "\nTest Case 6 : 30 Day months 31st day" << endl;
    cout << "Input : 31/04/2021" << endl;
    cout << "Output : " << endl;

    try {
        Date a = Date::CreateDate("31/04/2021");
        cout << "Test Case Failed. Creating Date in invalid ones too" << a << endl;
    }
    catch (Bad_Date &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Passed. Found exception in invalid dates." << endl;
    }
    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception." << endl;
    }

    cout << "\nTest Case 7 : Impossible dates" << endl;
    cout << "Input : -4/04/2015" << endl;
    cout << "Output : " << endl;

    try {
        Date a = Date::CreateDate("-4/04/2015");
        cout << "Test Case Failed. Creating Date in invalid ones too" << a << endl;
    }
    catch (Bad_Date &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Passed. Found exception in invalid dates." << endl;
    }
    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception." << endl;
    }

    cout << "\nTest Case 8 : Out of 1 - 12 months" << endl;
    cout << "Input : 31/15/2021" << endl;
    cout << "Output : " << endl;

    try {
        Date a = Date::CreateDate("31/15/2021");
        cout << "Test Case Failed. Creating Date in invalid ones too" << a << endl;
    }
    catch (Bad_Date &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Passed. Found exception in invalid dates." << endl;
    }
    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception." << endl;
    }

    cout << "\nTest Case 8 : Out of month days" << endl;
    cout << "Input : 531/15/2021" << endl;
    cout << "Output : " << endl;

    try {
        Date a = Date::CreateDate("531/15/2021");
        cout << "Test Case Failed. Creating Date in invalid ones too" << a << endl;
    }
    catch (Bad_Date &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Passed. Found exception in invalid dates." << endl;
    }
    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception." << endl;
    }




    cout << "\n\n---- Constructor Check----" << endl;
    cout << "\nTest Case 1 " << endl;
    cout << "Input : (26,8,2002)" << endl;
    cout << "Output : " << endl;
    Date a = Date(26, 8, 2002);
    if (a.date_ == 26 && a.month_ == 8 && a.year_ == 2002) {
        cout << "Test Case Passed. Feeding the inputs correctly in contrcutor." << endl;
    }
    else {
        cout << "Test Case Failed. Feeding the inputs in-correctly in contrcutor." << endl;
    }




    cout << "\n\n---- Copy Constructor Check----" << endl;
    cout << "\nTest Case 1 " << endl;
    cout << "Input : Date(26,8,2002)" << endl;
    cout << "Output : " << endl;
    Date b = Date(a);
    if (b.date_ == 26 && b.month_ == 8 && b.year_ == 2002) {
        cout << "Test Case Passed. Copied the fields correctly in contrcutor." << endl;
    }
    else {
        cout << "Test Case Failed. Copied the fields in-correctly in contrcutor." << endl;
    }




    cout << "\n\n---- Today Check----" << endl;
    cout << "\nTest Case 1 " << endl;
    cout << "Input : ---" << endl;
    cout << "Output : " << endl;
    Date c = Today();
    cout << "Test Case Passed. Todays date is found as " << c << endl;




    cout << "\n\n---- TimeGap Check----" << endl;
    cout << "\nTest Case 1 Correct Computation " << endl;
    cout << "Input : (26,08,2002) , (09,04,2021)" << endl;
    cout << "Output : " << endl;
    Date e = CreateDate("09/04/2021");
    double gap = e.GetTimeGap(a);
    if (gap >= 18.6200 && gap <= 18.6202) {
        cout << "Test Case Passed. Gap between " << a << " and " << e << " found as " << gap << endl;
    }
    else{
        cout << "Test Case failed. Not found the correct gap between the dates" << endl;
    }


    cout << "\nTest Case 2 Correct Negative - reverse Computation " << endl;
    cout << "Input : (09,04,2021), (26,08,2002)" << endl;
    cout << "Output : " << endl;
    double gap2 = a.GetTimeGap(e);
    if (gap2 == -gap) {
        cout << "Test Case Passed. Gap between " << e << " and " << a << " found as " << gap2 << endl;
    }
    else{
        cout << "Test Case failed. Not found the correct gap between the dates" << endl;
    }


}