#include<iostream>
using namespace std;
class queue{
    private:
    int front;
    int rear;
    int arr[5];
    public:
    queue(){
        rear=-1;
        front=-1;
        for (int i = 0; i < 5; i++)
        {
            arr[i]=0;
        }
        
    }
    bool IsEmpty(){
        if (rear==-1 && front==-1)
        {
            return true;
        }
        else{
            return false;
        }
        
    }
    bool IsFull(){
        if (rear==4)
        {
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int val){
        if (IsFull())
        {
            cout<<"Queue is Full"<<endl;
        }
        else if (IsEmpty())
        {
            rear=0;
            front=0;
            arr[front]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }
    int dequeue(){
        int x;
        if (IsEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        else if (rear == front)
        {
            x=arr[front];
            arr[front]=0;
            rear=-1;
            front=-1;
            return x;
        }
        else{
            x=arr[front];
            arr[front]=0;
            front++;
            return 0;
        }
    }
    int count(){
        return (rear-front+1);
    }
    void display(){
        cout<<"the values of queue are: "<<endl;
        for (int i = 0; i < 5; i++)
        {
            cout<<arr[i]<<endl;
        }
        
    }

};
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
      
return 0;
}