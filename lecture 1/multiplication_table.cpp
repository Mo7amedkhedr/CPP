
#include <iostream>

int main()
{
    int i=0,j=0;
    
    for(i=0;i<=12;i++)
    {
        for(j=0;j<=12;j++)
        {
            std::cout<<i<<" ";
            std::cout<<"*"<<" ";
            std::cout<<j;
            std::cout<<" = "<<i*j<<std::endl;
        }
       
    }

    return 0;
}