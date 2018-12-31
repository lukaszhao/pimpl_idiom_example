#include "pch.h"
#include "Dog.h"


#include <iostream>


// define calss Dog::DogImpl in .cpp, which was declared in .h
class Dog::DogImpl {
private:
    int         d_id;
    int         d_age;

public:
    DogImpl() : d_id(0), d_age(0) {}

    DogImpl(int id, int age) : d_id(id), d_age(age) {}

    void bark() {
        std::cout << "\nI am dog " << d_id << ", and my age is " << d_age << "\n";
    }

};


Dog::Dog() : d_dogImplPtr(new DogImpl)
{
}


Dog::Dog(int id, int age) : d_dogImplPtr(new DogImpl(id, age))
{
}


Dog::Dog(const Dog& rhs) : d_dogImplPtr(NULL)
{
    if (rhs.d_dogImplPtr) {
        // rhs.d_dogImplPtr is not null
        d_dogImplPtr = new DogImpl;
        *d_dogImplPtr = *rhs.d_dogImplPtr;
    }
}


Dog::~Dog()
{
    std::cout << "[DEBUG] ~Dog() called, delete dog\n";
    
    delete d_dogImplPtr;
}


Dog& Dog::operator=(const Dog& rhs)
{
    if (!rhs.d_dogImplPtr) {
        // rhs.d_dogImplPtr is null, then after copy, lhs d_dogImplPtr should also be null
        if (d_dogImplPtr) {
            // lhs d_dogImplPtr was not null, then need to delete and set it to null
            delete d_dogImplPtr;
            d_dogImplPtr = NULL;
        }
    } else {
        // rhs.d_dogImplPtr is not null, then after copy, lhs d_dogImplPtr should hold a copy
        if (!d_dogImplPtr) {
            // lhs d_dogImplPtr was null, directly copy construct (relying on DogImpl has correct/default copy ctor)
            d_dogImplPtr = new DogImpl(*rhs.d_dogImplPtr);
        } else {
            // lhs d_dogImplPtr was not null, directly copy content (relying on DogImpl has correct/default copy assignment operator)
            *d_dogImplPtr = *rhs.d_dogImplPtr;
        }
    }

    return *this;
}


void Dog::bark()
{
    d_dogImplPtr->bark();
}