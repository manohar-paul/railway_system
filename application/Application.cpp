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


using namespace std;

int main(int argc, char *argv[]) {

    Date doReservn = Date::Today();

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
        cout << *newBooking << endl;
    }
    catch (exception &Ex) {
        cout << "Exception Occured: " << Ex.what() << endl;
    }

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
        cout << *newBooking << endl;
    }
    catch (exception &Ex) {
        cout << "Exception Occured: " << Ex.what() << endl;
    }


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
        cout << *newBooking << endl;
    }
    catch (exception &Ex) {
        cout << "Exception Occured: " << Ex.what() << endl;
    }

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
        cout << *newBooking << endl;
    }
    catch (exception &Ex) {
        cout << "Exception Occured: " << Ex.what() << endl;
    }

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
        cout << *newBooking << endl;
    }
    catch (exception &Ex) {
        cout << "Exception Occured: " << Ex.what() << endl;
    }


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
        cout << *newBooking << endl;
    }
    catch (exception &Ex) {
        cout << "Exception Occured: " << Ex.what() << endl;
    }

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
        cout << *newBooking << endl;
    }
    catch (exception &Ex) {
        cout << "Exception Occured: " << Ex.what() << endl;
    }


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
        cout << *newBooking << endl;
    }
    catch (exception &Ex) {
        cout << "Exception Occured: " << Ex.what() << endl;
    }
    return 0;
}