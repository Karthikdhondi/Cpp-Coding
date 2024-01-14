#include<iostream> 
using namespace std;

#include "stack_class_using_ll.cpp"

int main(){

    StackUsingLL<int> s;

    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);
    s.push(106);
    s.push(107);
    s.push(108);
    s.push(109);


  
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;

}