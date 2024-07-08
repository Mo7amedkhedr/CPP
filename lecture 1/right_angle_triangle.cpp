#include <iostream>

int main()
{
    int i,j;
    int row=0;
    std::cout<<"enter number  of rows :  ";
    std::cin>>row;
    for(i=1;i<=row;i++)
    {  
        for(j=1;j<=i;j++)
        {
            std::cout<<"*";
            
        }
        std::cout<<std::endl;
      
    }
}