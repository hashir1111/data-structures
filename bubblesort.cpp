#include <iostream>
using namespace std;
// bubblesort
int main()
{
    int temp, arr[] = {5, 8, 2, 1, 6, 3};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            if (arr[j] >= arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
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