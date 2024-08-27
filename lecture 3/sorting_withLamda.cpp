
#include <iostream>
#include <algorithm> 
#include <vector>    

int main() {
   
    std::vector<int> arr = {100,5,33,22,88,92,32,0,1,55};

  
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return a < b; 
    });

    std::cout << "Sorted in ascending : ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

   
    std::sort(arr.begin(), arr.end(), [](int a, int b) {
        return a > b; 
    });

    std::cout << "Sorted in descending : ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}