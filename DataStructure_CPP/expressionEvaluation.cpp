#include<iostream>
#include<string>
#include<stack>
using namespace std;
    bool isoperation(char op){
        if(op == '*' ||op == '/' || op == '+' || op== '-'){
            return true;
        }else{
            return false;
        }
    }
    void evaluateExpression(string exp){
        stack<int>s;
        int op1,op2,res;
        string temp;
        char operation;
        for(int i = 0 ; i < exp.length(); i++){
            if(exp[i] == ' '){
                if(!temp.empty()){
                s.push(stoi(temp));
                temp.clear();
                }
            }else if(isoperation(exp[i])){
                operation = exp[i];
                op2 = s.top();
                s.pop();
                op1 = s.top();
                s.pop();
                if(op2 == 0 && exp[i] == '/'){
                    cout << "Error\n";
                    break;
                }
                switch (operation)
                {
                case '*':
                    res = op1*op2;
                    break;
                case '/':
                    res = op1/op2;
                    break;
                case '+':
                    res = op1+op2;
                    break;
                case '-':
                    res = op1-op2;
                    break;
                }
                s.push(res);
            }else{
                temp += exp[i];
            }
        }
        if (!s.empty()) {
            res = s.top();
        }
        
        cout << "Result: " << res << endl;
    }
    int getopWeight(char op){
        int weight =-1;
        switch(op){
            case '-':
            case '+':
                weight =1;
                break;
            case '*':
            case '/':
                weight =2;
                break;

        }
        return weight;

    }
    bool hasHigherPrecedence(char op1 , char op2){

        int op1weight = getopWeight(op1);
        int op2weight = getopWeight(op2);
        return (op1weight > op2weight);
    }
    bool isoperand(char o){
        if(o >= '0' && 0 <= '9') return true;
        else return false; 
    }
    
    string infixtopostfix(string exp){
        stack<int>st;
        string temp,expression;
        char op;
        for(int i = 0 ;  i < exp.length(); i++){
            if(exp[i] == ' ' ){
                if(!temp.empty()){
                    expression += temp;
                    expression += ' ';
                    temp.clear();
                }
            }else if(isoperation(exp[i]) ){
                while(!st.empty() && st.top() != '(' && hasHigherPrecedence(st.top(), exp[i])){
                    expression += st.top() ;
                    expression += ' ' ;
                    st.pop();
                }
                st.push(exp[i]);
            }else if (isoperand(exp[i])){
                temp += exp[i];
            }else if(exp[i] == '('){
                st.push(exp[i]);
            }else if(exp[i] == ')'){
                while (!st.empty() && st.top() != '(') {
				expression += st.top() ;
				expression += ' ' ;
				st.pop();
			}
			st.pop();
            }
        } 
        if(!temp.empty()){
                    expression += temp;
                    expression += ' ';
                    temp.clear();
        }
        while(!st.empty()){
                op = st.top();
                expression += op;
                expression += ' ';
                st.pop();
        }
        return expression;
    }
int main(){
	string expression;
	cout << "Enter Infix Expression \n";
	getline(cin, expression);
	string postfix = infixtopostfix(expression);
	cout << "Output = " << postfix << "\n";
    return 0 ;
}
