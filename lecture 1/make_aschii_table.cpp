
#include <iostream>

 
int main()
{ 
   char x[128]={};
    char i=0;
    std::cout<<" aschii code table : "<<std::endl;
    std::cout<<"+-------------------+"<<std::endl;
    std::cout<<"|char    |  aschii  |"<<std::endl;
    std::cout<<"+-------------------+"<<std::endl;
    

   for(i=32;i<=126;i++)
    {   
    std::cout<<"|"<<"   "<<i<<"    "<<"|"<<"   "<<int(i)<<"     "<<"|"<<std::endl;
        
    }
   
    return 0;
}
