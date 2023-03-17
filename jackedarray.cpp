#include <iostream>
using namespace std;
int main()
{
    int row = 4;
    int col[] = {1, 2, 3, 4};
    int **arr;
    arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col[i]];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            cout << "Enter Values: " << endl;
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
        {
            cout << arr[i][j];
        }
        cout << endl; 
    }

    return 0;
}