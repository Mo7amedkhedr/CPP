#include <iostream>
#include <string>

struct myData
{
 int ID;
 std::string name;
 void setter (int id, std::string n)
 {
     ID = id;
     name = n;
 }

};


int main()
{
 myData obj;
obj.setter(100, "mohamed khedr");
  return 0;

}