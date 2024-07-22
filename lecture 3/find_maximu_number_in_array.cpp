#include <iostream>
#include <ostream>
#include <algorithm>


void find_max(int arr[],int size)
{
    std::cout<<"max number in array is : "<<*std::max_element(arr,arr+size)<<std::endl;
}
int main()
{
 int arr[] = {1,2,1,5,98,100,0,6,74,-2,7};

 int size = sizeof(arr)/sizeof(arr[0]);
 
 find_max(arr, size);
}