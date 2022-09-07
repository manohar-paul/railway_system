#include<iostream>
#include"Gender.h"

using namespace std;

Gender::Gender() { }
Gender::~Gender() { }

ostream &operator<<(ostream &os, Gender &gender) {
    os << gender.GetName();
    return os;
}

template<> string Gender::Male::GetName() const { return "Male"; }
template<> string Gender::Female::GetName() const { return "Female"; }

template<> string Gender::Male::GetTitle() const { return "Mr."; }
template<> string Gender::Female::GetTitle() const { return "Ms."; }


void Gender::UnitTestGender() {

    cout << "---- GetName and GetTitle----" << endl;

    cout << "\nTest Case 1 : Male" << endl;
    cout << "Input : Male" << endl;
    cout << "Output : " << endl;
    if (Gender::Male::Type().GetName() == "Male") {
        cout << "Test Case Passed. Succesfully returning the correct name of the gender." << endl;
    }
    else {
        cout << "Test Case failed. Failed in returning the correct name of the gender." << endl;
    }

    cout << "\nTest Case 2 : Female" << endl;
    cout << "Input : Female" << endl;
    cout << "Output : " << endl;
    if (Gender::Female::Type().GetName() == "Female") {
        cout << "Test Case Passed. Succesfully returning the correct name of the gender." << endl;
    }
    else {
        cout << "Test Case failed. Failed in returning the correct name of the gender." << endl;
    }

    cout << "\nTest Case 3 : Male" << endl;
    cout << "Input : Male" << endl;
    cout << "Output : " << endl;
    if (Gender::Male::Type().GetTitle() == "Mr.") {
        cout << "Test Case Passed. Succesfully returning the correct name of the gender." << endl;
    }
    else {

        cout << "Test Case failed. Failed in returning the correct title of the gender." << endl;
    }

    cout << "\nTest Case 4 : Female" << endl;
    cout << "Input : Female" << endl;
    cout << "Output : " << endl;
    if (Gender::Female::Type().GetTitle() == "Ms.") {
        cout << "Test Case Passed. Succesfully returning the correct title of the gender." << endl;
    }
    else {
        cout << "Test Case failed. Failed in returning the correct title of the gender." << endl;
    }
}