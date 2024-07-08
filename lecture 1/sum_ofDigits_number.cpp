#include<iostream>
int main()
{
    int number=0,result=0,sum=0;
    std::cout<<"Enter a number : ";
    std::cin>>number;
    while(number!=0)
    {
        result=number%10;
        sum=sum+result;
        number=number/10;
        
    }
    std::cout<<sum<<std::endl;

    return 0;
}