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

    Date doReservn = Date::CreateDate("09/04/2021");
    // Made the Date of Reservation to the date on which the tests have been made 
    // else if made = TODAY. then some tests fail as time progresses
    // But be careful that in the Age criteria Present TODAY Date has been referenced

    // ****************************************************************************
    // ********************       VALID BOOKINGS         **************************
    // ****************************************************************************
    cout << "******************VALID BOOKINGS***********************" << endl;
    cout << "---- Bookings which does not validate on any passenger data ----" << endl;
    cout << "Test Case 1 : Input : AC3Tier, GeneralCategory,Delhi,Mumbai" << endl;
    cout << "Output : " << endl;
    try {
        Date dob = Date::CreateDate("26/08/2002");
        Passenger passenger = Passenger::CreatePassenger(
            "Sriram", "Chowdary", "Ravi", dob, Gender::Male::Type(),
            "400416116899", "7995188345", Divyaang::None::Type()
        );
        Date dobook = Date::CreateDate("11/04/2021");
        Booking *newBooking = Booking::CreateBooking(
            passenger, BookingClass::AC3Tier::Type(), BookingCategory::GeneralCategory::Type(),
            Railways::Instance().GetStation("Delhi"), Railways::Instance().GetStation("Mumbai"),
            dobook, doReservn);
        cout << "Test case Passed. \n The booking newly created is \n" << *newBooking << endl;
    }
    catch (...) {
        cout << "Test case failed. Throwing exceptions even in correct scenarios.\n" << endl;
    }


    cout << "\n\n---- Bookings which validate only on any passenger (age and gender) data ----" << endl;
    cout << "Test Case 2 : Input : ACFirstClass, SeniorCitizenCategory,Delhi,Kolkata" << endl;
    cout << "Output : " << endl;
    try {
        Date dob = Date::CreateDate("15/08/1947");
        Passenger passenger = Passenger::CreatePassenger(
            "Fname", "Mname", "Lname", dob, Gender::Male::Type(),
            "400416116899", "7995188345", Divyaang::None::Type()
        );
        Date dobook = Date::CreateDate("11/04/2021");
        Booking *newBooking = Booking::CreateBooking(
            passenger, BookingClass::ACFirstClass::Type(), BookingCategory::SeniorCitizenCategory::Type(),
            Railways::Instance().GetStation("Delhi"), Railways::Instance().GetStation("Kolkata"),
            dobook, doReservn);
        cout << "Test case Passed. \n The booking newly created is \n" << *newBooking << endl;
    }
    catch (...) {
        cout << "Test case failed. Throwing exceptions even in correct scenarios.\n" << endl;
    }


    cout << "\n\n---- Bookings which validate both on passenger (age and gender) and Divyaang data ----" << endl;
    cout << "Test Case 3 : Input : Sleeper, Blind,Chennai,Banagalore" << endl;
    cout << "Output : " << endl;
    try {
        Date dob = Date::CreateDate("11/03/2001");
        Passenger passenger = Passenger::CreatePassenger(
            "Fname", "Mname", "Lname", dob, Gender::Female::Type(),
            "400416116899", "7995188345", Divyaang::Blind::Type()
        );
        Date dobook = Date::CreateDate("11/04/2021");
        Booking *newBooking = Booking::CreateBooking(
            passenger, BookingClass::Sleeper::Type(), BookingCategory::DivyaangCategory::Type(),
            Railways::Instance().GetStation("Chennai"), Railways::Instance().GetStation("Bangalore"),
            dobook, doReservn);
        cout << "Test case Passed. \n The booking newly created is \n" << *newBooking << endl;
    }
    catch (...) {
        cout << "Test case failed. Throwing exceptions even in correct scenarios.\n" << endl;
    }


    cout << "\n\n---- Tatkal Bookings which validate no data and alsono concessions ----" << endl;
    cout << "Test Case 4 : Input : ACChairCar, Cancer,Chennai,Kolkata" << endl;
    cout << "Output : " << endl;
    try {
        Date dob = Date::CreateDate("11/03/2001");
        Passenger passenger = Passenger::CreatePassenger(
            "Fname", "Mname", "Lname", dob, Gender::Female::Type(),
            "400416116899", "7995188345", Divyaang::Cancer::Type()
        );
        Date dobook = Date::CreateDate("11/04/2021");
        Booking *newBooking = Booking::CreateBooking(
            passenger, BookingClass::ACChairCar::Type(), BookingCategory::TatkalCategory::Type(),
            Railways::Instance().GetStation("Chennai"), Railways::Instance().GetStation("Kolkata"),
            dobook, doReservn);
        cout << "Test case Passed. \n The booking newly created is \n" << *newBooking << endl;
    }
    catch (...) {
        cout << "Test case failed. Throwing exceptions even in correct scenarios.\n" << endl;
    }

    // ****************************************************************************
    // ********************     INVALID BOOKINGS         **************************
    // ****************************************************************************
    cout << "****************** INVALID BOOKINGS***********************" << endl;
    cout << "---- Invalid based on Category, passenger is not allowed to take that ----" << endl;
    cout << "Test Case 1 : Input : ExecutiveChairCar, GeneralCategory,Delhi,Mumbai" << endl;
    cout << "Output : " << endl;
    try {
        Date dob = Date::CreateDate("26/08/2002");
        Passenger passenger = Passenger::CreatePassenger(
            "Sriram", "Chowdary", "Ravi", dob, Gender::Male::Type(),
            "400416116899", "7995188345", Divyaang::None::Type()
        );
        Date dobook = Date::CreateDate("11/04/2021");
        Booking *newBooking = Booking::CreateBooking(
            passenger, BookingClass::ExecutiveChairCar::Type(), BookingCategory::LadiesCategory::Type(),
            Railways::Instance().GetStation("Delhi"), Railways::Instance().GetStation("Mumbai"),
            dobook, doReservn);
        cout << "Test case failed. Not throwing exceptions even in incorrect scenarios.\n" << endl;
    }
    catch (...) {
        cout << "Test case Passed. \n The booking is invalid and exception raised" << endl;
    }


    cout << "\n\n---- Invalid based on Date of booking > 1 year ----" << endl;
    cout << "Test Case 2 : Input ::AC2Tier, SeniorCitizenCategory,Delhi,Kolkata" << endl;
    cout << "Output : " << endl;
    try {
        Date dob = Date::CreateDate("15/08/1947");
        Passenger passenger = Passenger::CreatePassenger(
            "Fname", "Mname", "Lname", dob, Gender::Male::Type(),
            "400416116899", "7995188345", Divyaang::None::Type()
        );
        Date dobook = Date::CreateDate("11/04/2022");
        Booking *newBooking = Booking::CreateBooking(
            passenger, BookingClass::AC2Tier::Type(), BookingCategory::SeniorCitizenCategory::Type(),
            Railways::Instance().GetStation("Delhi"), Railways::Instance().GetStation("Kolkata"),
            dobook, doReservn);
        cout << "Test case failed. Not throwing exceptions even in incorrect scenarios.\n" << endl;
    }
    catch (...) {
        cout << "Test case Passed. \n The booking is invalid and exception raised" << endl;
    }


    cout << "\n\n---- Invalid based on Date of booking < 1 day ----" << endl;
    cout << "Test Case 3 : Input : FirstClass, Blind,Chennai,Banagalore" << endl;
    cout << "Output : " << endl;
    try {
        Date dob = Date::CreateDate("11/03/2001");
        Passenger passenger = Passenger::CreatePassenger(
            "Fname", "Mname", "Lname", dob, Gender::Female::Type(),
            "400416116899", "7995188345", Divyaang::Blind::Type()
        );
        Date dobook = Date::CreateDate("09/04/2021");
        Booking *newBooking = Booking::CreateBooking(
            passenger, BookingClass::FirstClass::Type(), BookingCategory::DivyaangCategory::Type(),
            Railways::Instance().GetStation("Chennai"), Railways::Instance().GetStation("Bangalore"),
            dobook, doReservn);
        cout << "Test case failed. Not throwing exceptions even in incorrect scenarios.\n" << endl;
    }
    catch (...) {
        cout << "Test case Passed. \n The booking is invalid and exception raised" << endl;
    }


    cout << "\n\n---- Invalid Passenger Detials ----" << endl;
    cout << "Test Case 4 : Input : SecondSitting, Cancer,Chennai,Kolkata, Passenger:{'', 'Mname', ''}" << endl;
    cout << "Output : " << endl;
    try {
        Date dob = Date::CreateDate("11/03/2001");
        Passenger passenger = Passenger::CreatePassenger(
            "", "Mname", "", dob, Gender::Female::Type(),
            "400416a116899", "7995188a345", Divyaang::Cancer::Type()
        );
        Date dobook = Date::CreateDate("11/04/2021");
        Booking *newBooking = Booking::CreateBooking(
            passenger, BookingClass::SecondSitting::Type(), BookingCategory::TatkalCategory::Type(),
            Railways::Instance().GetStation("Chennai"), Railways::Instance().GetStation("Kolkata"),
            dobook, doReservn);
        cout << "Test case failed. Not throwing exceptions even in incorrect scenarios.\n" << endl;
    }
    catch (...) {
        cout << "Test case Passed. \n The booking is invalid and exception raised" << endl;
    }
}