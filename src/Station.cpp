#include<iostream>
#include"Station.h"
#include"Railways.h"
#include"BookingSystemExceptions.h"

using namespace std;

// Contructor with name as a paramter
Station::Station(const string &name) : name_(name) { }

// Destrucotr
Station::~Station() { }

// Copy construcotr
Station::Station(const Station &station) : name_(station.name_) { }

// Output Streaming function
ostream &operator<<(ostream &os, const Station &station) {
    os << station.GetName();
    return os;
}

// Get method for the private name_ attribute
string Station::GetName() const { return name_; }

// Distance of the station passed from the present station (fetched from Railways Instance) 
int Station::GetDistance(const Station &a) const { return Railways::Instance().GetDistance(*this, a); }

// CreateStation static method to call ctr and returns the Station object if valid 
// else throws exception
Station Station::CreateStation(const string &name) {

    // Station Validations
    if (name == "") {
        // Empty String Validation
        throw Bad_Station();
    }

    // Calls ctr as name is valid and returns the copy of that
    Station a(name);
    return a;
}


void Station::UnitTestStation() {

    cout << "---- CreateStation Function and Out Stream Operator----" << endl;
    cout << "\nTest Case 1 : Valid and Exisitng Station" << endl;
    cout << "Input : Chennai" << endl;
    cout << "Output : " << endl;
    try {
        Station a = Station::CreateStation("Chennai");
        cout << "Test Case Passed. Station Created : " << a << endl;
    }
    catch (Bad_Station &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Failed. Found exception in correct ones too." << endl;
    }
    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception in correct ones too." << endl;
    }

    cout << "\nTest Case 2 : Empty Station name " << endl;
    cout << "Input : ''" << endl;
    cout << "Output : " << endl;
    try {
        Station a = Station::CreateStation("");
        cout << "Test Case Failed. Station Created even if empty." << a << endl;
    }
    catch (Bad_Station &ex) {
        cout << ex.what() << endl;
        cout << "Test Case Passed. Caught exception in empty name creation too." << endl;
    }
    catch (...) {
        cout << "Uncatchable errors" << endl;
        cout << "Test Case Failed. Found unknown exception in correct ones too." << endl;
    }

    cout << "---- Copy Constructor----" << endl;
    cout << "\nTest Case 1 : Copying contents " << endl;
    cout << "Input : Station('Chennai')" << endl;
    cout << "Output : " << endl;

    Station a = Station::CreateStation("Chennai");
    Station b = Station(a);
    if (b.name_ == a.name_)
        cout << "Test Case Passed. Station Created." << b << endl;
    else
        cout << "Test Case Failed. Station Not properly copied." << endl;

    cout << "---- GetName()----" << endl;
    cout << "\nTest Case 1 : Getting name of a valid station " << endl;
    cout << "Input : Station('Chennai')" << endl;
    cout << "Output : " << endl;

    if (a.GetName() == "Chennai")
        cout << "Test Case Passed. GetName properly read the name as: " << a.GetName() << endl;
    else
        cout << "Test Case Failed. GetName is not working." << endl;


    cout << "---- GetDistance()----" << endl;
    cout << "\nTest Case 1 : Output is correct or not " << endl;
    cout << "Input : Station('Chennai'), Station('Kolkata')" << endl;
    cout << "Output : " << endl;

    Station k = CreateStation("Kolkata");
    if (a.GetDistance(k) == 1659)
        cout << "Test Case Passed. GetDistance properly found the distance as: " << a.GetDistance(k) << endl;
    else
        cout << "Test Case Failed. GetDistance is not giving correct output." << endl;

    cout << "\nTest Case 2 : Reversing gives same Output or not " << endl;
    cout << "Input : Station('Kolkata'), Station('Chennai')" << endl;
    cout << "Output : " << endl;

    if (k.GetDistance(a) == a.GetDistance(k))
        cout << "Test Case Passed. GetDistance properly found the distance as: "
        << a.GetDistance(k) << " and " << k.GetDistance(a) << endl;
    else
        cout << "Test Case Failed. GetDistance is not giving correct output on reversing stations." << endl;
}