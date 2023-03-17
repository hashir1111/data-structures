#include<iostream>
#include<string>
using namespace std;
class stack{
    private:
    int top;
    int arr[5];
    public:
    stack(){
        top=-1;
        for (int i = 0; i < 5; i++)
        {
            arr[i]=0;
        }
        
    }
    bool IsEmpty(){
        if (top==-1)
        {
            return true;
        }
        else{
            return false;
        }
    }
    bool IsFull(){
        if (top==4)
        {
            return true;
        }
        else{
            return false;
        }
    }
    void push(int val){
        if (IsFull())
        {
            cout<<"Stack overflow"<<endl;
        }
        else{
            top++;
            arr[top]=val;
        }
    }
    int pop(){
        if (IsEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else{
            int popvalue=arr[top];
            arr[top]=0;
            top--;
            return popvalue;
        }
    }
    int count(){
        return (top+1);
    }
    int peek(int pos){
        if (IsEmpty())
        {
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else{
            return arr[pos];
        }
    }
    void change(int pos , int val){
        arr[pos]=val;
        cout<<"value change at"<<pos<<endl;
    }
    void display(){
        cout<<"The values in stack are: "<<endl;
        for (int i = 4; i >=0; i--)
        {
            cout<<arr[i]<<endl;
        }
        
    }
};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    // s.display();
    s.pop();
    // s.display();
    s.change(0,3);
    s.display();
return 0;
}