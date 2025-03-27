// Given a string containing: () {} [], create a function that returns true or false 
// depending on whether the symbols are valid.
//Using a stack 
// They are valid if: "[({})]", but not if: "([)]", ")()".

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s){
    stack<char> st;

    for(char c : s){
        if(c == '(' || c == '{' || c == '[') st.push(c); //If it is an opening symbol like '(', '{', or '[', we add it to the stack.
        else if(st.empty() && (c == ')' || c == '}' || c == ']')) return false; //If it is a closing symbol like '(', '{', or '[' and the stack is empty, return false.
        else if((st.top() == '(' && c == ')') || (st.top() == '{' && c == '}' ) || (st.top() == '[' && c == ']' ) ){
           /*The logic is: if c is a closing symbol, the top of the stack must be the corresponding opening symbol.
            If so, we pop an element from the stack and continue the comparison with the next ones.*/ 
            st.pop();
        }
    }
    return st.empty(); //If the stack is empty, the string is valid. Otherwise, if it contains elements, the string is invalid.
}

int main(){
    string example1 = "([{}])";
    string example2 = "({)}";
    string example3 = "){}(";
    cout << "the string = " << example1 << " is valid? " << isValid(example1) << endl; 
    cout << "the string = " << example2 << " is valid? " << isValid(example2) << endl;
    cout << "the string = " << example3 << " is valid? " << isValid(example3) << endl; 
}

//Implementation and idea by Thomas Santiago Beltran Arias in his Data Structures exam.