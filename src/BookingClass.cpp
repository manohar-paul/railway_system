#include<iostream>
#include"BookingClass.h"

using namespace std;

// The function body to the friend output streaming operator function
ostream &operator<<(ostream &os, BookingClass &bClass) {
    os << bClass.GetName() << " Booking Class";
    return os;
}

// Get methods that describe the AC First Class Booking Class
template<> string BookingClass::ACFirstClass::GetName() const { return "ACFirstClass"; }
template<> double BookingClass::ACFirstClass::GetLoadFactor() const { return 6.50; }
template<> double BookingClass::ACFirstClass::GetReservationCharge() const { return 60; }
template<> double BookingClass::ACFirstClass::GetTatkalLoadFactor() const { return 0.3; }
template<> double BookingClass::ACFirstClass::GetMinTatkalCharge() const { return 400; }
template<> double BookingClass::ACFirstClass::GetMaxTatkalCharge() const { return 500; }
template<> int BookingClass::ACFirstClass::GetMinTatkalDistance() const { return 500; }
template<> int BookingClass::ACFirstClass::GetNumTiers() const { return 2; }
template<> bool BookingClass::ACFirstClass::IsSitting() const { return false; }
template<> bool BookingClass::ACFirstClass::IsAc() const { return true; }
template<> bool BookingClass::ACFirstClass::IsLuxury() const { return true; }

// Get methods that describe the Executive Chair Car Booking Class
template<> string BookingClass::ExecutiveChairCar::GetName() const { return "ExecutiveChairCar"; }
template<> double BookingClass::ExecutiveChairCar::GetLoadFactor() const { return 5.0; }
template<> double BookingClass::ExecutiveChairCar::GetReservationCharge() const { return 60; }
template<> double BookingClass::ExecutiveChairCar::GetTatkalLoadFactor() const { return 0.3; }
template<> double BookingClass::ExecutiveChairCar::GetMinTatkalCharge() const { return 400; }
template<> double BookingClass::ExecutiveChairCar::GetMaxTatkalCharge() const { return 500; }
template<> int BookingClass::ExecutiveChairCar::GetMinTatkalDistance() const { return 250; }
template<> int BookingClass::ExecutiveChairCar::GetNumTiers() const { return 0; }
template<> bool BookingClass::ExecutiveChairCar::IsSitting() const { return true; }
template<> bool BookingClass::ExecutiveChairCar::IsAc() const { return true; }
template<> bool BookingClass::ExecutiveChairCar::IsLuxury() const { return true; }

// Get methods that describe the AC 2 TierBooking Class
template<> string BookingClass::AC2Tier::GetName() const { return "AC2Tier"; }
template<> double BookingClass::AC2Tier::GetLoadFactor() const { return 4.0; }
template<> double BookingClass::AC2Tier::GetReservationCharge() const { return 50; }
template<> double BookingClass::AC2Tier::GetTatkalLoadFactor() const { return 0.3; }
template<> double BookingClass::AC2Tier::GetMinTatkalCharge() const { return 400; }
template<> double BookingClass::AC2Tier::GetMaxTatkalCharge() const { return 500; }
template<> int BookingClass::AC2Tier::GetMinTatkalDistance() const { return 500; }
template<> int BookingClass::AC2Tier::GetNumTiers() const { return 2; }
template<> bool BookingClass::AC2Tier::IsSitting() const { return false; }
template<> bool BookingClass::AC2Tier::IsAc() const { return true; }
template<> bool BookingClass::AC2Tier::IsLuxury() const { return false; }

// Get methods that describe the First Class Booking Class
template<> string BookingClass::FirstClass::GetName() const { return "FirstClass"; }
template<> double BookingClass::FirstClass::GetLoadFactor() const { return 3.0; }
template<> double BookingClass::FirstClass::GetReservationCharge() const { return 50; }
template<> double BookingClass::FirstClass::GetTatkalLoadFactor() const { return 0.3; }
template<> double BookingClass::FirstClass::GetMinTatkalCharge() const { return 400; }
template<> double BookingClass::FirstClass::GetMaxTatkalCharge() const { return 500; }
template<> int BookingClass::FirstClass::GetMinTatkalDistance() const { return 500; }
template<> int BookingClass::FirstClass::GetNumTiers() const { return 2; }
template<> bool BookingClass::FirstClass::IsSitting() const { return false; }
template<> bool BookingClass::FirstClass::IsAc() const { return false; }
template<> bool BookingClass::FirstClass::IsLuxury() const { return true; }

// Get methods that describe the AC 3 Tier Booking Class
template<> string BookingClass::AC3Tier::GetName() const { return "AC3Tier"; }
template<> double BookingClass::AC3Tier::GetLoadFactor() const { return 2.50; }
template<> double BookingClass::AC3Tier::GetReservationCharge() const { return 40; }
template<> double BookingClass::AC3Tier::GetTatkalLoadFactor() const { return 0.3; }
template<> double BookingClass::AC3Tier::GetMinTatkalCharge() const { return 300; }
template<> double BookingClass::AC3Tier::GetMaxTatkalCharge() const { return 400; }
template<> int BookingClass::AC3Tier::GetMinTatkalDistance() const { return 500; }
template<> int BookingClass::AC3Tier::GetNumTiers() const { return 3; }
template<> bool BookingClass::AC3Tier::IsSitting() const { return false; }
template<> bool BookingClass::AC3Tier::IsAc() const { return true; }
template<> bool BookingClass::AC3Tier::IsLuxury() const { return false; }

// Get methods that describe the AC Chair Car Booking Class
template<> string BookingClass::ACChairCar::GetName() const { return "ACChairCar"; }
template<> double BookingClass::ACChairCar::GetLoadFactor() const { return 2.0; }
template<> double BookingClass::ACChairCar::GetReservationCharge() const { return 40; }
template<> double BookingClass::ACChairCar::GetTatkalLoadFactor() const { return 0.3; }
template<> double BookingClass::ACChairCar::GetMinTatkalCharge() const { return 125; }
template<> double BookingClass::ACChairCar::GetMaxTatkalCharge() const { return 225; }
template<> int BookingClass::ACChairCar::GetMinTatkalDistance() const { return 250; }
template<> int BookingClass::ACChairCar::GetNumTiers() const { return 0; }
template<> bool BookingClass::ACChairCar::IsSitting() const { return true; }
template<> bool BookingClass::ACChairCar::IsAc() const { return true; }
template<> bool BookingClass::ACChairCar::IsLuxury() const { return false; }

// Get methods that describe the Sleeper Booking Class
template<> string BookingClass::Sleeper::GetName() const { return "Sleeper"; }
template<> double BookingClass::Sleeper::GetLoadFactor() const { return 1.0; }
template<> double BookingClass::Sleeper::GetReservationCharge() const { return 20; }
template<> double BookingClass::Sleeper::GetTatkalLoadFactor() const { return 0.3; }
template<> double BookingClass::Sleeper::GetMinTatkalCharge() const { return 100; }
template<> double BookingClass::Sleeper::GetMaxTatkalCharge() const { return 200; }
template<> int BookingClass::Sleeper::GetMinTatkalDistance() const { return 500; }
template<> int BookingClass::Sleeper::GetNumTiers() const { return 3; }
template<> bool BookingClass::Sleeper::IsSitting() const { return false; }
template<> bool BookingClass::Sleeper::IsAc() const { return false; }
template<> bool BookingClass::Sleeper::IsLuxury() const { return false; }

// Get methods that describe the Second Sitting Booking Class
template<> string BookingClass::SecondSitting::GetName() const { return "SecondSitting"; }
template<> double BookingClass::SecondSitting::GetLoadFactor() const { return 0.60; }
template<> double BookingClass::SecondSitting::GetReservationCharge() const { return 15; }
template<> double BookingClass::SecondSitting::GetTatkalLoadFactor() const { return 0.1; }
template<> double BookingClass::SecondSitting::GetMinTatkalCharge() const { return 10; }
template<> double BookingClass::SecondSitting::GetMaxTatkalCharge() const { return 15; }
template<> int BookingClass::SecondSitting::GetMinTatkalDistance() const { return 100; }
template<> int BookingClass::SecondSitting::GetNumTiers() const { return 0; }
template<> bool BookingClass::SecondSitting::IsSitting() const { return true; }
template<> bool BookingClass::SecondSitting::IsAc() const { return false; }
template<> bool BookingClass::SecondSitting::IsLuxury() const { return false; }