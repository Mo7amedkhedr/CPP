#include <iostream>
#include <cstring>

#include <string>
#include <utility>

class String
{
private:
int size;
char *str;
public:
String(const char *str){
    size = strlen(str);
    this->str = new char[size+1];
    strcpy(this->str, str);
}
void fun(){
    std::cout<<str<<std::endl;
}
String( const String &obj)
{   
    size = obj.size;
    str = new char[size+1];
    strcpy(str, obj.str);
}
//move constructor

String (String &&obj) {

    std::cout <<"move constructor"<<std::endl;
    //move trivial data from t6 to t5
    // reset t6
    //for new instance
    size = obj.size;
    obj.size= 0;
    //for old instance
    str = obj.str;
    obj.str = nullptr;


};
void setchar(char value){*str = value;}
~String(){
    delete[] str;
    std::cout<<"destructor String called"<<std::endl;
}


String& operator=(const String& other)
{
    std::cout<<"copy assignment"<<std::endl;
    if(this!= &other){
        delete[] str;
        size = other.size;
        str = new char[size+1];
        strcpy(str, other.str);
    }
    return *this;
}


String& operator=(String&& obj){

    std::cout<<"move assignment"<<std::endl;
    if(this!= &obj){
        return *this;
    }
    this->size = obj.size;
    delete[] this->str;
    this->str = obj.str;
    obj.size = 0;  // reset obj
    obj.str = nullptr;
    return *this;
}


};
String getString()
{
    String t1("Hello"); // 1create
    return t1; // copy temp
}


//Rule Zero
class mydata{

    std::string name;

    public:
    mydata(std::string name):name(name){
        std::cout<<" constructor"<<std::endl;
    }
    mydata(const mydata& obj)=delete;
    mydata(mydata&& obj)=delete;
    mydata &operator=(const mydata& obj)=delete;
    mydata &operator=(mydata&& obj)=delete; 
    virtual ~mydata()=default;

};

class base{
 std::string name;
 public:
 base(std::string name):name(name){
     std::cout<<"base constructor"<<std::endl;
 }
 base(){
     std::cout<<"base default constructor"<<std::endl;
 }
 void print(){
     std::cout<<"print in base "<<std::endl;
 }
  

  ~base(){
     std::cout<<"base destructor"<<std::endl;
  }
};

class derived : public base{
 
 public:
 int id = 10;
 derived(std::string name):base(name){
     std::cout<<"derived constructor"<<std::endl;
 }
 derived(){
     std::cout<<"derived default constructor"<<std::endl;
 }

 ~derived(){
     std::cout<<"derived destructor"<<std::endl;
 
 }
} ;
 // derived2 (inherit) derived (inherit) base ----> multilevel inheritence
class derived2 : public derived{
 
 public:
 int id = 12;
 derived2(std::string name):derived(name){
     std::cout<<"derived2 constructor"<<std::endl;
 }
 derived2(){
     std::cout<<"derived2 default constructor"<<std::endl;
 }

 ~derived2(){
     std::cout<<"derived2 destructor"<<std::endl;
 
 }
} ;

// hr (interit) employee finance (interit) employee also ------>hirerecal


int main()
{ 
    derived d;
    d.print();



 /* mydata mohamed ("mohamed");
  mydata d_name1(mohamed); //copy constructor
  mydata d_name2(std::move(mohamed)); //move constructor
   mydata d_name3(mohamed); //copy constructor
   d_name3 = d_name2; //copy assignment
   d_name3 = std::move(d_name2); //move assignment*/










    /* 5 Rule
    1- copy constructor
    2- copy assignment
    3- move constructor
    4- move assignment
    5- destructor
    
    */


 String mo("mohamed");
 String ah("ahmed");
 ah=std::move(mo);
 ah.setchar('D');
 ah.fun();
 mo.fun();
 std::cout<<"--------------------------------"<<std::endl;
 //std::cout<<ah<<std::endl;
 String t3(getString()); // copy from temp to t3
 //std::cout<<t3<<std::endl;
 String t4(std::move(getString())); // move from temp to t4
 //std::cout<<t4<<std::endl;

   






  String name("mohamed");
   //name2 replace with name ..... name2 become alias to name but name2 --> && (Rvalue ref) so should convert name to temp so name2 become alias to temp of name */
   /*value category name2 ---> lvalue
    type category   name2 ---> rvalue ref
    */
    //Rvalue reference  it is a reference so this one will be considered as a {optimization}
String &&name2(std::move(name)); // here no intiation 
   /*name3 will take the ownership from name take data from name and make name ==0 */
    /*value category name2 ---> lvalue
    type category   name3 ---> string
    */
   String name3(std::move(name));
 /** std::cout<<name<<std::endl;
   std::cout<<name2<<std::endl;
   std::cout<<name3<<std::endl;
*/
  /*priorities of constructor
  1- move constructor
  2- copy constructor

  */

 





  String t1 ("khedr");  
 String t6("mohamed");
 String &&t2 ( getString()); // copy from temp to t2
 //String &&t3(std::move(t1));
  //String &&/*type RvalueREF*/t4(std::move(t1/* Lvalue */));
 // 1- i need to convert t1 (lvalue) to Rvalue ----> std::move(t1)
 // 2- i need to handle the move constructor 
 String t5 = std::move(t6);//move constructor this constructor will be called when you will move instance from t6 ==>should be Rvalue (std::move) to t5

std::cout<<"start"<<std::endl;
//std::cout<<t4.str<<std::endl; // crash happen here
std::cout<<"end"<<std::endl;

 return 0;
 



}