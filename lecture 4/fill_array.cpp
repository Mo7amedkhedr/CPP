#include <iostream>
#include <vector>

int main() {
    const int start = 10;
    const int end = 10000;

    
    int size = end - start + 1;
    std::vector<int> numbers(size);

    for (int i = 0; i < size; ++i) {
        numbers[i] = start + i;
    }
    std::cout << "Array elements:" << std::endl;
    for (int i = 0; i < size; ++i) 
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

}