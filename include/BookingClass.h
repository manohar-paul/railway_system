#ifndef __BOOKING_CLASS_H_
#define __BOOKING_CLASS_H_

#include<iostream>

using namespace std;

template<typename T>
class BookingClassTypes;
// Forward declaration of the BookingClassTypes

// Generic class for the Booking Classes
class BookingClass {
private:
    struct SleeperType { };
    struct SecondSittingType { };
    struct ACChairCarType { };
    struct ExecutiveChairCarType { };
    struct AC3TierType { };
    struct AC2TierType { };
    struct ACFirstClassType { };
    struct FirstClassType { };

protected:
    BookingClass() { }
    virtual bool IsSitting() const = 0;
    virtual bool IsLuxury() const = 0;
    virtual bool IsAc() const = 0;
    virtual int GetNumTiers() const = 0;

public:
    ~BookingClass() { }
    virtual string GetName() const = 0;
    virtual double GetLoadFactor() const = 0;
    virtual double GetReservationCharge() const = 0;
    virtual double GetTatkalLoadFactor() const = 0;
    virtual double GetMaxTatkalCharge() const = 0;
    virtual double GetMinTatkalCharge() const = 0;
    virtual int GetMinTatkalDistance() const = 0;

    friend ostream &operator<<(ostream &, BookingClass &);

    typedef BookingClassTypes<SleeperType> Sleeper;
    typedef BookingClassTypes<FirstClassType> FirstClass;
    typedef BookingClassTypes<SecondSittingType> SecondSitting;
    typedef BookingClassTypes<ACFirstClassType> ACFirstClass;
    typedef BookingClassTypes<ACChairCarType> ACChairCar;
    typedef BookingClassTypes<ExecutiveChairCarType> ExecutiveChairCar;
    typedef BookingClassTypes<AC2TierType> AC2Tier;
    typedef BookingClassTypes<AC3TierType> AC3Tier;
};

template<typename T>
class BookingClassTypes :public BookingClass {
private:
    BookingClassTypes() : BookingClass() { }
    bool IsSitting() const;
    bool IsLuxury() const;
    bool IsAc() const;
    int GetNumTiers() const;

public:
    ~BookingClassTypes() { }
    string GetName() const;
    double GetLoadFactor() const;
    double GetReservationCharge() const;
    double GetTatkalLoadFactor() const;
    double GetMaxTatkalCharge() const;
    double GetMinTatkalCharge() const;
    int GetMinTatkalDistance() const;

    static const BookingClassTypes<T> &Type() {
        static const BookingClassTypes<T> theObject;
        return theObject;
    }
};

#endif //__BOOKING_CLASS_H_