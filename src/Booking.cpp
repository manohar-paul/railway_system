// Paul Manohar Pusuluri
//  

#include<iostream>
#include<vector>

#include"Date.h"
#include"Station.h"
#include"Railways.h"
#include"Booking.h"
#include"BookingClass.h"
#include"BookingCategory.h"
#include"Passenger.h"
#include"Concession.h"
#include"BookingSystemExceptions.h"

using namespace std;

// Declaring the static variables
double Booking::sBaseFareRate = 0.5;
int Booking::sPNRSerial = 0;
vector<Booking *> Booking::sBookings;

ostream &operator<<(ostream &os, Booking &booking) {
    os << "\n*********************************************" << endl;
    os << "Booking Category: " << booking.GetType() << endl;
    os << "PNR: " << booking.PNR << endl;
    os << "Passenger Details: \n" << booking.passenger_ << endl;
    os << "From: " << booking.fromStation_ << " \nTo: " << booking.toStation_ << endl;
    os << "Fare: " << booking.fare_ << endl;
    os << "Date of Booking: " << booking.dateOfBooking_ << endl;
    os << "Date of Reservation: " << booking.dateOfReservation_ << endl;
    return os;
}

Booking::Booking(
    const Passenger &passngr, const BookingClass &bClass, const BookingCategory &bCatgry,
    const Station &from, const Station &to, const Date &doBook, const Date &doReservation
) :
    fromStation_(from), toStation_(to), dateOfBooking_(doBook), dateOfReservation_(doReservation),
    passenger_(passngr), bookingCategory_(bCatgry), bookingClass_(bClass) {

}

double Booking::computeBaseFare() {
    return Railways::Instance().GetDistance(fromStation_, toStation_) *
        sBaseFareRate *
        bookingClass_.GetLoadFactor();
}

template<> double Booking::GeneralBooking::computeConcession() {
    return fare_ * GeneralConcession::Type().GetConcession();
}

template<> double Booking::LadiesBooking::computeConcession() {
    return fare_ * LadiesConcession::Type().GetConcession(passenger_);
}

template<> double Booking::SeniorCitizenBooking::computeConcession() {
    return fare_ * SeniorCitizenConcession::Type().GetConcession(passenger_);
}

template<> double Booking::DivyaangBooking::computeConcession() {
    return fare_ * DivyaangConcession::Type().GetConcession(passenger_, bookingClass_);
}

template<> double Booking::TatkalBooking::computeConcession() { return fare_ * 0; }
template<> double Booking::PremTatkalBooking::computeConcession() { return fare_ * 0; }


template<> double Booking::GeneralBooking::computeExtraCharges() { return 0; }
template<> double Booking::LadiesBooking::computeExtraCharges() { return 0; }
template<> double Booking::SeniorCitizenBooking::computeExtraCharges() { return 0; }
template<> double Booking::DivyaangBooking::computeExtraCharges() { return 0; }

template<> double Booking::TatkalBooking::computeExtraCharges() {
    int distance = Railways::Instance().GetDistance(fromStation_, toStation_);
    if (distance < bookingClass_.GetMinTatkalDistance()) {
        return 0;
    }
    else {
        double tatkalCharges = distance * bookingClass_.GetTatkalLoadFactor();
        if (tatkalCharges < bookingClass_.GetMinTatkalCharge()) {
            return bookingClass_.GetMinTatkalCharge();
        }
        else if (tatkalCharges > bookingClass_.GetMaxTatkalCharge()) {
            return bookingClass_.GetMaxTatkalCharge();
        }
        else {
            return tatkalCharges;
        }
    }
}

template<> double Booking::PremTatkalBooking::computeExtraCharges() {
    int distance = Railways::Instance().GetDistance(fromStation_, toStation_);
    if (distance < bookingClass_.GetMinTatkalDistance()) {
        return 0;
    }
    else {
        double tatkalCharges = distance * 2 * bookingClass_.GetTatkalLoadFactor();
        if (tatkalCharges < 2 * bookingClass_.GetMinTatkalCharge()) {
            return 2 * bookingClass_.GetMinTatkalCharge();
        }
        else if (tatkalCharges > 2 * bookingClass_.GetMaxTatkalCharge()) {
            return 2 * bookingClass_.GetMaxTatkalCharge();
        }
        else {
            return 2 * tatkalCharges;
        }
    }
}

Booking *Booking::CreateBooking(
    const Passenger &passngr, const BookingClass &bClass, const BookingCategory &bCatgry,
    const Station &from, const Station &to, const Date &doBook, const Date &doReservn
) {
    Railways::Instance().GetStation(from.GetName());
    Railways::Instance().GetStation(to.GetName());
    Railways::Instance().GetDistance(from, to);

    if (doBook.GetTimeGap(doReservn) > 1 || doBook.GetTimeGap(doReservn) <= 0) {
        throw Bad_BookingDate();
    }

    if (!bCatgry.Eligibility(passngr)) {
        throw Bad_BookingCatgry();
    }

    return bCatgry.CreateBookingThisCategory(passngr, bClass, from, to, doBook, doReservn);
}

template<> string Booking::GeneralBooking::GetType() { return "GeneralBooking"; }
template<> string Booking::LadiesBooking::GetType() { return "LadiesBooking"; }
template<> string Booking::SeniorCitizenBooking::GetType() { return "SeniorCitizenBooking"; }
template<> string Booking::DivyaangBooking::GetType() { return "DivyaangBooking"; }
template<> string Booking::TatkalBooking::GetType() { return "TatkalBooking"; }
template<> string Booking::PremTatkalBooking::GetType() { return "PremTatkalBooking"; }

void Booking::UnitTestBooking() {
    Date doReservn = Date::CreateDate("09/04/2021");

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