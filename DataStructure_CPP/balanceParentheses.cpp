#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool arepaired(char open , char close){
    if(open == '(' && close == ')'){
        return true; 
    }else if(open == '{' && close == '}'){
        return true; 
    }else if(open == '[' && close == ']'){
        return true; 
    }else{
        return false;
    }

}
bool arebalanced(string exp){
    stack<char> s ;
    for(int i= 0 ; i < exp.length();i++){
        if(exp[i] == '[' ||exp[i] == '{' ||exp[i] == '('){
            s.push(exp[i]);
        }else if(exp[i] == ']' ||exp[i] == '}' ||exp[i] == ')'){
            if(s.empty() || !arepaired(s.top(),exp[i])){
                return false;
            }else{
                s.pop();
            }
        }
    }
    return s.empty();
}
int main(){
    string expression;
    while(true){
    cout << "enter an expression : ";
    cin >> expression;
    if (arebalanced(expression)) {
        cout << "balanced \n";
    }else{
        cout << "not balanced \n";
    }
    }

    return 0 ;
}