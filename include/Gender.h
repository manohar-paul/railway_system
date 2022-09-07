#ifndef __GENDER_H_
#define __GENDER_H_

#include<iostream>

using namespace std;

template<typename T>
class GenderTypes; // Forward declaration of the GenderTypes

class Gender {
private:
    struct MaleType { };
    struct FemaleType { };

protected:
    Gender();

public:
    ~Gender();
    virtual string GetName() const = 0;
    virtual string GetTitle() const = 0;

    friend ostream &operator<<(ostream &, const Gender &);

    typedef GenderTypes<MaleType> Male;
    typedef GenderTypes<FemaleType> Female;
    
    static void UnitTestGender();
};

template<typename T>
class GenderTypes :public Gender {

private:
    GenderTypes() { }

public:
    ~GenderTypes() { }
    string GetName() const;
    string GetTitle() const;

    static const GenderTypes<T> &Type() {
        static const GenderTypes<T> theObject;
        return theObject;
    }

};


#endif //__GENDER_H_