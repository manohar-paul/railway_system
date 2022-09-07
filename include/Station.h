// Paul Manohar Pusuluri
//  

#ifndef __STATION_H_
#define __STATION_H_

#include<iostream>

using namespace std;

// Station Claass
class Station {

private:
    // Name of the Station
    const string name_;

    // Since we are using CreateStation function to call the constructor
    // This is made private
    Station(const string &);

public:
    // Object Destructor
    ~Station();

    // There is a need of Copy Constructor 
    // even though stations are fetched from Railways using GetStation 
    // and then on only references are used
    // in the createStation it is used
    Station(const Station &);

    // Public set method for the Private name_ attribute
    string GetName() const;

    // Distance of the present station from other station passed as a paramneter
    int GetDistance(const Station &) const;

    // CreateStation static method to call ctr and returns the Station object if valid 
    // else throws exception
    static Station CreateStation(const string &);

    // Friend function to outstream the Date object to os
    friend ostream &operator<<(ostream &, const Station &);

    // Testing Function that will be called while testing
    static void UnitTestStation();
};

#endif //__STATION_H_