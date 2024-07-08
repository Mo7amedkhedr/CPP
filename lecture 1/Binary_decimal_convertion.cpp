#include <iostream>
#include <bitset>


void Binary_to_decimal()
{
     std::string b;
    
    std::cout << "Enter a binary number: ";
    std::cin >> b;
    
    std::bitset<32> bits(b); 
    
    unsigned int decimal_number = bits.to_ulong();
    
    std::cout << "Decimal representation: " << decimal_number << std::endl;
    
}

void decimal_to_binary()
{
     unsigned int d;
    
    std::cout << "Enter a decimal number: ";
    std::cin >> d;
    
    std::bitset<32> bits(d); 
    
    std::cout << "Binary representation: " << bits << std::endl;
}

int main() {

    int n=0;
    
    std::cout<< "  1- binary to dicimal \n  2-dicimal to binary \n choose number (1~2) :  ";
    std::cin>>n;
     
    if(n==1)
    {
        Binary_to_decimal();
    }
    else if (n==2) {
    decimal_to_binary();
    }
    else{
        std::cout<<"please, Enter avalid number  "<<std::endl;
    }
    return 0;
    
}


