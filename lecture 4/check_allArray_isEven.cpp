#include <iostream>


class check_evenArray{

public:

    bool check(int arr[], int size);


};

bool check_evenArray::check(int arr[],int size)
{
  bool alleven = true; 
  for(int i=0;i<size;i++)
  {
    if(arr[i]%2!=0) 
    {
        alleven = false;
        break;  
    }
  }
return alleven;
}



int main() {
    
    int arr[]={2,4,8,6,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    check_evenArray obj;
    if(obj.check(arr, size))
    {
        std::cout<<"All elements in the array are even."<<std::endl;
    }
    else
    {
        std::cout<<"NOT EVEN ARRAY"<<std::endl;
    }

}

