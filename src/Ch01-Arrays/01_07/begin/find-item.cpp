#include <iostream>
#include <string>
using namespace std;

template <typename T>
int findItem(const T arr[], size_t size, T target)
{
    for(size_t i = 0; i < size; i++)
    {
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10,20,30,40,50};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "arr_size: " << arr_size << "," << findItem(arr, arr_size , 30) << std::endl;
    return 0;
}
