#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

template<typename T>void print(T data)
{
    std::copy(std::begin(data),std::end(data),std::ostream_iterator<int>(std::cout,"  "));
    std::cout<<"\n";
}
struct data{
    int x;
    int y;

};

/*enum Traffic{
    RED,
    YELLOW,
    GREEN
};*/
enum class Traffic :unsigned char{
    RED,
    YELLOW,
    GREEN
};

enum class colors :unsigned char { // to print with enum class should make operator

    RED = 0,
    YELLOW,
    GREEN
};

std::ostream &operator<<(std::ostream &os, const colors &obj)
{
    switch(obj)
    {
        case colors::RED:
             os<<"RED";
             break;
        case colors::YELLOW:
            os<<"YELLOW";
            break;
        case colors::GREEN:
            os<<"GREEN";
            break;
    }
    return os;
}

/*
 struct / class
 1- can contain fnctions and variables
 2- from memory side members will be allocate in same scope of object and functions will be in .text section
*/
struct myData{
    int ID;
    std::string name;
    void setter(int id, std::string n)
    {
      ID = id;
      name = n;
    }
};

struct myData2{
    int ID;
    char name[20];
   myData2(){ 
    std::cout<<"from constructor"<<std::endl;
    ID=1;
    std::strcpy(name,"khedr"); 
    }
   ~myData2()
   {
     std::cout<<"from destructor"<<std::endl;
    ID=0;
    std::strcpy(name,"ali"); 
   }
};

class dataa{
    private:
    int ID;
    char name[20];
    public:
    dataa()
    { 
    std::cout<<"from constructor"<<std::endl;
    ID=1;
    std::strcpy(name,"khedr"); 
    }
   ~dataa()
   {
     std::cout<<"from destructor"<<std::endl;
    ID=0;
    std::strcpy(name,"ali"); 
   }
  void print();
};

 void dataa::print(){
   std::cout<<"id"<<ID<<std::endl;
    std::cout<<"name"<<name<<std::endl;
  }


class testThis{
    private:
    int ID;
    public:
    testThis(int id) ;
    void print();

};
 testThis::testThis(int id)  {
        this->ID=id;
    }
 void testThis::print(){
 
    std::cout<<"id"<<ID<<std::endl;
 }
int main()
{

testThis obj8(1);
obj8.print();



    dataa obj7;
    obj7.print();
  

  {  myData2 data1;
    std::cout<<data1.ID<<std::endl;
    std::cout<<data1.name<<std::endl;
  }


 myData data;
 data.setter(123,"John");




  int x1 = 0;   //copy intialization
  int x2{};    //value or uniform intialization
  int x3(0);  //direct intialization
  std::cout<<x1<<" "<<x2<<" "<<x3<<std::endl;

  int value ;
  int value2{};
  int value3 = int{};
  std::cout<<value<<"     "<<value2<<"        "<<value3<<std::endl;


std::vector<int>v(2,3);
print(v); // 3  3
std::vector<int>v2{10,3};
print(v2); // 10  3 

//int value4(); // vexing parse

float decimal = 3.14;
int integer =decimal; //implicit cast will convert float to int
std::cout<<integer<<std::endl;
//int integer2 {decimal} // ERROR narrow conversion will cause error
int integer3 {static_cast<int>(decimal)};
std::cout<<integer3<<std::endl;

double doubleValue = 3.14;
int intValue = static_cast<int>(doubleValue); // narrow conversion will cause error
std::cout<<intValue<<std::endl;

/*
data d;
data d2{};
std::cout<<d.x<<"   "<<d.y<<std::endl;
std::cout<<d2.x<<"   "<<d2.y<<std::endl;*/


/*Traffic obj = RED;
//Traffic obj5 = 2; // ERROR should use static_cast
std::cout<<obj<<std::endl;
std::cout<<static_cast<int>(obj)<<std::endl; // output 0
Traffic obj2 = static_cast<Traffic>(1);
std::cout<<static_cast<int>(obj2)<<std::endl; // output 1
Traffic obj3{};
obj3 = static_cast<Traffic>(2); 
std::cout<<obj3<<std::endl; //2
std::cout<<Traffic::YELLOW<<std::endl;
//int num = GREEN; // problem convert from dataType to another dataType
std::cout<<sizeof(obj)<<std::endl;*/

colors obj{};
std::cout<<obj<<std::endl;
std::cout<<colors::YELLOW<<std::endl;
std::cout<<static_cast<int>(obj)<<std::endl; // output 1
colors obj2 = static_cast<colors>(1);
std::cout<<static_cast<int>(obj2)<<std::endl; // output 1
std::cout<<sizeof(obj)<<std::endl;
//int num2 = colors::GREEN; //ERROR 

Traffic obj6 {};
std::cout<<static_cast<int>(obj6)<<std::endl;


return 0;
}


  










