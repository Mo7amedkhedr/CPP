#include <iostream>


class contain_evenNumber{

public:
   bool check_contain_Even(int arr[],int size);

};

bool contain_evenNumber::check_contain_Even(int arr[],int size)
{
 bool find_even = false;
 for(int i=0; i<size; i++)
 {
    if(arr[i]%2==0)
    {
        find_even = true;
        break;
    }
 }
  return find_even;
}



int main()
{
   int arr[]={1,3,5,7,9};
   int size = sizeof(arr)/sizeof(arr[0]);
   contain_evenNumber obj;
   if(obj.check_contain_Even(arr, size))
   {
     std::cout << "Array contains an even number." << std::endl;
   }
   else
   {
      std::cout << "NOT CONTAIN EVEN NUMBER"<<std::endl;
   }
  
}