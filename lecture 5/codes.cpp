#include <iostream>
#include <ostream>

class base{

    public:
    void print(){
        std::cout << "Base class print function" << std::endl;
    }
};


class myData : public base{
/*private:
int a;
int b;
public:
myData(){  //default constructor
    std::cout<<"default constructor"<<std::endl;
}
myData(int a):a(a) // called intialzer list
{
    std::cout<<"parametized constructor with a"<<std::endl;
   // this->a=a;
}
myData(int a, int b): myData(a) //delgation constructor 
{  //parametized constructor
    std::cout<<"parametized constructor with a and b"<<std::endl;

this->b=b;
}*/
public:
myData()=delete;
void print()=delete;
myData (bool a, int &,int l);
bool a = true;
int &number; //refrence must be in intializer list
const int l ;//const must be in intializer list

};

myData::myData(bool a, int &number,int l):a(a),number(number),l(l){
    std::cout<<"parametized constructor with a and reference and const"<<std::endl;
    //this->a=a;
    //this->number=number;
}

class test{
private:
mutable int a;
int b;
static int value_static;
int &number;
int *ptr;

public:
test(int a, int b):a(a),b(b),number(this->a){
    std::cout<<"Parametized constructor"<<std::endl;
}
int getter(int temp) const{
  // a = 5 ERROR You can't modify any variables(members)
  // you can create local variables and change them
  // but you can't change the value of a or b
  //you can use mutable if you would like to modify the variable
   a = temp; 
 int myvalue = 10;
   myvalue++;
   // you can modify the parameter value as well
   temp++;
   //you can modify static member 
   value_static++;
   //you can modify reference member value
   number=100;
   
    return a;
}
int getter(int temp)
{
    return a;
}

// mira rule prevents you to return * or & 
int *getptr(){return ptr;}
int &getnumber(){return number;}


void func() const{}
void func2(){}

};

int test::value_static=0;


class temp; //forward declaration
 void fun();
class train {
private:
friend class temp; // friend class
friend void fun() // friend function
{
    std::cout<<"fun from train"<<std::endl;
    train obj2(1,2);
    std::cout<<obj2.a<<std::endl;
    std::cout<<obj2.b<<std::endl;

}
friend std::ostream &operator<<(std::ostream &os, const train &data) //friend operator overloading
{
    os<<data.a<<","<<data.b;
    return os;
}
int a;
int b;

public:
train(int a, int b):a(a),b(b)
{

}

};

class temp{
public:
temp()
{
    std::cout<<"temp constructor"<<std::endl;
    // you can modify any member of train class
    train obj1(1,2);
    std::cout<<obj1.a<<std::endl;
    std::cout<<obj1.b<<std::endl;
}

};

class train_static{
 public:
 train_static(){
     value_static++; // increment static member
 }
 // static member is not related to instance , it is related to the class itself
 static int value_static;
 static const int max = 5; // it is related to class and also it is constant
 static const int min; 
 static const int temp; // ERROR when if you would like to define in constructor
 static const float pi; //ERROR non integral so should definition outside
private:

};

int train_static::value_static=1; // definition should be outside the class
const int train_static::min = 1; //can intialize outside the class
const float train_static::pi = 3.14;

class trick{
    public:
trick(){}
static const int temp ;

};
void getbyref(const int &a){}
const int trick::temp=5;



class complete_static{
public:
complete_static(){
     std::cout<<"complete static constructor"<<std::endl;
}
static void func(){ // static function related to class not instances
     std::cout<<"complete static function"<<std::endl;
   //  temp=10;//ERROR cannot access to (this)
   number=200; // work 
}
int temp;
static int number ;
};
int complete_static::number=20;

int main()
{ 
    complete_static::func(); // calling from class name and instance 
    complete_static obj1;
    obj1.func();

   
   /*getbyref(trick::temp);
  std::cout<<trick::temp<<std::endl;
  // std::cout<<10<<std::endl;*/



/**
 train_static obj9;
 train_static obj10;
 train_static obj11;
 train_static obj12;

    std::cout<<train_static::value_static<<std::endl;  // you can access the static member from class name
    std::cout<<obj9.value_static<<std::endl;  // you can access the static member from object
   std::cout<<train_static::max<<std::endl;
   std::cout<<obj10.min<<std::endl;*/
  
  /*temp t;
  fun();*/







   /* const test obj1(1,2); // const instance can only call const member functions
    obj1.getter(5);
    test obj2(1,2);//normal instance it will call normal function if there is also const function
    obj2.getter(6);//non const instance can call both const and non const member functions
   obj2.func();
   obj2.func2();

   obj2.getnumber()=1111100;
   std::cout<<obj2.getter(2)<<std::endl;

*/

 // call default constructor
 
 //1-myData obj1;
 //2- myData obj2{};
 //3-myData obj3 = myData(); 
 
 
 // call parametrized constructor
 //1- myData obj4(5,10);
 //2-myData obj4 = myData(5,10);

//myData obj5 {2,5}; //aggregate intialization
//myData obj6 = myData(2,3);
//myData obj7(6);
//myData{}; //ERROR call deleted constructor
/*int x=10;
myData obj8(true,x,10);*/
//obj8.print();

 return 0;


}