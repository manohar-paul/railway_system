#ifndef __DIVYAANG_H_
#define __DIVYAANG_H_

#include<iostream>

using namespace std;

template<typename T>
class DivyaangTypes; // Forward declaration of the DivyaangTypes

class Divyaang {
private:
    struct BlindType { };
    struct OrthoHandicappedType { };
    struct CancerType { };
    struct TBType { };
    struct NoneType { };

protected:
    Divyaang() { }

public:
    ~Divyaang() { }
    virtual string GetName() const = 0;

    friend ostream &operator<<(ostream &, const Divyaang &);

    typedef DivyaangTypes<BlindType> Blind;
    typedef DivyaangTypes<OrthoHandicappedType> OrthoHandicapped;
    typedef DivyaangTypes<CancerType> Cancer;
    typedef DivyaangTypes<TBType> TB;
    typedef DivyaangTypes<NoneType> None;

    static void UnitTestDivyaang();
};

template<typename T>
class DivyaangTypes :public Divyaang {

private:
    DivyaangTypes() :Divyaang() { }

public:
    ~DivyaangTypes() { }
    string GetName() const;

    static const DivyaangTypes<T> &Type() {
        static const DivyaangTypes<T> theObject;
        return theObject;
    }

    // Notes:
    // No need of Copy constructors and Assignment operators
};

#endif //__DIVYAANG_H_