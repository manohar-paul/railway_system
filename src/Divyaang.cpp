#include<iostream>
#include"Divyaang.h"

using namespace std;

ostream &operator<<(ostream &os, const Divyaang &divyaang) {
    os << divyaang.GetName();
    return os;
}

template<> string Divyaang::Blind::GetName() const { return "Blind"; }
template<> string Divyaang::OrthoHandicapped::GetName() const { return "OrthoHandicapped"; }
template<> string Divyaang::Cancer::GetName() const { return "Cancer"; }
template<> string Divyaang::TB::GetName() const { return "TB"; }
template<> string Divyaang::None::GetName() const { return "None"; }

void Divyaang::UnitTestDivyaang(){

    cout << "---- GetName----" << endl;

    cout << "\nTest Case 1 : Blind" << endl;
    cout << "Input : Blind" << endl;
    cout << "Output : " << endl;
    if (Divyaang::Blind::Type().GetName() == "Blind") {
        cout << "Test Case Passed. Succesfully returning the correct name of the divyaang type." << endl;
    }
    else {
        cout << "Test Case failed. Failed in returning the correct name of the divyaang type." << endl;
    }

    cout << "\nTest Case 2 : OrthoHandicapped" << endl;
    cout << "Input : OrthoHandicapped" << endl;
    cout << "Output : " << endl;
    if (Divyaang::OrthoHandicapped::Type().GetName() == "OrthoHandicapped") {
        cout << "Test Case Passed. Succesfully returning the correct name of the divyaang type." << endl;
    }
    else {
        cout << "Test Case failed. Failed in returning the correct name of the divyaang type." << endl;
    }

    cout << "\nTest Case 3 : Cancer" << endl;
    cout << "Input : Cancer" << endl;
    cout << "Output : " << endl;
    if (Divyaang::Cancer::Type().GetName() == "Cancer") {
        cout << "Test Case Passed. Succesfully returning the correct name of the divyaang type." << endl;
    }
    else {
        cout << "Test Case failed. Failed in returning the correct name of the divyaang type." << endl;
    }

    cout << "\nTest Case 4 : TB" << endl;
    cout << "Input : TB" << endl;
    cout << "Output : " << endl;
    if (Divyaang::TB::Type().GetName() == "TB") {
        cout << "Test Case Passed. Succesfully returning the correct name of the divyaang type." << endl;
    }
    else {
        cout << "Test Case failed. Failed in returning the correct name of the divyaang type." << endl;
    }

    cout << "\nTest Case 5 : None" << endl;
    cout << "Input : None" << endl;
    cout << "Output : " << endl;
    if (Divyaang::None::Type().GetName() == "None") {
        cout << "Test Case Passed. Succesfully returning the correct name of the divyaang type." << endl;
    }
    else {
        cout << "Test Case failed. Failed in returning the correct name of the divyaang type." << endl;
    }

}