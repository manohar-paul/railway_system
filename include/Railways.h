// Paul Manohar Pusuluri
//  

#ifndef __RAILWAYS_H
#define __RAILWAYS_H

#include<iostream>
#include<vector>
#include<map>

#include"Station.h"
#include"BookingSystemExceptions.h"

using namespace std;

// Railways Class <<Singleton>>
class Railways {
private:
    // Vector of stations themselves
    vector<Station> stations_;

    // Map from a pair of strings (Station 1, Station 2) to the distance in between them
    map<pair<string, string>, int> distances_;

    // The above two would also have been mplemented as statics
    // But since we are using a singleton class it would be semantically nice to have non static ones


    // Since we are using Instance() function to call the constructor and get the Singleton Instance
    // This is made private
    Railways();

public:

    // Object Destructor
    ~Railways();

    // Method to get the Station object that corresponds to the given station name
    const Station &GetStation(const string &)const;

    // Method to get the distance between 2 Stations passed as arguments
    // Fetches from the map
    int GetDistance(const Station &, const Station &)const;

    // A non static function to validate the Railways
    // Unlike in the Date and Station here we cannot check and return as we should not have
    // copy ctrs for a singleton pattern
    // This is just a helper method to reduce the clutter in the Instance() method
    // Also non static since anyways we are using the singleton pattern
    void ValidateRailways() const;

    // returns a reference  to a static object that represents the Singleton Instance
    static const Railways &Instance() {
        static const Railways theObject;
        // This should come after the instantiation 
        // else the vector and map which we wish to check will not have entries in them
        theObject.ValidateRailways();
        // return the Sttaic connst obejct created
        return theObject;
    }

    // UnitTestFunction called from test file
    static void UnitTestRailways();
};

#endif /* __RAILWAYS_H */