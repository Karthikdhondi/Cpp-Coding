#include<iostream>


using namespace std;

#include "vehicle.h"
#include "car.h"

int main(){
    //Vehicle v;


    //v.color = "Gray" ;
    /*
    We cannot use numTyers directly since it is declared as protected,
    only derived class can access it. 

    v.numTyers = 4;
    
    we can use maxspeed here because it is declared as private.
    v.maxspeed = 100;
    */

    Car c(5);
    //c.color = "Red";

    /*
    Here numTyers will throw an error because it is declared as protected.
    It can be accessed in only derived class, outside the derived class we cant access. 
    Therefore it is thorwing an error

    */
    //c.numTyers = 2;
    //c.numGears = 5;
    
}