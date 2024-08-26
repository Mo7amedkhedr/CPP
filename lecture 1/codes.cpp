#include <cassert>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

int global_value = 10; 

int ScoreOfString(std::string s)
{
  int result =0;
  for(int i = 0 ;i < s.size()-1 ; i++)
  {
    result += abs(s[i] - s[i+1]);
  }
  return result;
}

int FinalValueAfterOperation(std::vector<std::string> operations)
{
   int x=0;
   for(std::string var : operations)
   {
    if(var == "X++" || var == "++X" || var =="x++" || var =="++x")
    {
      x++;
    }
    else{
      x++;
    }
   }
return  x;
}

int main()
{
  
  std::vector<int> myVector;
  int myint;
  std::cout<<"please enter some integers (enter 0 to end)\n";
  do{
    std::cin>>myint;
    myVector.push_back(myint);
  }while(myint);
  std::cout <<"my vector stores "<<int(myVector.size()-1)<<std::endl;


std::cout<<"hello world"<<std::endl;

printf("hello world from printf \n");

std::cout<<5<<std::endl;


int x=0;
int y=0;
std::cin>>x;
std::cin>>y;
std::cout<<"x = "<<x<<" y = "<<y<<std::endl;


int num1=0;
int num2=0;
std::cout<<"Enter two integers: ";
std::cin>>num1>>num2;
if(num1>num2)
{
  std::cout<<num1<<" is greater than "<<num2<<std::endl;
}
else if (num1<num2) {
 std::cout<<num1<<" is less than "<<num2<<std::endl;
}
else{
  std::cout<<num1<<" is equal to "<<num2<<std::endl;
}


// Ctrl +  shift + a => to open c++ Reference
// Ctrl + shift + o => to open properties
// mainpulators  find in <iomanip>


std::cout <<
"default true "<<true<<'\n'
<<"default false "<<false<<'\n'
<<std::boolalpha
<<"boolAlpha true "<<true<<'\n'
<<"boolAlpha false "<<false<<'\n'
<<std::noboolalpha
<<"noboolalpha true "<<true<<'\n'
<<"noboolalpha false "<<false<<'\n';


std::cout<<"number 55 in octal =  "<<std::oct<<std::showbase<<55<<'\n'
      << "number 55 in decimal =  "<<std::dec<<std::showbase<<55<<'\n'
      << "number 42 in hexadecimal =  "<<std::hex<<std::showbase<<42<<std::dec<<'\n';


std::cout<<std::dec<<10<<std::endl;
std::cout<<std::hex<<10<<std::endl;

std::cout<<"number with show point : "<<std::showpoint<<1.0<<std::endl;



int num = 42;
std::cout<<"number with width 10 : "<<std::setw(10)<<num<<std::endl;
std::cout<<"number with fill character 'x' : "<<std::setfill('x')<<std::setw(10)<<num<<std::endl;



double pi = 3.141596786565656;
std::cout<<std::fixed<<std::setprecision(4)<<"Pi = "<<pi<<std::endl;
std::cout<<std::scientific<<std::setprecision(4)<<"Pi = "<<pi<<std::endl;
 
 
int local_value = 11;
std::cout<<"global_value = "<<global_value<<std::endl;
std::cout<<"local_value = "<<local_value<<std::endl;




//note : we can not declare variable after case it will exploit ERROR but when we make case with scope {} it will work correctly
int value = 10;
const int value_const = 10;
switch (value) {
  case value_const:
  std::cout<<"work correctly with const "<<std::endl;
  break;
  default:
  std::cout<<"default"<<std::endl;}


for(int i=0;i<11;i++)
{
  std::cout<<i<<std::endl;
}



int x2 =5;
while(x){
  std::cout<<x--<<std::endl;
}


int arr[5]={1,2,3,4,5};
std::vector<int> v {10,11,12,13,14};
std::string str("mohamed khedr");
for(int i : arr)
{
  std::cout<<i<<std::endl;
} 
std::cout<<std::endl;
for(auto i :v)
{
  std::cout<<i<<std::endl;
} 
for(auto i : str)
{
  std::cout<<i<<std::endl;
} 

assert(ScoreOfString("hello")==13);
assert(FinalValueAfterOperation({"X++" , "++X", "--X", "X--"})==0);

return 0;
}
