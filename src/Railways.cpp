// Paul Manohar Pusuluri
//  

#include<iostream>
#include<vector>
#include<map>

#include"Railways.h"
#include"Station.h"
#include"BookingSystemExceptions.h"

using namespace std;

// Constructor to initialise the attributes of the Singleton Instance
Railways::Railways() {
    // Initialise the Stations
    stations_.push_back(Station::CreateStation("Mumbai"));
    stations_.push_back(Station::CreateStation("Delhi"));
    stations_.push_back(Station::CreateStation("Bangalore"));
    stations_.push_back(Station::CreateStation("Kolkata"));
    stations_.push_back(Station::CreateStation("Chennai"));

    // Initialise the Distances
    distances_[make_pair("Mumbai", "Delhi")] = 1447;
    distances_[make_pair("Mumbai", "Bangalore")] = 981;
    distances_[make_pair("Mumbai", "Kolkata")] = 2014;
    distances_[make_pair("Mumbai", "Chennai")] = 1338;
    distances_[make_pair("Delhi", "Bangalore")] = 2150;
    distances_[make_pair("Delhi", "Kolkata")] = 1472;
    distances_[make_pair("Delhi", "Chennai")] = 2180;
    distances_[make_pair("Bangalore", "Kolkata")] = 1871;
    distances_[make_pair("Bangalore", "Chennai")] = 350;
    distances_[make_pair("Chennai", "Kolkata")] = 1659;
}

// Desctructor
Railways::~Railways() { }

// Get method to get the station with the given name
const Station &Railways::GetStation(const string &name) const {
    vector<Station>::const_iterator it;
    // Iterate through all the entries in the vector and return the first
    for (it = stations_.begin(); it != stations_.end(); ++it)
        if ((it)->GetName() == name)
            break;
    if (it == stations_.end()) {
        throw Bad_Query();
    }
    return (*it);
}

// Get method to get the ditacnnes between two given stations
int Railways::GetDistance(const Station &from, const  Station &to) const {
    map<pair<string, string>, int>::const_iterator dist_iter;

    // Iterate through all the pairs in the map and return the first
    // Check the from-to pair
    dist_iter = distances_.find(make_pair(from.GetName(), to.GetName()));

    if (dist_iter == distances_.end()) { // Does not exist
        // Check the to-from pair. Must exist by symmetry
        dist_iter = distances_.find(make_pair(to.GetName(), from.GetName()));
    }

    if (dist_iter == distances_.end()) {
        throw Bad_Query();
    }

    return dist_iter->second;
}

// Railways Validations
void Railways::ValidateRailways() const {
    // Validate the entries made into the vector of stations
    // Iterate through all and find if it exists any where else
    vector<Station>::const_iterator it, it_dup_check;
    map<pair<string, string>, int>::const_iterator dist_iter, dist_iter_rev;

    for (it = this->stations_.begin(); it != this->stations_.end(); ++it) {
        for (it_dup_check = this->stations_.begin(); it_dup_check != this->stations_.end(); ++it_dup_check)
            if (it != it_dup_check && it->GetName() == it_dup_check->GetName()) {
                // This is where stations with same names are caught
                throw Bad_Railways();
            }
            else {
                // Here, either different stations with diff names are possbile
                //  or totally equal stations are possible
                dist_iter = distances_.find(make_pair(it->GetName(), it_dup_check->GetName()));

                if (it->GetName() == it_dup_check->GetName()) {
                    // Distance between teo same Station names defined 
                    if (dist_iter != distances_.end()) {
                        throw Bad_Railways();
                    }
                }

                else {
                    dist_iter_rev = distances_.find(make_pair(it_dup_check->GetName(), it->GetName()));
                    if (dist_iter == distances_.end()) { // Forward relation Does not exist
                        // Check the to-from pair. Must exist by symmetry
                        if (dist_iter_rev == distances_.end()) {
                            // Backward relation also Does not exist
                            // That is there is a pair of stations in between which distance is not defined
                            throw Bad_Railways();
                        }
                    }
                    else if (dist_iter != distances_.end() && dist_iter_rev != distances_.end()) {
                        // Both reverse and original both exists
                        throw Bad_Railways();
                    }
                }
            }

    }
    return;
}

// UnittestingFunction to use later in tests
void UnitTestRailways();