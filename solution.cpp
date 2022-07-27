// Including the required headers
#include <iostream>
#include <unordered_map>
#include <vector>
#include <iterator>
using namespace std;


int main()
{
    //Sorting an array using two pointers
    unordered_map<int, int> count;
    count[1] = 5;
    count[2] = 8;
    count[3] = 2;
    vector<int> arr; 
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);


    vector<int> sortedArray;
    for (int i = 0; i < 2; i++)
    {
        for (int j = i+1; j < 3; j++)
        {
            vector<int>::iterator ptr = arr.begin();
            if (count[arr[i]] > count[arr[j]] )
            {
                advance(ptr, i);
               sortedArray.push_back(arr[i]);
               arr.erase(ptr);
            }
            else
            {
               advance(ptr, j);
               sortedArray.push_back(arr[j]);
               arr.erase(ptr);
            }
        }
        
    }
    
    for (int m = 0; m < sortedArray.size(); m++)
    {
        cout << sortedArray[m] << "\n";
    }
    
    return 0;
}
