#include <iostream>
 int main()
{

    char x;
    std::cout<< "Enter a character :  ";
    std::cin>>x;

    if(x=='A'||x=='E'||x=='I'||x=='O'||x=='U'||x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
    {
        std::cout<<"letter is vowel"<<std::endl;
    }
    else
    {
        std::cout<<"letter is not vowel"<<std::endl;
    }
    return 0;


}  