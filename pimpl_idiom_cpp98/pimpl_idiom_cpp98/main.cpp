// pimpl_idiom_cpp98.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Dog.h"

int main()
{
    Dog dog(134624, 2);
    dog.bark();

    Dog dog2(dog);
    dog2.bark();

    Dog dog3;
    dog3 = dog;
    dog3.bark();
}

