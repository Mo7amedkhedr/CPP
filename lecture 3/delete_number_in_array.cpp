#include <iostream>


int delete_number_InArray(int arr[],int size,int goal)
{
  int i=0;
  int i_new=0;
  for( i = 0; i < size; i++ )
  {
    if(arr[i]!= goal)
    {
      arr[i_new++] = arr[i];
      
    }
  }
  return i_new;

}

int main()
{
  int arr[] ={1,2,3,4,5,6,7,8,9,10};
  int size = sizeof(arr)/sizeof(arr[0]);
  int goal;
  std::cout<<"enter the number you want to delete :  ";
  std::cin>>goal;
  int newLength = delete_number_InArray(arr,  size,  goal);
   std::cout<<"the new array after deletion : ";
  for(int i = 0;i<newLength;i++)
  {
   
    std::cout<<arr[i]<<" ";
  }
   std::cout << std::endl;
   return 0;
}