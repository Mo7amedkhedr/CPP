#include <iostream>
#include <iterator>

// note if you defined parameter with any value all parameter after it should defined with values otherwise it will give error
void PrintMessage(std::string s = "mohamed khedr")
{   
    std::cout << "Hello, " << s  << std::endl;
     std::cout << "Hello, " << s.substr(5,s.size())  << std::endl;
}
  

  
// function overloading 
// overloading happens with different parameter datatype only


int add (int num1, int num2)
{
    std::cout<<__FUNCTION__<<std::endl;
    return num1 + num2;
}
int add(float num1, float num2)
{
    std::cout<<__FUNCTION__<<std::endl;
    return num1 + num2;
}



void testGDB()
{
    int arr[5] = {1,2,3,4,5}; 
  
    arr[6]=15;
    int num=10;
}

void func_pointer(int *ptr)
{
    std::cout<<__FUNCTION__<<std::endl;
}

void func_ref(int &ref)
{   ref = 100;
    std::cout<<__FUNCTION__<<std::endl;
}

struct data
{
    int x=100;
    int y=10;
    char c=0;
    bool b= false;
};
int main()
{   
    add(1,2);
    add(1.5f, 2.5f);

    PrintMessage();
    PrintMessage("ahmed");
    std::string v("hello");
    std::string v2(" world");
    v.insert(v.end(),v2.begin(),v2.end());
    v.insert(v.begin(),'#');
    v.insert(v.begin(),4,'#'); 
    std::cout << v << std::endl; 

    int arr[5] = {1,2,3,4,5}; 
    arr[0]=10;
    arr[5]=15;
    for(int i=0;i<5;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    testGDB();

   int *ptr = nullptr;
   *ptr = 5;

   int *ptr5 = new int(10);
   std::cout << *ptr5 << std::endl;
   delete ptr5;
   std::cout << *ptr5 << std::endl;
   ptr5 = nullptr;  // set the pointer to nullptr to prevent dangling pointer
   std::cout << *ptr5 << std::endl;  // This will cause a runtime error as we are trying to dereference a nullptr


 int x = 10;
 int &refTox = x;
 int *ptrr = &x;
 std::cout << "x: " << x << std::endl;
 std::cout << "refTox: " << refTox << std::endl;
 std::cout << "ptr: " << ptrr << std::endl;
 std::cout << "*ptr: " << *ptrr << std::endl;
  std::cout << "x: " << &x << std::endl;
 std::cout << "refTox: " << &refTox << std::endl;
 std::cout << "ptr: " << &ptrr << std::endl;
 *ptrr = 20;
 std::cout << "x: " << x << std::endl;
 std::cout << "refTox: " << refTox << std::endl;
  int y = 10;
  func_pointer(&y);
  func_ref(y);
  std::cout << "y: " << y << std::endl; // y will be changed to 100 in func(int &ref)

  int a = 10;
  char c = 'a';
  int *q = (int*)&c;
 // int *p =static_cast<int*>(&c); //ERROR static_cast from char to int is not allowed
  
  const int val =10;
  const int *ptr7 =&val;

  //int *ptr2 = ptr;//ERROR invalid conversion from ( const int *) to (int *)  
  int *ptr3 = const_cast<int*>(ptr7); //OK const_cast from (const int *) to (int *)

  std::cout << "val: " << val << std::endl;
  std::cout << "*ptr3: " << *ptr3 << std::endl;

  *ptr3 = 20;
  std::cout << "val: " << val << std::endl; // 10
  std::cout << "*ptr3: " << *ptr3 << std::endl;//20

  const int *ptr4 = &val;
  //*ptr4 = 20; //ERROR assignment of read-only location '*ptr4'

  int *ptr6 = new int(10);
  delete ptr6;
  *ptr6 = 20; //ERROR deleting a pointer that was not allocated with 'new'


   
   data d;
   int *p= reinterpret_cast<int *>(&d);
   std::cout<<*p++<<std::endl;
   std::cout<<*p++<<std::endl;
    std::cout<<*p<<std::endl;
    return 0;
}