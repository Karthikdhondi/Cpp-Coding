#include<iostream>
using namespace std;

#include "vehicle.h"
#include "car.h"
#include "truck.h"
#include "bus.h"

int main(){
   // HondaCity h(100, 5);

    /*
    A class can call only its immediate parent class Constructor
    */

    Bus b;
    /*
    b.print();
    This above print will give the error.

    we have print() functions in both "vehicle class and car Class".
    Therefore there is a confusion. To avoid the confusion we need to we can add a print() fuction in Bus Class. 
    */

    // if we dont want to use bus's print function then we need to explicitly mention the class name. 
    //b.print();

    //b.Car :: print();
}