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


Dog::~Dog()
{
    delete d_dogImplPtr;
}


void Dog::bark()
{
    d_dogImplPtr->bark();
}