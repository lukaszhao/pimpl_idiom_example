#pragma once


            // =========
            // class Dog
            // =========



class Dog
{

private:

    class       DogImpl;        // declare class Dog::DogImpl in .h, define class Dog::DogImpl in .cpp

    DogImpl*    d_dogImplPtr;


public:
    
    Dog();
        // default ctor
    
    Dog(int id, int age);
        // ctor with id and age

    ~Dog();
        // dtor

    void bark();
        // dog barks

};

