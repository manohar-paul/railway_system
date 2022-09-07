#include<iostream> 
#include<vector>
#include<map>
#include"Concession.h"
#include"Passenger.h"
#include"Gender.h"
#include"Divyaang.h"
#include"BookingClass.h"

Concession::Concession() { }
Concession::~Concession() { }

GeneralConcession::GeneralConcession() : Concession() { }
GeneralConcession::~GeneralConcession() { }
double GeneralConcession::GetConcession() const {
    return 0;
}

LadiesConcession::LadiesConcession() : Concession(), concession_(0) { }
LadiesConcession::~LadiesConcession() { }

double LadiesConcession::GetConcession(const Passenger &passngr) const {
    return concession_;
}

SeniorCitizenConcession::SeniorCitizenConcession() :Concession() {
    concessions_[Gender::Male::Type().GetName()] = 0.4;
    concessions_[Gender::Female::Type().GetName()] = 0.5;
}
SeniorCitizenConcession::~SeniorCitizenConcession() { }

double SeniorCitizenConcession::GetConcession(const Passenger &passngr) const {

    map<string, double>::const_iterator gend_iter;

    gend_iter = concessions_.find(passngr.gender_.GetName());
    return gend_iter->second;

}

DivyaangConcession::DivyaangConcession() : Concession() {


    concessions_[make_pair(
        Divyaang::Blind::Type().GetName(),
        BookingClass::ACFirstClass::Type().GetName()
    )] = 0.5;
    concessions_[make_pair(
        Divyaang::OrthoHandicapped::Type().GetName(),
        BookingClass::ACFirstClass::Type().GetName()
    )] = 0.5;
    concessions_[make_pair(
        Divyaang::Cancer::Type().GetName(),
        BookingClass::ACFirstClass::Type().GetName()
    )] = 0.5;
    concessions_[make_pair(
        Divyaang::TB::Type().GetName(),
        BookingClass::ACFirstClass::Type().GetName()
    )] = 0.0;
    concessions_[make_pair(
        Divyaang::None::Type().GetName(),
        BookingClass::ACFirstClass::Type().GetName()
    )] = 0.0;


    concessions_[make_pair(
        Divyaang::Blind::Type().GetName(),
        BookingClass::ExecutiveChairCar::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::OrthoHandicapped::Type().GetName(),
        BookingClass::ExecutiveChairCar::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::Cancer::Type().GetName(),
        BookingClass::ExecutiveChairCar::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::TB::Type().GetName(),
        BookingClass::ExecutiveChairCar::Type().GetName()
    )] = 0.0;
    concessions_[make_pair(
        Divyaang::None::Type().GetName(),
        BookingClass::ExecutiveChairCar::Type().GetName()
    )] = 0.0;


    concessions_[make_pair(
        Divyaang::Blind::Type().GetName(),
        BookingClass::AC2Tier::Type().GetName()
    )] = 0.5;
    concessions_[make_pair(
        Divyaang::OrthoHandicapped::Type().GetName(),
        BookingClass::AC2Tier::Type().GetName()
    )] = 0.5;
    concessions_[make_pair(
        Divyaang::Cancer::Type().GetName(),
        BookingClass::AC2Tier::Type().GetName()
    )] = 0.5;
    concessions_[make_pair(
        Divyaang::TB::Type().GetName(),
        BookingClass::AC2Tier::Type().GetName()
    )] = 0.0;
    concessions_[make_pair(
        Divyaang::None::Type().GetName(),
        BookingClass::AC2Tier::Type().GetName()
    )] = 0.0;


    concessions_[make_pair(
        Divyaang::Blind::Type().GetName(),
        BookingClass::FirstClass::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::OrthoHandicapped::Type().GetName(),
        BookingClass::FirstClass::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::Cancer::Type().GetName(),
        BookingClass::FirstClass::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::TB::Type().GetName(),
        BookingClass::FirstClass::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::None::Type().GetName(),
        BookingClass::FirstClass::Type().GetName()
    )] = 0.0;


    concessions_[make_pair(
        Divyaang::Blind::Type().GetName(),
        BookingClass::AC3Tier::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::OrthoHandicapped::Type().GetName(),
        BookingClass::AC3Tier::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::Cancer::Type().GetName(),
        BookingClass::AC3Tier::Type().GetName()
    )] = 1.0;
    concessions_[make_pair(
        Divyaang::TB::Type().GetName(),
        BookingClass::AC3Tier::Type().GetName()
    )] = 0.0;
    concessions_[make_pair(
        Divyaang::None::Type().GetName(),
        BookingClass::AC3Tier::Type().GetName()
    )] = 0.0;


    concessions_[make_pair(
        Divyaang::Blind::Type().GetName(),
        BookingClass::ACChairCar::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::OrthoHandicapped::Type().GetName(),
        BookingClass::ACChairCar::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::Cancer::Type().GetName(),
        BookingClass::ACChairCar::Type().GetName()
    )] = 1.0;
    concessions_[make_pair(
        Divyaang::TB::Type().GetName(),
        BookingClass::ACChairCar::Type().GetName()
    )] = 0.0;
    concessions_[make_pair(
        Divyaang::None::Type().GetName(),
        BookingClass::ACChairCar::Type().GetName()
    )] = 0.0;


    concessions_[make_pair(
        Divyaang::Blind::Type().GetName(),
        BookingClass::Sleeper::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::OrthoHandicapped::Type().GetName(),
        BookingClass::Sleeper::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::Cancer::Type().GetName(),
        BookingClass::Sleeper::Type().GetName()
    )] = 1.0;
    concessions_[make_pair(
        Divyaang::TB::Type().GetName(),
        BookingClass::Sleeper::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::None::Type().GetName(),
        BookingClass::Sleeper::Type().GetName()
    )] = 0.0;


    concessions_[make_pair(
        Divyaang::Blind::Type().GetName(),
        BookingClass::SecondSitting::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::OrthoHandicapped::Type().GetName(),
        BookingClass::SecondSitting::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::Cancer::Type().GetName(),
        BookingClass::SecondSitting::Type().GetName()
    )] = 1.0;
    concessions_[make_pair(
        Divyaang::TB::Type().GetName(),
        BookingClass::SecondSitting::Type().GetName()
    )] = 0.75;
    concessions_[make_pair(
        Divyaang::None::Type().GetName(),
        BookingClass::SecondSitting::Type().GetName()
    )] = 0.0;
}
DivyaangConcession::~DivyaangConcession() { }

double DivyaangConcession::GetConcession(const Passenger &passngr, const BookingClass &bClass) const {

    map<pair<string, string>, double>::const_iterator divConc_iter;

    divConc_iter = concessions_.find(make_pair(
        passngr.divyaangType_.GetName(),
        bClass.GetName()
    ));

    return divConc_iter->second;
}
