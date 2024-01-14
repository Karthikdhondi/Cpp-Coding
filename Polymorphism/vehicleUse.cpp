#include<iostream>


using namespace std;

#include "vehicle.h"
#include "car.h"

int main(){
  
    Vehicle v;

    
    Car c;
    
    v.print();

    c.print();


    //Here the pointer is same as the object 
    Vehicle *v1 = new Vehicle;

    Vehicle *v2;
    /*
    1. Here pointer is of type Vehicle(Base class) and object is of type Car(derived class)
    2. Base class can point to derived class object, but vice versa is not allowed. 

    Note: 
    Whenever a Base class pointer is pointing to the child class object, in that case we can only access
    those properties which belong to Base class(Vehicle class). but I can't access the Car(Derived class) properties.

    */
    
    v2 = &c;

    v1 -> print();

    /*
    This v2->print(); is printing the Vehicle class's print() function, even though it is pointing to Car's class object.
    Because it is happening at "Compile time". 

    Since at compile time it will check what kind of pointer it is, 
    since v2 is Vehicle class pointer, so it will call Vehicle class properties only. But not car class's

    */

    v2 -> print();
    
    
}