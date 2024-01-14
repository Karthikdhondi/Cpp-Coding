#include<iostream>
using namespace std;

#include "Pair_class.cpp"

int main(){
    /*
    Pair<int> p0;
    p0.setX(10);
    p0.setY(20);

    Pair<double> p1;
    p1.setX(10.24);
    p1.setY(20.34);

    cout << "X0 :" << p0.getX()  << ", " << "Y :" << p0.getY()  << endl;
    cout << "X1 :" << p1.getX() << ", " << "Y :" << p1.getY() << endl;

    Pair<char> p2;
    p2.setX('a');
    p2.setY('b');

    cout << "X2 :" << p2.getX() << ", " << "Y2 :" << p2.getY() << endl;
  
    Pair<int,double> p3;
    p3.setX(10);
    p3.setY(20.45);    
    cout << "X3 :" << p3.getX() << ", " << "Y3 :" << p3.getY() << endl;
  */


// Creating a triplet using a Pair

Pair<Pair<int, int>, int> p4;
p4.setY(70);
Pair<int, int> p5;
p5.setX(50);
p5.setY(60);

p4.setX(p5);

cout << "X5 :" << p4.getX().getX() << ", " << "Y5 :" << p4.getX().getY() <<  ", "<< "Z5 :" << p4.getY() << endl;


Pair<Pair<int, char>, double> p7;
p7.setY(8.1994);
Pair<int, char> p6;
p6.setX(6);
p6.setY('K');

p7.setX(p6);

cout << "X5 :" << p7.getX().getX() << ", " << "Y5 :" << p7.getX().getY() <<  ", "<< "Z5 :" << p7.getY() << endl;
}