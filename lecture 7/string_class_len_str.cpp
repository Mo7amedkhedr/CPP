
#include <cstring>
#include <iostream>



class string{
    private:
        char* data;
        int length;
    public:
        string() : data(nullptr),length(0)
        {
            std::cout<<"constructor"<<std::endl;
        }
        string(const char* str) : data(nullptr),length(0){
            if(str){
                length=std::strlen(str);
                data=new char[length+1];
                std::strcpy(data,str);
            }
        }

        ~string(){
            std::cout<<"destructor"<<std::endl;
            delete [] data;
        }        
        int getlength() const{
            return length;
        }
        const char* getstring() const {
            return data;
        }

    
};

int main()
{
    string s("mohamed khedr ");

   
    std::cout << "the String is " << s.getstring()<< "and it's length is "<< s.getlength()<< std::endl;


    return 0;
}