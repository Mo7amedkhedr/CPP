#include <iostream>
#include <algorithm> 

int main() {
    int number1, number2, number3;
    
    
    std::cout << "Enter three numbers : ";
    std::cin >> number1 >> number2 >> number3;
    
  
    int max_value = std::max(std::max(number1, number2), number3);
    
   
    std::cout << "The maximum number is: " << max_value << std::endl;
    
    return 0;
}