// Paul Manohar Pusuluri
//  

#ifndef __BOOKING_H_
#define __BOOKING_H_

#include<iostream>
#include<vector>
#include"Date.h"
#include"Station.h"
#include"BookingClass.h"
#include"Passenger.h"

using namespace std;

// Forward declaration of the BookingTypes
template<typename T>
class BookingTypes;

// Forward declaraion of the BookingCategory which is declared in other header file
class BookingCategory;

// Generic Class for Booking
class Booking {
private:
    // Strcuts to be used as Template typenames 
    struct SeniorCitizenBookingType { };
    struct GeneralBookingType { };
    struct LadiesBookingType { };
    struct DivyaangBookingType { };
    struct TatkalBookingType { };
    struct PremTatkalBookingType { };

protected:
    // Used as Protected as this is an Abstract class 
    // and hence no instance is allowed independelty
    Booking(
        const Passenger &, const BookingClass &, const BookingCategory &,
        const Station &, const Station &, const Date &, const Date &
    );

    // Protected data related to the Booking
    const Station fromStation_;
    const Station toStation_;
    const Date dateOfBooking_;
    const BookingClass &bookingClass_;
    const BookingCategory &bookingCategory_;
    const Date dateOfReservation_;
    const Passenger passenger_;

    // Static data related
    static double sBaseFareRate;
    static vector<Booking *> sBookings;
    static int sPNRSerial;

    // On going processed values
    int PNR;
    double fare_;
    bool bookingStatus_;
    string bookingMessage_;

    // Method to compute base fare which only depends on stations data and class data 
    // and hence made as non virtual
    double computeBaseFare();

    // The below two requires the Category Type which is obtained 
    // as a part of the Booking category
    virtual double computeConcession() = 0;
    virtual double computeExtraCharges() = 0;

public:
    // Destructor
    ~Booking() { }

    // Protected methods used
    virtual string GetType() = 0;
    virtual void computeFare() = 0;
    static void sPrintAllBookings();

    // Output streaming operator
    friend ostream &operator<<(ostream &, Booking &);

    // CreateBooking static method to call ctr and returns the Booking object if valid 
    // else throws exception
    static Booking *CreateBooking(
        const Passenger &, const BookingClass &, const BookingCategory &,
        const Station &, const Station &, const Date &, const Date &
    );

    // The various possible BookingTypes as template
    typedef BookingTypes<SeniorCitizenBookingType> SeniorCitizenBooking;
    typedef BookingTypes<GeneralBookingType> GeneralBooking;
    typedef BookingTypes<PremTatkalBookingType> PremTatkalBooking;
    typedef BookingTypes<LadiesBookingType> LadiesBooking;
    typedef BookingTypes<TatkalBookingType> TatkalBooking;
    typedef BookingTypes<DivyaangBookingType> DivyaangBooking;
    
    static void UnitTestBooking();
};

// Template class with typename T
template<typename T>
class BookingTypes :public Booking {
private:

public:
    // This is a method of a template class and is common for all types and
    // hence given body here
    BookingTypes(
        const Passenger &passngr, const BookingClass &bClass, const BookingCategory &bCatgry,
        const Station &fromStn, const Station &toStn, const Date &doBook, const Date &doReservsn
    ) :
        Booking(passngr, bClass, bCatgry, fromStn, toStn, doBook, doReservsn) {
        // Increasing PNRSerail
        PNR = ++sPNRSerial;
        // Computinf fare
        this->computeFare();
        // Setting message as success
        bookingMessage_ = "Successfully, a ticket is booked";
        // Setting booking status as true
        bookingStatus_ = true;
        // Pushing the pointer to the static vector of bookings
        sBookings.push_back(this);
    }

    // Destrcuotr of the template class objects
    ~BookingTypes() { }

    // These three are methods different for different BookingTypes
    // and hence not given function body here, given in the source file
    string GetType();
    double computeConcession();
    double computeExtraCharges();

    // Computing fare as per the concessions, extracharges (bcz of the tatkal)
    // This is a method of a template class and is common for all types and
    // hence given body here : computeFare
    void computeFare() {
        // Computing basefare
        fare_ = computeBaseFare();
        // Computing Concessions
        double concession = this->computeConcession();
        // Computing Extra charges
        double extraCharges = this->computeExtraCharges();
        // Computing Final fare from the above three entities
        fare_ = fare_ - concession + extraCharges + bookingClass_.GetReservationCharge();
        double fraction = fare_ - static_cast<int>(fare_);
        if (fraction >= 0.5) {
            fare_ = static_cast<int>(fare_)+1;
        }
        else fare_ = static_cast<int>(fare_);
    }

};

#endif //__BOOKING_H_