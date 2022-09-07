#include<iostream>

#include"BookingCategory.h"
#include"Booking.h"
#include"Gender.h"
#include"Date.h"

using namespace std;

ostream &operator<<(ostream &os, BookingCategory &bCatgry) {
    os << bCatgry << " Booking Category";
    return os;
}

// ***************************************************************
// **********************GENERAL BOOKING CATGRY*******************
// ***************************************************************
template<> string BookingCategory::GeneralCategory::GetName() const { return "GeneralCategory"; }

template<> bool BookingCategory::GeneralCategory::Eligibility(const Passenger &passngr) const {
    return true;
}

template<> Booking *BookingCategory::GeneralCategory::CreateBookingThisCategory(
    const Passenger &passngr, const BookingClass &bClass,
    const Station &fromStn, const Station &toStn, const Date &doBook, const Date &doReservsn
) const {
    return new Booking::GeneralBooking(passngr, bClass, *this, fromStn, toStn, doBook, doReservsn);
}

// ***************************************************************
// ***********************LADIES BOOKING CATGRY*******************
// ***************************************************************
template<> string BookingCategory::LadiesCategory::GetName() const { return "LadiesCategory"; }

template<> bool BookingCategory::LadiesCategory::Eligibility(const Passenger &passngr) const {
    if (passngr.gender_.GetName() == Gender::Female::Type().GetName()) {
        return true;
    }
    return false;
}

template<> Booking *BookingCategory::LadiesCategory::CreateBookingThisCategory(
    const Passenger &passngr, const BookingClass &bClass,
    const Station &fromStn, const Station &toStn, const Date &doBook, const Date &doReservsn
) const {
    return new Booking::LadiesBooking(passngr, bClass, *this, fromStn, toStn, doBook, doReservsn);
}


// ***************************************************************
// *****************SENIOR CITIZEN BOOKING CATGRY*****************
// ***************************************************************
template<> string BookingCategory::SeniorCitizenCategory::GetName() const { return "SeniorCitizenCategory"; }

template<> bool BookingCategory::SeniorCitizenCategory::Eligibility(const Passenger &passngr) const {
    double age = Date::Today().GetTimeGap(passngr.dateOfBirth_);
    if (passngr.gender_.GetName() == Gender::Male::Type().GetName() && age >= 60) {
        return true;
    }
    else if (passngr.gender_.GetName() == Gender::Female::Type().GetName() && age >= 58) {
        return true;
    }
    return false;
}

template<> Booking *BookingCategory::SeniorCitizenCategory::CreateBookingThisCategory(
    const Passenger &passngr, const BookingClass &bClass,
    const Station &fromStn, const Station &toStn, const Date &doBook, const Date &doReservsn
) const {
    return new Booking::SeniorCitizenBooking(passngr, bClass, *this, fromStn, toStn, doBook, doReservsn);
}


// ***************************************************************
// ********************DIVYAANG BOOKING CATGRY********************
// ***************************************************************
template<> string BookingCategory::DivyaangCategory::GetName() const { return "DivyaangCategory"; }

template<> bool BookingCategory::DivyaangCategory::Eligibility(const Passenger &passngr) const {
    if (passngr.divyaangType_.GetName() != Divyaang::None::Type().GetName()) {
        return true;
    }
    return false;
}

template<> Booking *BookingCategory::DivyaangCategory::CreateBookingThisCategory(
    const Passenger &passngr, const BookingClass &bClass,
    const Station &fromStn, const Station &toStn, const Date &doBook, const Date &doReservsn
) const {
    return new Booking::DivyaangBooking(passngr, bClass, *this, fromStn, toStn, doBook, doReservsn);
}


// ***************************************************************
// ******************** TATKAL BOOKING CATGRY*********************
// ***************************************************************
template<> string BookingCategory::TatkalCategory::GetName() const { return "TatkalCategory"; }

template<> bool BookingCategory::TatkalCategory::Eligibility(const Passenger &passngr) const {
    return true;
}

template<> Booking *BookingCategory::TatkalCategory::CreateBookingThisCategory(
    const Passenger &passngr, const BookingClass &bClass,
    const Station &fromStn, const Station &toStn, const Date &doBook, const Date &doReservsn
) const {
    return new Booking::TatkalBooking(passngr, bClass, *this, fromStn, toStn, doBook, doReservsn);
}


// ***************************************************************
// ****************PREM TATKAL BOOKING CATGRY*********************
// ***************************************************************
template<> string BookingCategory::PremTatkalCategory::GetName() const { return "PremTatkalCategory"; }

template<> bool BookingCategory::PremTatkalCategory::Eligibility(const Passenger &passngr) const {
    return true;
}

template<> Booking *BookingCategory::PremTatkalCategory::CreateBookingThisCategory(
    const Passenger &passngr, const BookingClass &bClass,
    const Station &fromStn, const Station &toStn, const Date &doBook, const Date &doReservsn
) const {
    return new Booking::PremTatkalBooking(passngr, bClass, *this, fromStn, toStn, doBook, doReservsn);
}

