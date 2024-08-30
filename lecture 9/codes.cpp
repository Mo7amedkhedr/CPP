#include <iostream>
// function overriding
class base{
    public:
    int a;
    base(int a ):a(a){
        std::cout << "Base constructor called" << std::endl;
        std::cout<<a<<std::endl;
    }
   virtual void print() const{
        std::cout << "print from Base" << std::endl;
    }
    // vtable ===> virtual table (dynamic binding) (late binding)
    // interface class
  virtual void display()=0;// pure virtual function
  virtual void display2()=0;// pure virtual function
  virtual void display3()=0;// pure virtual function


};
//abstract class
class baseabstract{
 public:
  virtual void display4(){
    std::cout << "print from baseabstract" << std::endl;
  };

};


class derivedabstract : public baseabstract{
    public:
    void display4() override{
        std::cout << "print from Derivedabstract" << std::endl;
    }
    
};


class derived : public base{

    public: 
     using base ::base ;
    void display()override{
        std::cout << "print from Derived" << std::endl;
    }
    void display2() override{
        std::cout << "print from Derived2" << std::endl;
    }
    void display3() override{
        std::cout << "print from Derived3" << std::endl;
    }
    void print() const override{
        std::cout << "print from Derived" << std::endl;
    }
   
};
class derived2 : public base {

    public:
    void print()const{
        std::cout << "print from Derived2" << std::endl;
    }   
};


void func (base * p){
    p->print(); // dynamic binding happens here
}

void func2(const base &p){
    p.print(); // static binding happens here

}

class dynamic_Cast{

    public:
    virtual void print(){
        std::cout << "print from dynamic_cast" << std::endl;
    }

};
class derived_dynamic_Cast:public dynamic_Cast{
 public:
  void print()override{
        std::cout << "print from derived_dynamic_cast" << std::endl;
    }
  void print2();
};
void derived_dynamic_Cast::print2(){
    std::cout << "print2 from derived_dynamic_cast" << std::endl;
}

void construct_test()
{
    std::string s = "hello, world";  //const char*
    std::cout << s << std::endl;
     std::string str(s); //copy constructor
     std::cout << str << std::endl;
     std::string str2(s, 6); // copy constructor with start and length
     std::cout << str2 << std::endl;
      std::string str3(std::move(str)); // move constructor
     std::cout << str3 << std::endl;
     std::string str4(s.begin(), s.end()); // copy constructor with range   
     std::cout << str4 << std::endl;
      std::string str5(10,'m');
      std::cout << str5 << std::endl;
      std::string str6(str5, 7 , 5);
      std::cout << str6 << std::endl;

}

void string_function()
{
      std::string s = "hello, world";
      std::cout << s << std::endl;
      std::cout << s.size() << std::endl;
      std::cout << s.length() << std::endl;
      std::cout << s.capacity() << std::endl;
      std::cout << s.max_size() << std::endl;
      std::cout << s.empty() << std::endl;
      std::cout << s.find('l') << std::endl;
      std::cout << s.rfind('l') << std::endl;
      std::cout << s.substr(6, 5) << std::endl;
      s.erase(6, 5);
      s.insert(6, "khedr ");
      std::cout << s << std::endl;
      /*replace
      find position 6
      remove 5 element
      insert at position 6
      */
      s.replace(6, 5, "world");
      std::cout << s << std::endl;
      s.push_back('!');
      std::cout << s << std::endl;
      s.pop_back();
      std::cout << s << std::endl;
    //  s.clear();
      std::cout << s.empty() << std::endl;
      if(s.find("hello")==std::string::npos)
      {
        std::cout << "Not found" << std::endl;
      }
      else{
        std::cout << "Found" << std::endl;
      }
      s[0]='M';
      std::cout << s << std::endl;
      // s.at(100)='L';
    //  std::cout << s << std::endl;
      const char *ptr = s.c_str();
}

bool starts_with (std::string body, std::string prefix)
{
    if(body.find(prefix)==0)
    {
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    
    string_function();
    construct_test();

    dynamic_Cast *ptr = new derived_dynamic_Cast();
    ptr->print();
  //  ptr->print2();
   derived_dynamic_Cast *ptr2= (dynamic_cast<derived_dynamic_Cast*>(ptr)) ;
    if(ptr2!=nullptr){
        ptr2->print();
    }



    derivedabstract d4;
    d4.display4();// this is allowed as it is a pure virtual function in baseabstract class
  derived d3(10);
  d3.display();
  d3.display2();
  d3.display3();

    /* *** interface class ***
    1- it is not allowed to create instance from interface class
      //  base b; ERROR
    2- in inherited  class we must implement all the pure virtual function
    
    */

/*
func(new derived);
func(new derived2);
func2(derived());
func2(derived2());
*/
/*derived d;
derived2 d2;
base *ptr = &d;
ptr->print(); // dynamic binding happens here
ptr = &d2;
ptr->print(); // dynamic binding happens here*/

}