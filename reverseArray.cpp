// This program contains a function which will reverse an array from
// index l to index r
//  Including the required headers
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> reverseArray(vector<int> arr, int l, int r)
{
    while (l < r)
    {
        swap(arr[l++], arr[r--]);
    }
    return arr;
}

int main()
{
    // Sorting an array using two pointers
    vector<int> arr;
    for (int i = 0; i < 5; i++)
    {
        arr.push_back(i);
    }
    vector<vector<int> > operations;
    vector<int> ops;
    ops.push_back(0);
    ops.push_back(4);
    operations.push_back(ops);
    ops.clear();
    ops.push_back(2);
    ops.push_back(3);
    operations.push_back(ops);
    ops.clear();
    ops.push_back(1);
    ops.push_back(2);
    operations.push_back(ops);

    for (int i = 0; i < operations.size(); i++)
    {
        vector<int> operation = operations[i];
        arr = reverseArray(arr, operation[0], operation[1]);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
