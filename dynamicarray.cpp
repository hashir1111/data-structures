//Dynamic Array
#include<iostream>
// #include<string>
using namespace std;
int main(){
    int size;
    int *ptr;
    ptr =new int[size];
    cout<<"Enter the size of an array: "<<endl;
    cin>>size;
    cout<<"Enter the values of an array: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cin>>ptr[i];
        cout<<endl;
    }
    cout<<"[";
    for (int i = 0; i < size; i++)
    {
        cout<<ptr[i];
        if (i<size-1)
        {
            cout<<" , ";
        }
        
        
    }
    cout<<"]";
    return 0;
}    