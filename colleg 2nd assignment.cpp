#include <iostream>
using namespace std;

class Stack {
    int top = -1;
    int stk[100];
    int length = 100;

    public:

        void push(int val) {
            if (top>=length-1) {
                cout<<"Stack Overflow"<<endl;
            }
            else {
                top++;
                stk[top]=val;
            }
        };

        void pop() {
            if (top<0) {
                cout<<"Stack Underfow"<<endl;
            }
            else {
                cout<<stk[top]<<" was popped from stack!"<<endl;
                top--;
            }
        }

        void display() {
            if (top>=0) {
                cout<<"[ "<<stk[top]<<endl;
                for (int i=top-1; i>=1; i--) {
                    cout<<"  "<<stk[i]<<endl;
                }
                cout<<"  "<<stk[0]<<" ]";
            }
            else {
                cout<<"Stack is empty!";
            }
        }

};

int main() {
    Stack myStack;
    myStack.push(10);
    myStack.push(15);
    myStack.push(15);
    myStack.push(17);
    myStack.push(69);
    myStack.pop();
    myStack.display();
    return 0;
}