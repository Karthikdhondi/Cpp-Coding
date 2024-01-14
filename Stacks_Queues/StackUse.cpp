#include<iostream>
using namespace std;

//#include "stack_using_array.cpp"
#include "stack_class_usingTemplate.cpp"

#include<stack>
int main(){
    stack<int> s;
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.empty() << endl;




    /*
    //To enable the stack_using_array.cpp class, uncomment the below line and comment 
    //StackUsingArray s;
    StackUsingArray<char> s;
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
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
*/

}