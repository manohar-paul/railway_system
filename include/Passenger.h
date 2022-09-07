// Paul Manohar Pusuluri
//  

#ifndef __PASSENGER_H
#define __PASSENGER_H

#include<iostream>
#include<vector>

#include"Date.h"
#include"Divyaang.h"
#include"Gender.h"

using namespace std;

// Name <<primitve>> datatype as a class
class Name {
public:
    // Public attributes that represent the name
    string firstName_;
    string middleName_;
    string lastName_;

    // Constrcutor with the Fname, Mname,Lname for the Name
    Name(const string &, const string &, const string &);

    // Desctrrucotr
    ~Name();

    // Copy Constrcutor
    Name(const Name &);

    // Get method that returns the name as format "fname mname lname"
    string GetName() const;
};

// Passenger
class Passenger {
public:
    // Attributes that represnet the passneger
    Name name_;
    Date  dateOfBirth_;
    const Gender &gender_;
    string aadhar_;
    string mobile_;
    const Divyaang &divyaangType_;
    string disabilityId_;

private:
    // Since we are using CreatePassenger function to call the constructor
    // This is made private
    Passenger(
        const Name &, const Date &, const Gender &, const string &, const string &,
        const Divyaang &d, const string &
    );

public:
    // Destructor
    ~Passenger();

    // Copy construcotr used in CreatePassenger 
    Passenger(const Passenger &);

    // CreatePassenger static method to call ctr and returns the Passenger object if valid 
    // else throws exception
    static Passenger CreatePassenger(
        const string &, const string &, const string &,
        Date &, const Gender &, const string & = "", const string & = "",
        const Divyaang & = Divyaang::None::Type(),
        const string & = "");

    // Friend function to outstream the Date object to os
    friend ostream &operator<<(ostream &os, const Passenger &passngr);

    static void UnitTestPassenger();
};

// Testing Function that will be called while testing

#endif /* __PASSENGER_H */