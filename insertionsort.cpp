#include <iostream>
using namespace std;
// insertion sort
int main()
{
    int temp, arr[] = {5, 8, 2, 1, 6, 3};

    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    cout << "[";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]";

    return 0;
}