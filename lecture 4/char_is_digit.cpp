#include <iostream>
#include <cctype>


class char_is_digit{
  
public:
    
    void check_is_digit(char character_is_digit);

};
void char_is_digit::check_is_digit(char character_is_digit)
{
    if(std::isdigit(character_is_digit))
    {
       std::cout<<" IS DIGIT "<<std::endl;
    }
    else {
       std::cout<<" IS NOT DIGIT "<<std::endl;
    }
}

int main()
{
    char_is_digit obj;
    obj.check_is_digit('f');
}