// Paul Manohar Pusuluri
//  

#ifndef __DATE_H
#define __DATE_H

#include<iostream>
using namespace std;

// Date Class
class Date {

private:
    // Private Attributes
    unsigned int date_, month_, year_;

    // Since we are using CreateDate function to call the constructor
    // This is made private
    Date(unsigned int, unsigned int, unsigned int);

public:
    // Object Destructor
    ~Date();

    // Copy Constructor as this is primarily used in CreateDate
    Date(const Date &);

    // CreateDate static method to call ctr and returns the date object if valid 
    // else throws exception
    static Date CreateDate(const string &);

    // Returns todays system date in terms of Date Object 
    static Date Today();

    // Returns the date gap interms of fractions representing the num of years
    // Returned convention this - reference 
    double GetTimeGap(const Date &) const;

    // Friend function to outstream the Date object to os
    friend ostream &operator<< (ostream &, const Date &);

    // Testing Function that will be called while testing
    static void UnitTestDate();

};

#endif /*  __DATE_H */