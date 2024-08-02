#include <iostream>

class BackTrace
{   std::string name;
    public:
        BackTrace(std::string name):name(name)
        {
            std::cout<<"Enter "<<name<<std::endl;
        }

        ~BackTrace(){std::cout<<"Exit "<<name<<std::endl;}
};
void fun1()
{
    BackTrace obj(__PRETTY_FUNCTION__);
}
void fun2()
{
    BackTrace obj(__PRETTY_FUNCTION__);
    fun1();
}
void fun3()
{
    BackTrace obj(__PRETTY_FUNCTION__);
    fun2();
}
int main()
{
    BackTrace obj1(__PRETTY_FUNCTION__);
    fun1();
    fun2();
    fun3();
    return 0;
}