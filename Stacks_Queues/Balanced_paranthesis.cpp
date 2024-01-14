
#include<iostream>
#include<cstring>
using namespace std;

#include<stack>



bool balancedParantheses(char str){
    stack<char> s;
    for(int i=0; i < strlen(str); i++){
        if(str[i] == '{'  || str[i] == '(' || str[i] == '[' ){
          s.push(str[i]);
        }
   
        if(
            (s.top() == '{' && str[i] != '}') || 
            (s.top() == '(' && str[i] != ')') || 
            (s.top() == '[' && str[i] != ']') )
            {
               return false;
            }
             cout<< "iteration i: " << i << endl;
                s.pop();
        }
    return s.empty();
}


int main(){

    char *string = new char;
    cin >> string;
    cout <<"Given String: "<< string << endl; 
   // cout << string[5] << endl;

    val = balancedParantheses(string);

    if(val){
        cout << "Givem string has Balanced Paranthesis" << endl;
    }
    else{
        cout << "Imbalanced Paranthesis:" << endl;
    }
    
}


