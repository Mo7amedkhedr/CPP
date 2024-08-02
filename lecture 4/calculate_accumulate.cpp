#include <iostream>
#include <numeric>





int main(){
  int arr[]= {1,2,3,4,5,6,7,8,9,10};
  int size = sizeof(arr)/sizeof(arr[0]);

  int sum = std::accumulate(arr,arr+size,0);
  std::cout << "Sum of array elements: " << sum << std::endl;

  return 0;

}