#include <cstring>
#include <iostream>


class string{

private:
    char *str;
    int length;
public:
    
    string(const char *s) {
        std::cout<<"string is created"<<std::endl;
        length = std::strlen(s);
        str = new char[length + 1]; // 1  -> for null terminator
        std::strcpy(str, s);
    }
    
    ~string() {
        delete[] str;
        std::cout<<"string is deleted"<<std::endl;
    }
    int get_length(){
        return length;
    }
     const  char *get_str(){
        return str;
    }

};

int main()
{
   string s1("mohamed khedr");
   std::cout<<s1.get_length()<<std::endl;
   std::cout<<s1.get_str()<<std::endl;



   return 0;

}
