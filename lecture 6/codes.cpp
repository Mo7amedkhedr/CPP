#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
#include <algorithm>
class LCD{

    public:
    std::string msg;
    int cursor =0;
    void display (){
        std::cout << "Message: " << msg << std::endl;
    }

    // datatype operator op (argument-list ){body}
  LCD operator + (LCD& lcd2){
        LCD temp;
        temp.msg = this->msg + lcd2.msg;
        return temp;
    }
   LCD& operator += (std::string& str){
        this->msg += str;
        return *this;
    }
   bool operator <(LCD &lcd)
  {
     
  return this->msg <lcd.msg;
  }
 LCD& operator ++(){ //preincrement
    this->cursor++;
    return *this;
  }
  void operator --(){ //pre decrement
    this->cursor--;
  }
  int operator++(int) //post
  {
    int temp = this->cursor;
    this->cursor++;
    return temp;
  }
   
};



std::string operator + (const LCD &lcd, const std::string &Message)
   {
    return lcd.msg + Message;
   }


class Data
{
public:
std::string msg;
int cursor = 0;
Data()=default;
Data(std::string msg,int cursor) : msg(msg), cursor(cursor) {
    std::cout<<"constructor is callde"<<std::endl;
}
//friend std::ostream operator <<(std::ostream &os,const Data &dt);
bool operator <(const Data &temp){return this->cursor < temp.cursor;}
friend std::ostream &operator<<(std::ostream &os, const Data &dt)
{
    os << dt.msg << "  " << dt.cursor << std::endl;
    return os;
}
void operator()(std::string msg, int courser)
{
    std::cout <<"called functor"<<std::endl;
    std::cout<<"the old values were "<<*this<<std::endl;
    this->msg = msg;
    this->cursor = courser;
    std::cout<<"the new values are "<<*this<<std::endl;
}
~Data(){
    std::cout<<"destructor is called"<<std::endl;
}

//std::string to_string() { return msg;}
operator std::string (){return msg;}

explicit Data(std::string msg):msg(msg){}
};

int operator +(int c,Data &d)
{
    return c + d.cursor;
}

//custom user defined literal 
Data operator""_mt(unsigned long long int value)
{
    return Data("hello from _mt ",value);
}

int main()
{ 
   
     
   Data d1("hellollkkk",5);
   Data d2 = 100_mt;
   std::cout<<d2.msg<<" "<<std::endl;
  std::string message = d1.to_string();
   std::string message = d1;
   std::cout<<message<<std::endl;
  
   Data d2 = std::string ("welcommmmme");
  Data d2 = Data(std::string ("welcommmmme"));
   int x3 = 3 +d1;
   int x = std::string("mohamed") + d1;//operator+(std::string, d1)
   int x2 = d1+ std::string("khedr"); //d1.operator(std::string)
   LCD lcd1("hello world");
   LCD lcd2(" welcome");
   LCD lcd3("mohamed");

    Data data1{"hello world",0};
   data1("khedr",2);
   Data("hello",0)(); // temporary instance
     std::vector<Data >v{
        {"hello world",0},{"khedr",2},{"mohamed",1}
    };
  std::sort(v.begin(),v.end());
    std::cout<<v[0].cursor<<std::endl;
   std::cout<<v[1].cursor<<std::endl;
    std::cout<<v[2].cursor<<std::endl;
    std::copy(v.begin(),v.end(),std::ostream_iterator<Data>(std::cout,"\n"));

    
LCD lcd1{"hello world"};
LCD lcd2{" welcome"};
LCD lcd3{"mohamed"};
LCD lcd3 = lcd1 + lcd2;
lcd3.display();
std::string Message = " from egypt ";
lcd3.msg += Message;
lcd3.display();
std::string result = lcd1 + Message; // operator + (LCD,std::string)
std::cout<<"result: "<<result<<std::endl;
if (lcd1 < lcd2) // lcd1.operator < (lcd2)
{
 std::cout << "lcd1 is less than lcd2" << std::endl;
}
else
{
    std::cout << "lcd1 is not less than lcd2" << std::endl;
}
++lcd1;
 std::cout << lcd1.cursor << std::endl;
 lcd2++;
 std::cout << lcd2.cursor << std::endl;
}
