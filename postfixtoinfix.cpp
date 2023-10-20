// Postfix to infix implementation

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string postfixToInfix( string postfix){

    stack <string> stack;
    string infix;

    for(int i=0;i<postfix.length();i++){

        char c=postfix[i];


        if(isalnum(c)){  //for non operator
            stack.push(string(1,c));
        }
        else if(isspace(c)){
            continue;
        }
        else{  //for operator
            string op2=stack.top();
            stack.pop();

            string op1=stack.top();
            stack.pop();

            string op3 ='(' + op1 + c + op2 + ')';
            stack.push(op3);

        }
       

    }
    return stack.top();
}
int  main(){
   
    string postfix="ab+c/fdg*-";
    cout<<"Postfix expression is : "<<postfix<<endl;
    cout<<"Infix expression is : "<<postfixToInfix(postfix);
    return 0;
}
