#ifndef __BOOKINGSYSTEMEXCEPTIONS_H_
#define __BOOKINGSYSTEMEXCEPTIONS_H_

#include<iostream>
#include<exception>

using namespace std;

class Bad_Date : public exception {
public:
    const char *what() const noexcept { return "Invalid Date!"; }
};

class Bad_Date_OutOfRange : public Bad_Date {
public:
    const char *what() const noexcept { return "Date Out of Range. Expected (1900 - 2099)!"; }
};

class Bad_Station : public exception {
public:
    const char *what() const noexcept { return "Empty station name not accepted."; }
};

class Bad_Passenger : public exception {
public:
    const char *what() const noexcept { return "Invalid Passenger Details!"; }
};

class Bad_PassengerName : public Bad_Passenger {
public:
    const char *what() const noexcept { return "Invalid Passenger Name!"; }
};

class Bad_Railways : public exception {
public:
    const char *what() const noexcept { return "Invalid Railways Details Entry!"; }
};

class Bad_Query : public Bad_Railways{
public:
    const char *what() const noexcept { return "No such Data found!"; }
};

class Bad_Booking : public exception{
public:
    const char *what() const noexcept { return "Bad booking details!"; }
};

class Bad_BookingDate : public Bad_Booking{
public:
    const char *what() const noexcept { return "Bad booking date!"; }
};

class Bad_BookingCatgry : public Bad_Booking{
public:
    const char *what() const noexcept { return "Bad Category! You ae not suitable for this category."; }
};

// class Bad_PassengerName : public Bad_Passenger{
//     const char *what() const noexcept { return "Invalid Passenger Name!"; }
// };

#endif //__BOOKINGSYSTEMEXCEPTIONS_H_