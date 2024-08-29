#include <iostream>
#include <cstring>
#include <utility>


class String
{
private:

char *str;
int size;

public:

friend String operator+(const String& lhs, const String& rhs);
friend std::ostream &operator<<(std::ostream &os, const String &obj);

String(){
    std::cout<<"constructor"<<std::endl;
}
String(const char *str){
    size = strlen(str);
    this->str = new char[size+1];
    strcpy(this->str, str);
}
void print_str(){
    std::cout<<str<<std::endl;
}
void print_length(){
    std::cout<<"Length: "<<size<<std::endl;
}

String(const String &obj)
{   
    std::cout<<"copy constructor"<<std::endl;
    size = obj.size;
    str = new char[size+1];
    strcpy(str, obj.str);
}


String (String &&obj) {

    std::cout <<"move constructor"<<std::endl;
   
    size = obj.size;
    obj.size= 0;
    //for old instance
    str = obj.str;
    obj.str = nullptr;

};



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



~String()
   {
    delete[] str;
    std::cout<<"destructor String called"<<std::endl;
}

};


// Overloading the plus operator
String operator+(const String& lhs, const String& rhs)
{
    int length = strlen(lhs.str) + strlen(rhs.str);
 
    char* buff = new char[length + 1];
 
    // Copy the strings to buff[]
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    buff[length] = '\0';
 
    // String temp
    String temp{ buff };
 
    // delete the buff[]
    delete[] buff;
 
    // Return the concatenated string
    return temp;
}

std::ostream &operator<<(std::ostream &os, const String &obj)
{
    os << obj.str;
    return os;
}


int main(){
  
   String s1("mohamed");
   s1.print_str();
   s1.print_length();
   String s2 = s1;
   String s3(std::move(s2));
   String s4(" khedr");
   String s5 = s1 + s4;
   std::cout<<s5<<std::endl;
   s5.print_str();
   s4.print_str();
   s4.print_length();
   s4 = s3;
   s4 = std::move(s1);
   s4.print_str();
   s1.print_str(); 
   s3.print_str(); 
   s2.print_str(); 


    return 0;
}


