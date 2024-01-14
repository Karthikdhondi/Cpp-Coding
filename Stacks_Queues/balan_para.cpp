#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty() || (st.top() != '(' && ch == ')') ||
                (st.top() != '{' && ch == '}' ) ||
                (st.top() != '[' && ch == ']')) {
               
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s="{a-(b+c)*[c/d]}";

    if (isValid(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}