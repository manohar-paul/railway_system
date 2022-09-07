// Paul Manohar Pusuluri
//  

#include<iostream>

#include"Booking.h"
#include"BookingCategory.h"
#include"BookingClass.h"
#include"Concession.h"
#include"Date.h"
#include"Divyaang.h"
#include"Gender.h"
#include"Passenger.h"
#include"Railways.h"
#include"Station.h"
#include"BookingSystemExceptions.h"

using namespace std;

int main(int argc, char *argv[]) {

    // General Booking With valid details

    cout << "*************** BEGIN UNIT TESTS ON DATE CLASS *******************\n" << endl;
    Date::UnitTestDate();
    cout << "\n**************** END UNIT TESTS ON DATE CLASS*********************" << endl;

    cout << "*************** BEGIN UNIT TESTS ON STATION CLASS *******************\n" << endl;
    Station::UnitTestStation();
    cout << "\n**************** END UNIT TESTS ON STATION CLASS*********************" << endl;

    cout << "*************** BEGIN UNIT TESTS ON GENDER CLASS *******************\n" << endl;
    Gender::UnitTestGender();
    cout << "\n**************** END UNIT TESTS ON GENDER CLASS*********************" << endl;

    cout << "*************** BEGIN UNIT TESTS ON PASSENGER CLASS *******************\n" << endl;
    Passenger::UnitTestPassenger();
    cout << "\n**************** END UNIT TESTS ON PASSENGER CLASS*********************" << endl;

    cout << "*************** BEGIN UNIT TESTS ON DIVYAANG CLASS *******************\n" << endl;
    Divyaang::UnitTestDivyaang();
    cout << "\n**************** END UNIT TESTS ON DIVYAANG CLASS*********************" << endl;

    cout << "*************** BEGIN UNIT TESTS ON BOOKING CLASS *******************\n" << endl;
    Booking::UnitTestBooking();
    cout << "\n**************** END UNIT TESTS ON BOOKING CLASS*********************" << endl;
}