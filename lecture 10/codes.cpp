#include <cstring>
#include <functional>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <array>
#include <vector>
#include <set>
class EnhanceString : public std::string{
 public:
 using std::string::string;
 bool starts_with (std::string prefix)
 {
    if(this->find(prefix)==0)
    {
     return true;
    }
    else{
        return false;
    }
}

void to_upper(){
    std::transform(this->begin(), this->end(), this->begin(), ::toupper);
}

void to_lower(){
    std::transform(this->begin(), this->end(), this->begin(), ::tolower);
}

void reverse(){
    std::reverse(this->begin(), this->end());
}

};

constexpr int MAX_SIZE = 5;
class String : public std::array<char, MAX_SIZE>{
    public:
    String(const char*str){
        strncpy(data(), str, MAX_SIZE);
    }
    void print()const{
        std::for_each(begin(),end(),[](char c){
            std::cout<<c<<" ";
        });
        std::cout<<std::endl;
    
}};

class person{
    public:
    std::string name;
    int age;
    person (const std::string &n, int a ):name(n), age(a){
        std::cout<<"constructing person"<<std::endl;
    }
    person(const person &other):name(other.name), age(other.age){
        std::cout<<"copy constructing person"<<std::endl;
    }

    ~person(){
        std::cout<<"destructing person"<<std::endl;
    }

};




int main()
{

    std::set<int>s={1,5,2,6,3,8,66,100};
     std::multiset<int,std::greater<>>s2={1,5,2,6,6,3,8,66,100};
     //multiset allow dublicate 
    for(int i : s2)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
 
    std::vector<person>people;
     people.push_back(person("mohamed",22));
     people.push_back(person("ahmed",23));


   std::vector<int >v5 ={5,6,7,8,9};
   for(int i=0;i<100;i++)
   {
    auto it = v5.cbegin().base();
    std::cout<<"pointer "<<it<<"  size = "<<v5.size()<<" capacity = "<<v5.capacity()<<std::endl;

   }
    std::array<int, 5> arr{1,22,3,4,15};
    std::vector<int> v = {1,23,13,4,5};
    std::cout<<v.size()<<std::endl;
    //std::cout<<v.empty()<<std::endl;
    std::sort(v.begin(),v.end());
    for(auto &i : v)
    {
        std::cout<<i<<" ";
    }
      std::cout<<std::endl;
    std::cout<<v.back()<<std::endl;
    std::cout<<v.front()<<std::endl;
    //std::cout<<arr.at(12)<<std::endl;
    //std::cout<<arr[12]<<std::endl; //error out of range
    std::vector<int>v2(v);
    std::vector<int>v3(std::move(v));
    v.push_back(100);
    v.insert(v.begin(),500);
    v.emplace_back(55); // like push-back but there is an optimization here
    v.emplace(v.begin()+2,1000);// like insert but there is an optimization here
    for(auto &i : v)
    {
        std::cout<<i<<" ";
    }
   std::cout<<std::endl;
   std::vector<int>v4 ={11,12,13,14,15};
   v.assign(v4.begin(),v4.end());
   for(auto &i : v)
   {
     std::cout<<i<<" ";
   }
   std::cout<<std::endl;
   v.resize(10);
     for(auto &i : v)
   {
     std::cout<<i<<" ";
   }
   std::cout<<std::endl;

  
    String s10("Mohamed khedr");
    s10.print();

   std::array<int, 5> arr2 = {1,2,3,4,5};
   std::cout<<arr2.size()<<std::endl;
   //std::cout<<arr.empty()<<std::endl;
   std::sort(arr2.begin(),arr2.end());
   for(auto &i : arr2)
   {
     std::cout<<i<<" "<<std::endl;
   }
   std::cout<<arr2.back()<<std::endl;
   std::cout<<arr2.front()<<std::endl;
  // std::cout<<arr.at(12)<<std::endl;
   //std::cout<<arr[12]<<std::endl; //error out of range
  std::cout<<*arr2.data()<<std::endl;






   std::string s11 = "Hello world";
   std::cout<<s11.substr(0,5)<<std::endl;
   std::cout<<s11.substr(6)<<std::endl;
   std::cout<<s11.substr(6,5)<<std::endl;
   std::cout<<s11.find("world")<<std::endl;
   std::cout<<s11.rfind("world")<<std::endl;
   std::cout<<s11.replace(6,5,"universe")<<std::endl;
   std::cout<<s11<<std::endl;
   std::cout<<s11.erase(6,5)<<std::endl;
   std::cout<<s11<<std::endl;
   std::cout<<s11.c_str()<<std::endl;
   



     auto raw_string=R"..(Hello world)..";
     std::cout<<raw_string<<std::endl;
   EnhanceString s12 = "mohamed khedr";
   std::string word;
   // stringstream one of the child from basic stream , stream for file ,stream for buffer, stream for string
   std::stringstream ss(s12);
   std::getline(ss,word,',');
   std::cout<<word<<std::endl;
   std::cout<<s12.starts_with("Hello")<<std::endl;
   s12.to_upper();
   std::cout<<s12<<std::endl;
   s12.to_lower();
   std::cout<<s12<<std::endl;
   s12.reverse();
   std::cout<<s12<<std::endl;
   return 0;

   
}