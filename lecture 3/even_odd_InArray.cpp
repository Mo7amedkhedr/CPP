#include <iostream>
#include <vector>
void findEvenAndOdd_numbers(int arr[], int size, std::vector<int>&evens, std::vector<int>& odds) {
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evens.push_back(arr[i]); 
        } 
        else {
            odds.push_back(arr[i]);  
        }
    }
}

int main()
{
  int arr[]={1,22,33,55,44,22,99,66,102,58};
  int size = sizeof(arr) / sizeof(arr[0]);

  std::vector<int> evens, odds;

  findEvenAndOdd_numbers(arr, size, evens, odds);
   std::cout << "even numbers in array : ";
    for (int num : evens) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "odd numbers in array : ";
    for (int num : odds) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}