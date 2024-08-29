#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

class String
{
private:
char *str;
int size;
// if the all data is trivial data types {int, double,float ,char, bool ,{struct,class but without any constructor or functions}}

public:
String(const char *str){
    size = strlen(str);
    this->str = new char[size+1];
    strcpy(this->str, str);
}
void fun(){
    std::cout<<str<<std::endl;
}
/*
=====> why copy constructor is must be const and &
 implicit constructor is created
 String(const String &obj)
 {
 size = obj.size;
 str = obj.str;
 }
*/

 //copy constructor
 // This constructor is called when an object is created from an existing object of the same class.
 // It is used to initialize the object using the values of the existing object.
 // The copy constructor is used to create a new object as a copy of an existing object.
 // It is a special member function that is automatically called when an object is created from an existing object of the same class.
 // The copy constructor is a constructor that takes an object of the same class as a parameter and initializes the new object using the values of the existing object.
 // The copy constructor should have the same name as the class and should not have a return type.
 // The copy constructor should have a parameter that is a reference to the class type.
 // The copy constructor should initialize the new object using the values of the existing object.
 // The copy constructor should use the initialization list to initialize the member variables of the class.
 // The copy constructor should not change the state
 // T (const T & obj)
 // copy data from obj to this
String(const String &obj)
{   
    size = obj.size;
    str = new char[size+1];
    strcpy(str, obj.str);
}
void setchar(char value){*str = value;}
~String(){
    delete[] str;
    std::cout<<"destructor String called"<<std::endl;
}

};

String /*temp*/get_instance()
{
  static char array[]="helloo from instance";
  String t1 (array);
 return t1;

}

class String2{
private:
public:
int *ptr;
String2(int value){
   this-> ptr = new int(value);
    std::cout<<" constructor string2"<<std::endl;
}
String2 (const String2 &obj){
     std::cout<<" copy constructor string2"<<std::endl;
}
//destructor
~String2(){
    delete ptr;
    ptr=nullptr;
    std::cout<<"destructor string2"<<std::endl;
}
String2 & operator=(const String2 &obj)
{

    //self assignment check
    if(this == &obj){
       return *this;
    }

    //clean before starting
    if(this ->ptr){
       delete this->ptr;
      this-> ptr = new int(*obj.ptr);
   
    }
    //clean before starting
    if(this ->ptr){
       delete this->ptr;
      this-> ptr = new int(*obj.ptr);
    
   
    }
    return *this;
}
};

String2/*temp*/  get_instance2()
{
  String2 t1(5) ; //1 constructor string2
  return t1;//2  copy constructor called here first time temp(t1)
  // destructor when return t1
}

/*value category
   Lvalue ---> name + address
   Rvalue ---> temp + no name
   Xvalue ---> identity + moved
*/

int &fun()
{
    static int i = 5;
    return i;
}
int /*temp*/ func2()
{
    static int i2 = 10;
    return i2;
}
 /*type category 
 {left value reference ---> alias to Lvalue 
  , right value reference  -----> alias to Rvalue (movement to location )}
  */
void function0(int x){}
void function1( int &x){}
/*const left value refrence still also alias to Lvalue*/
void function3(const int &x){}



int main()
{

  const int &ref3 =10;// temp = 10 ref3 is an alias to temp

   function0(1); // works because x ---> Lvalue and 1 ---> Rvalue
  int var2 =10;
  function0(var2);// works var is Lvalue in expression itself which means x = var ---> x =10  (rvalue)
  int &ref1 = var2;
  function0(ref1);// works ref is Lvalue in expression itself which means x = var   (rvalue)
 // function1(1);  // doesn't work because 1 ----> Rvalue
  function1(var2); // Left value ref ---> alias to Lvalue
  function1(ref1); // ref1 also left value

  function3(1);     //  const lvalue ref  can ref to Rvalue || ref to to ---> Rvalue = temp
  function3(ref1); // ref1 also left value
  function3(var2);// var2 also left value
 

    std::string name1 = "mohamed"; // name1 is Lvalue
    std::string name2 = std::move(name1); // name2 is Lvalue
    std::cout<<name2<<std::endl; // it works
      std::cout<<name1<<std::endl; // it is empty, it is moved ,so let's consider that the name1 now is a Xvalue
   
 int y = 10;
  int &x2 = y; //value category of x2 is Lvalue and type category of x2 is Lvalue reference 
  // int &temp2 =10; //ERROR because LvalueREf must be intialized with Lvalue
   
   int &&rvalueref =10; // it is right value reference
   //value category of x2 is Lvalue and type category of x2 is Right value reference 

 // int &&rvalueref2 = y; //REF to Rvalue ERROR because y has it is sole owner ship  
  
  int &&rvalueref3 = std::move(y); // ref to Rvalue. y is a lvalue but the return value of std::move(y) is a RVALUE and sole owner ship

    
   fun()/*Lvalue*/=10/*Rvalue*/;
    int x /*Lvalue*/ = fun()/*now -> Rvalue because it becones as value =10*/;
    
    std::cout<<fun()<<std::endl;
    std::cout<<x<<std::endl;
   
  // func2() = 100; // ERROR because i2 return in int as temporary which doesn't have an address so ------> func2() become as Rvalue
    
    int left = func2();

    std::cout<<left<<std::endl; //10

    
  

  String2 t4(5);
  String2 t5(10);

   t5=t4; // assigning which means t3.operator =t2 , there is no creation 
   *(t5.ptr)=10;
   std::cout<<*(t4.ptr)<<std::endl;
   t5=t5;//self assigning*/
  // String2 t1(get_instance2());//3   copy constructor call here when t1(temp)
  // destructor when temp goes out of scope
 // destructor when t1goes out of scope
   
   char array[]="hello";
    String t1(array);
    String t2(t1);
    t2.fun();

  
    char array2[]="hello";
    String t3(array2);
    // it doesn't work in c++14 
    //get_instance() will return an temporary objct which means this one will be RVALUE (temporary can not be refered to &)
    //cont datatype &
    //datatype && =====>RVALUE
    String t6(get_instance());
    t3.setchar('a');
    t3.fun();
    t6.fun();
  

     return 0;

}
