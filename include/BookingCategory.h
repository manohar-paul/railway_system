#ifndef __BOOKING_CATEGORY_H_
#define __BOOKING_CATEGORY_H_

#include<iostream>
#include"Booking.h"
#include"Passenger.h"

using namespace std;

template<typename T>
class BookingCategoryTypes; // Forward declaration of the BookingCategoryTypes

class BookingCategory {
private:
    struct SeniorCitizenCategoryType { };
    struct GeneralCategoryType { };
    struct LadiesCategoryType { };
    struct DivyaangCategoryType { };
    struct TatkalCategoryType { };
    struct PremTatkalCategoryType { };

protected:
    BookingCategory() { }

public:
    ~BookingCategory() { }

    virtual string GetName() const = 0;
    virtual bool Eligibility(const Passenger &) const = 0;
    virtual Booking *CreateBookingThisCategory(const Passenger &, const BookingClass &,
        const Station &, const Station &, const Date &, const Date &) const = 0;

    friend ostream &operator<<(ostream &, BookingCategory &);

    typedef BookingCategoryTypes<SeniorCitizenCategoryType> SeniorCitizenCategory;
    typedef BookingCategoryTypes<GeneralCategoryType> GeneralCategory;
    typedef BookingCategoryTypes<PremTatkalCategoryType> PremTatkalCategory;
    typedef BookingCategoryTypes<LadiesCategoryType> LadiesCategory;
    typedef BookingCategoryTypes<TatkalCategoryType> TatkalCategory;
    typedef BookingCategoryTypes<DivyaangCategoryType> DivyaangCategory;
};

template<typename T>
class BookingCategoryTypes :public BookingCategory {

private:
    BookingCategoryTypes() :BookingCategory() { }

public:
    ~BookingCategoryTypes() { }

    string GetName() const;
    bool Eligibility(const Passenger &) const;

    Booking *CreateBookingThisCategory(const Passenger &, const BookingClass &,
        const Station &, const Station &, const Date &, const Date &) const;

    static const BookingCategoryTypes<T> &Type() {
        static const BookingCategoryTypes<T> theObject;
        return theObject;
    }

};

#endif //__BOOKING_CATEGORY_H_