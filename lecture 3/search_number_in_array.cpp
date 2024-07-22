
#include <iostream>

void search_num_InArray(int arr[], int size,int goal)
{

    for(int i=0;i<size;i++)
    {
        if(arr[i] == goal)
        {
           
            std::cout<< "the number you entered is : "<<goal << " found in index : " <<i<<std::endl;
            break;
        }
        else if ((i==size-1)&&(arr[i]!=goal))
        {
            std:: cout<<"not found " <<std::endl;
            break;             
        }
    }
    
}

int main()
{
  int arr[]={1,2,3,4,5,8,9,10,22,66,84,100};

  int size = sizeof(arr)/sizeof(arr[0]);
  int  goal;
  int pointer_value;
  std::cout << "Enter the number you want to search: ";
  std::cin >> goal;
  search_num_InArray(arr, size, goal);
  
}




