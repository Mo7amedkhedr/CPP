#include <cstdio>
#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <thread>
#include <tuple>

class MyCustomException : public std::exception{

    public:
    //noexcept ---> don't write throw
    //noexcept (true/false) or //noexcept for expression noexcept(fun())
    const char* what() const noexcept override {
        return "My custom exception";
    }
};

namespace myContainer {
    namespace myVector {
      class MyVector{};
      void push_back(int value){
        //do something
      }
    }
}
class Data{
    int x;
    int y;
    public:
    Data(int x, int y):x(x),y(y){}
};
void fun(std::unique_ptr<int>temp)
{
    std::cout<<*temp<<std::endl;
}
void fun2(std::unique_ptr<int>&temp)
{
    std::cout<<*temp<<std::endl;
}


class FileDeleter{
   public:
   void operator()(FILE *file)const{
    std::cout<<"deleting file"<<std::endl;
    fclose(file);
   }


};

// basic template single argument
template  <typename T>
T division (T num1, T num2)
{
    return num1/num2;
}
// basic template multi argument
template  <typename T, typename U>
 auto division (T num1, U num2) ->decltype(num1/num2)
{
    return num1/num2;
}

//class template
template<typename T > class container{
 
  public:
  T value;
  container(T value):value(value){}
  void print(){
    std::cout<<value<<std::endl;
  }

};

//class template with standalone function 
template<typename T > class container2{
 
  public:
  T value;
  container2(T value):value(value){}
  template<typename U> 
  void add(U val){
    value+=val;
  }
  void print(){
    std::cout<<value<<std::endl;
  }
  
};
// explicit specialization
template<>class container<float>{
    public:
    float value;
    container(float value):value(value+1){
        std::cout<<"explicit specialization"<<std::endl;
        std::cout<<"float value: "<<value<<std::endl;
    }
}; 

// partial specialization
template<typename T,typename U> class array{ // primary template
  public:
  array(T t,U u){
    std::cout<<"primary template"<<std::endl;
  } 
};

template<typename T> class array<T,T>{ // partial specialization
  public:
  array(T t,T u){
    std::cout<<"partial specialization"<<std::endl;
  }

};

// default template arguments
template <typename T, typename U = int>
class A{
    public:
    T t;
    U u;
    A(T t,U u):t(t),u(u){
        std::cout<<"default template arguments"<<std::endl;
    }
};

//const template expression
template <typename T, int size> class myarray{
    public:
    T arr[size];
    myarray(){
        for(int i=0;i<size;i++)
            arr[i]=i;
    }
    void print(){
        for(int i=0;i<size;i++)
            std::cout<<arr[i]<<" ";
        std::cout<<std::endl;
    }
};

// variadic arguments
void print()
{
    std::cout<<" end of print variadic arguments "<<std::endl;
}
template <typename T, typename ... Args> 
void print(T t, Args ... arg)
{
    std::cout<<t<<" ";
    print(arg...);
}

bool comparevalues(){
    std::string name1 ("khedr");
    std::string name2 ("khedr");
    int num1(10);
    int num2(10);
    return std::tie(name1,num1) == std::tie(name2,num2);
}

int main()
{
    std::cout<<comparevalues()<<std::endl;

std::tuple<int,float,std::string>t(1,2.5f,"mohamed khedr");
std::get<0>(t)=10;
std::cout<<std::get<0>(t)<<' '<<std::get<1>(t)<<' '<<std::get<2>(t)<<std::endl;

std::cout<<std::tuple_size<decltype(t)>::value<<std::endl;
std::cout<<std::tuple_size_v<decltype(t)><<std::endl;



  print(1,2,"mohamed",4.5,5.5f,"khedr");
  print(11,12,"mohamed",14.5,15.5f);
  print(17,72,"mohamed",47.5);


    myarray<int, 5>arr2;


    A<double>a(3.5,5);
    A<double,float>a2(3.5,2.5);
    A<double,char>a3(3.5,'a');

    std::cout<<division(3,2)<<std::endl;
    std::cout<<division(3.5,2.5)<<std::endl;
    std::cout<<division(3.5f,2.5f)<<std::endl;
    std::cout<<division(3.5f,2.5)<<std::endl;
   container<int>c(55);
   c.print();
   container<std::string>c2("mohamed khedr");
   c2.print();
   container2<int>c3(55);
   c3.add(10);
   c3.print();
   container<float>c4(5.5);

    
   std::shared_ptr<int >p4 = std::make_shared<int>(10);
   std::shared_ptr<int >p5 = p4;
   std::cout<<"p.use_count() =  "<<p4.use_count()<<std::endl;
   std::cout<<*p4<<' '<<*p5<<std::endl;
    p4.reset();
    std::cout<<*p5<<std::endl;
    std::cout<<"p.use_count() =  "<<p4.use_count()<<std::endl;



    std::unique_ptr<FILE,FileDeleter>file(fopen("example.txt", "w"));
    if(file){
        std::cout<<"File opened successfully"<<std::endl;
        //... write to file...
        fprintf(file.get(), "hello mohamed khedr");

    }
    else{
        std::cout<<"failed to open!!!!!!!!"<<std::endl;
    }
    




   // unique_ptr is ownership smart pointer
   std::unique_ptr<int>p (new int (42));
    std::unique_ptr<Data>p1 = std::make_unique<Data>(2,3);
    std::unique_ptr<int> p2 = std::make_unique<int>(4);
    
    std::unique_ptr<int> p3 = std::make_unique<int>(4);
    
    //p2 = p1; // no error because unique_ptr can't be copied or assigned from one another
  //p1 = p2; ERROR becaue unique_ptr make 1- delete for copy constructor  2- delete for assignment operator 
   p2 = std::move(p3);
  //fun(p3);// ERROR becaue no copy constructor
   fun(std::move(p3));
    fun2(p3);
   std::cout<<*p2<<std::endl; //ERROR becaue unique_ptr has been moved
   std::cout<<p3.get()<<std::endl;
   std::cout<<p3.release()<<std::endl;

auto fndeleter = [](int *p){
  
   std::cout<<"deleting p"<<std::endl;
    delete p;
};

std::unique_ptr<int, decltype(fndeleter)> p10(new int(5), fndeleter);
  // best practise for sockets or file descriptor
 //create class with destructor to close socket or file descriptor


  int *ptr = new int (5);
  if(ptr == nullptr){
    // cerr is standarad output stream for errors
    std::cerr << "Error: memory allocation failed" << std::endl;
    exit(EXIT_FAILURE);
  }
  delete ptr; // stack unwinding




  //myContainer::myVector::MyVector v;
   namespace MyC= myContainer::myVector ;
    MyC::MyVector v;
    using namespace myContainer::myVector;
    push_back(5);
    using namespace std::literals;
    std::this_thread::sleep_for(1s);


  try{
    //throw "exception occurred!!! ";
    //throw std::runtime_error("run time errer ");
    //throw 10;
    throw MyCustomException();
  }
  catch(MyCustomException &e){
    std::cout << "[0]Caught: " << e.what() << std::endl;
  }
  catch(const char* e){
    std::cout << "[1]Caught: " << e << std::endl;
  }
  catch(std::exception& e){
    std::cout << "[2]Caught: " << e.what() << std::endl;
  }
  catch(...){
    std::cout << "[3] work as default Caught: unknown exception" << std::endl;
  }


}
