// Including the required headers
#include <iostream>
using namespace std;

int arr[10] = {10, 20, 30, 40, 50, 60, 90, 100, 110, 120};

void binarySearch(int start, int end, int search_value)
{
    int mid = (start + end) / 2;
    if (arr[mid] > search_value)
    {
        end = mid;
        binarySearch(start, end, search_value);
    }
    else if (arr[mid] < search_value)
    {
        start = mid;
        binarySearch(start, end, search_value);
    }
    else if (arr[mid] == search_value)
    {
        cout << " The element is in the index position " << mid << "\n";
    }
    else
    {
        cout << "Value does not exist in the array \n";
    }
}

int main()
{
    binarySearch(0, 10, 11);
    return 0;
}
