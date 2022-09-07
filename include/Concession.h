#ifndef __CONCESSION_H_
#define __CONCESSION_H_

#include<iostream>
#include<vector>
#include<map>
#include"Passenger.h"
#include"Divyaang.h"
#include"BookingClass.h"

class Concession {
protected:
    Concession();
public:
    ~Concession();
};

class GeneralConcession : public Concession {

private:
    GeneralConcession();

public:
    ~GeneralConcession();
    double GetConcession() const;
    static const GeneralConcession &Type() {
        static const GeneralConcession theObject;
        return theObject;
    }
};

class LadiesConcession : public Concession {
private:

    double concession_;
    LadiesConcession();

public:
    ~LadiesConcession();
    double GetConcession(const Passenger &) const;
    static const LadiesConcession &Type() {
        static const LadiesConcession theObject;
        return theObject;
    }
};

class SeniorCitizenConcession : public Concession {

private:
    map<string, double> concessions_;
    SeniorCitizenConcession();

public:
    ~SeniorCitizenConcession();
    double GetConcession(const Passenger &) const;
    static const SeniorCitizenConcession &Type() {
        static const SeniorCitizenConcession theObject;
        return theObject;
    }
};

class DivyaangConcession : public Concession {

private:
    map<pair<string, string>, double> concessions_;
    DivyaangConcession();

public:
    ~DivyaangConcession();
    double GetConcession(const Passenger &, const BookingClass &) const;
    static const DivyaangConcession &Type() {
        static const DivyaangConcession theObject;
        return theObject;
    }
};

#endif //__CONCESSION_H_