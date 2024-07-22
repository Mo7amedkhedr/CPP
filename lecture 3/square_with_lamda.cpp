#include <iostream>

int main()
{
   int x;
   std::cout<<"Enter number : ";
   std::cin>>x;
   [=](){std::cout<<"square of number= "<<x*x<<std::endl;}();
    return 0;

}