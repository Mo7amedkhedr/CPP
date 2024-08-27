#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>


const int var_global =10;

constexpr int func(int start)
{
    for (int i =start;i<5;i++)
    {
        return i;
    }
    return 5;
}

int main(){

auto f  = [/*capture*/](/*parameter*/)->int
 {
    std::cout<<"hello mohamed khedr" <<std::endl;
    return 5;
 };
  
 std::cout << f()<<std::endl;

auto f2 = [](int x,int y){
    return x + y;
};
std::cout<<f2(5, 6)<<std::endl;

int offset =100;
auto f3 = [offset](int x,int y)->int{
    return x + y+offset;
};
std::cout<<f3(5, 6)<<std::endl;


int offset2;
std::cin >>offset2;
std::vector<int>v{10,13,30,0,1,2,6,3};
std::sort(v.begin(),v.end(),[offset2](int num1,int num2){return (offset2+num1)<(offset2+num2);});
std::for_each(v.begin(),v.end(),[](int num){std::cout<<num<<std::endl;});


int temp=10;
[](int num3){
   // std::cout<<num3 + temp <<std::endl; // ERROR scope of lambda is standalone scope
    
}(3);   



int temp2=10;
[temp2](int num3)   mutable{
    temp2=100;            // ERROR need to be mutable or refrences and the changing will be only in lambda scope with mutable but with reference it will change outside
    std::cout<<temp2 <<std::endl; 
}(3);

std::cout<<temp2<<std::endl; // will print 100 as it changed in lambda scope


int temp3=10;
[&temp3](int num3)   mutable{
    temp3=100;            // ERROR need to be mutable or refrences and the changing will be only in lambda scope with mutable but with reference it will change outside
    std::cout<<temp3 <<std::endl; 
}(3);

std::cout<<temp3<<std::endl; // will print 100 as it changed in lambda scope



int temp4=10;
int value=20;
[&temp4,value](int num) mutable{
    temp4=100;
    value = 200;            // ERROR need to be mutable or refrences and the changing will be only in lambda scope with mutable but with reference it will change outside
    std::cout<<temp4 << std::endl; 
    std::cout<<value << std::endl;
}(3);

std::cout<<temp4<<std::endl; // will print 100 as it changed in lambda scope
std::cout<<value<<std::endl; // will print 20 as it was not changed in lambda scope


int temp5=10;
int value2=20;
[&](int num) {
    temp5=100;
    value2 = 200;            // ERROR need to be mutable or refrences and the changing will be only in lambda scope with mutable but with reference it will change outside
    std::cout<<temp5 << std::endl; 
    std::cout<<value2 << std::endl;
}(3);

std::cout<<temp5<<std::endl; // will print 100 as it changed in lambda scope
std::cout<<value2<<std::endl; // will print 200 as it changed in lambda scope



int temp6=10;
int value3=20;
[=](int num) mutable{
    temp6=100;
    value3 = 200;            // ERROR need to be mutable or refrences and the changing will be only in lambda scope with mutable but with reference it will change outside
    std::cout<<temp6 << std::endl; 
    std::cout<<value3 << std::endl;
}(3);
std::cout<<temp6<<std::endl; // will print 10 as it was not changed in lambda scope
std::cout<<value3<<std::endl; // will print 20 as it changed in lambda scope



void(*ptrTOfunc)(int x) = [](int x){
    std::cout<<"from pointer to function"<<std::endl;
};
ptrTOfunc(2);


int number5=10;
/*void(*ptrTOfunc2)(int x) = [number5](int x){  // ERROR 
    std::cout<<"from pointer to function2"<<std::endl;
};*/
//ptrTOfunc2(2);

int number6=20;
std::function<void (int x)> pf = [number6](int x){
    std::cout<<"from function pointer pf"<<std::endl;
};
pf(6);


auto fn = [](auto num7, auto num8){std::cout <<num7+num8<<std::endl;};
fn(1,2);
fn(1.5,2.5);
fn('3','a');


auto fn2 = [](auto num7, auto num8){return num7+num8;};
std::cout<<typeid(fn2(1,2)).name()<<std::endl;
std::cout<<typeid(fn2(1.5,2.5)).name()<<std::endl;


int temp7 =10;
[&v=temp7,x=5](){
    std::cout<<v<<std::endl;  // will print 10
    std::cout<<x<<std::endl;  // will print 5
    v=100;
}();

std::cout<<temp7<<std::endl;  // will print 100

 
 int var = var_global;
 int array[var_global]={1,2,3,4,5,6,7,8,9,10};
 switch (var) {
    case var_global:
        for(int i=0;i<var;i++){
            std::cout<<array[i]<<std::endl;
        }
        break;
    default:
        std::cout<<"Error: Invalid input."<<std::endl;
        break;
 }

  
  int *ptrr =new int(var_global);
  //int *ptrr2=var_global;//ERROR you can solve it with static_cast



int x ;
std::cin>>x;
const int var1=x;
//constexpr int var2=x; //ERROR 

constexpr int x1 =func(3);
//constexpr int x2 = func(rand());//ERROE  
 return 0;
}