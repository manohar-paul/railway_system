#include<iostream>
#include"Passenger.h"
#include"BookingSystemExceptions.h"

using namespace std;

// Constrcutor
Name::Name(const string &fname, const string &mname, const string &lname) :
    firstName_(fname), middleName_(mname), lastName_(lname) {
}
// Destructor
Name::~Name() { }

// Copy constrcutor
Name::Name(const Name &name) :
    firstName_(name.firstName_), middleName_(name.middleName_), lastName_(name.lastName_) {
}

// Get Name as a string
string Name::GetName() const {
    return firstName_ + " " + middleName_ + " " + lastName_;
}

// Constrcuotor
Passenger::Passenger(
    const Name &name, const Date &dob, const Gender &gender,
    const string &aadhar, const string &mobile,
    const Divyaang &divyaangType,
    const string &disabilityId
) :
    name_(name), dateOfBirth_(dob), gender_(gender), aadhar_(aadhar), mobile_(mobile),
    divyaangType_(divyaangType), disabilityId_(disabilityId) {
}

// Copy construcotr
Passenger::Passenger(
    const Passenger &passngr
) :
    name_(passngr.name_), dateOfBirth_(passngr.dateOfBirth_), gender_(passngr.gender_), aadhar_(passngr.aadhar_), mobile_(passngr.mobile_),
    divyaangType_(passngr.divyaangType_), disabilityId_(passngr.disabilityId_) {
}

// Destrcutor
Passenger::~Passenger() { }

// Output Stream operator
ostream &operator<<(ostream &os, const Passenger &passngr) {
    os << "Name: " << passngr.gender_.GetTitle() << passngr.name_.GetName() << endl;
    os << "Date Of Birth: " << passngr.dateOfBirth_ << endl;
    os << "Gender: " << passngr.gender_.GetName() << endl;
    os << "Aadhar: " << passngr.aadhar_ << endl;
    os << "Mobile: " << passngr.mobile_ << endl;
    os << "Disability Type: " << passngr.divyaangType_.GetName() << endl;
    os << "Disability ID: " << passngr.disabilityId_ << endl;
    return os;
}

// Create Passenger and return it if valid
// Else throiws exception
Passenger Passenger::CreatePassenger(
    const string &fname, const string &mname, const string &lname,
    Date &dob, const Gender &gender, const string &aadhar, const string &mobile,
    const Divyaang &divyaangType,
    const string &disabilityId) {

    // Passenger Validations
    if (fname == "" && lname == "") {
        throw Bad_Passenger();
    }
    if (Date::Today().GetTimeGap(dob) <= 0) {
        throw Bad_Passenger();
    }
    if (aadhar.length() != 12 || aadhar.find_first_not_of("0123456789") != string::npos) {
        throw Bad_Passenger();
    }
    if (mobile != "" && (mobile.length() != 10 || mobile.find_first_not_of("0123456789") != string::npos)) {
        throw Bad_Passenger();
    }

    Name name(fname, mname, lname);
    return Passenger(
        name, dob, gender,
        aadhar, mobile, divyaangType, disabilityId);
}

void Passenger::UnitTestPassenger() {

    cout << "Test Case 1 : Input : All correct data : 'Sriram', 'Chowdary', 'Ravi', '26 / 08 / 2002', Gender::Male::Type(),'400416116899', '7995188345', Divyaang::None::Type()" << endl;
    try {
        Date dob = Date::CreateDate("26/08/2002");
        Passenger newPassenger = Passenger::CreatePassenger(
            "Sriram", "Chowdary", "Ravi", dob, Gender::Male::Type(),
            "400416116899", "7995188345", Divyaang::None::Type()
        );
        cout << "Test case Passed. \n The Passenger newly created is \n" << newPassenger << endl;
    }
    catch (...) {
        cout << "Test case failed. Throwing exceptions even in correct scenarios.\n" << endl;
    }

    cout << "Test Case 2 : Input : Invalid DOB data : 'Fname', 'Mname', 'Lname', '36 / 08 / 2002', Gender::Male::Type(),'400416116899', '7995188345', Divyaang::None::Type()" << endl;
    try {
        Date dob = Date::CreateDate("36/08/2002");
        Passenger newPassenger = Passenger::CreatePassenger(
            "Fname", "Mname", "Lname", dob, Gender::Male::Type(),
            "400416116899", "7995188345", Divyaang::None::Type()
        );
        cout << "Test case failed. Not throwing exceptions even in incorrect scenarios.\n" << endl;
    }
    catch (...) {
        cout << "Test case Passed. Exception throwed!! \n" << endl;
    }

    cout << "Test Case 3 : Input : Invalid Name data : '', 'Mname', '', '36 / 08 / 2002', Gender::Male::Type(),'400416116899', '7995188345', Divyaang::None::Type()" << endl;
    try {
        Date dob = Date::CreateDate("36/08/2002");
        Passenger newPassenger = Passenger::CreatePassenger(
            "", "Mname", "", dob, Gender::Male::Type(),
            "400416116899", "7995188345", Divyaang::None::Type()
        );
        cout << "Test case failed. Not throwing exceptions even in incorrect scenarios.\n" << endl;
    }
    catch (...) {
        cout << "Test case Passed. Exception throwed!! \n" << endl;
    }

    cout << "Test Case 4.1 : Input : Invalid Aadhar data : 'Fname', 'Mname', 'Lname', '26 / 08 / 2002', Gender::Male::Type(),'40041ss16899', '7995188345', Divyaang::None::Type()" << endl;
    try {
        Date dob = Date::CreateDate("26/08/2002");
        Passenger newPassenger = Passenger::CreatePassenger(
            "Fname", "Mname", "Lname", dob, Gender::Male::Type(),
            "40041ss16899", "7995188345", Divyaang::None::Type()
        );
        cout << "Test case failed. Not throwing exceptions even in incorrect scenarios.\n" << endl;
    }
    catch (...) {
        cout << "Test case Passed. Exception throwed!! \n" << endl;
    }

    cout << "Test Case 4.2 : Input : Invalid Aadhar data : 'Fname', 'Mname', 'Lname', '26 / 08 / 2002', Gender::Male::Type(),'400499', '7995188345', Divyaang::None::Type()" << endl;
    try {
        Date dob = Date::CreateDate("26/08/2002");
        Passenger newPassenger = Passenger::CreatePassenger(
            "Fname", "Mname", "Lname", dob, Gender::Male::Type(),
            "400499", "7995188345", Divyaang::None::Type()
        );
        cout << "Test case failed. Not throwing exceptions even in incorrect scenarios.\n" << endl;
    }
    catch (...) {
        cout << "Test case Passed. Exception throwed!! \n" << endl;
    }

    cout << "Test Case 5 : Input : Invalid Mobile data : 'Fname', 'Mname', 'Lname', '26 / 08 / 2002', Gender::Male::Type(),'400416116899', '7995s188345', Divyaang::None::Type()" << endl;
    try {
        Date dob = Date::CreateDate("26/08/2002");
        Passenger newPassenger = Passenger::CreatePassenger(
            "Fname", "Mname", "Lname", dob, Gender::Male::Type(),
            "400416116899", "7995s188345", Divyaang::None::Type()
        );
        cout << "Test case failed. Not throwing exceptions even in incorrect scenarios.\n" << endl;
    }
    catch (...) {
        cout << "Test case Passed. Exception throwed!! \n" << endl;
    }

    cout << "Test Case 5 : Input : Empty Mobile data : 'Fname', 'Mname', 'Lname', '26 / 08 / 2002', Gender::Male::Type(),'400416116899', '', Divyaang::None::Type()" << endl;
    try {
        Date dob = Date::CreateDate("26/08/2002");
        Passenger newPassenger = Passenger::CreatePassenger(
            "Fname", "Mname", "Lname", dob, Gender::Male::Type(),
            "400416116899", "", Divyaang::None::Type()
        );
        cout << "Test case Passed. \n The Passenger newly created is \n" << newPassenger << endl;
    }
    catch (...) {
        cout << "Test case failed. Throwing exceptions even in correct scenarios.\n" << endl;
    }

}

// string Passenger::GetName() const{
//     return name_.GetName();
// }