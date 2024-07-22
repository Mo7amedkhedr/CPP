#include <iostream>

void merge_array(int arr1[],int size1, int arr2[],int size2, int merge_array[])
{
  int i;
  int j;
  for(i=0;i<size1;i++)
  {
    merge_array[i]=arr1[i];
  }
  for(j =0; j < size2; j++)
  {
    merge_array[i+j]=arr2[j];
  }
}



int main()
{

 int arr1[]={1,2,3,4,5,6,7,8,9,10};
 int arr2[]={11,12,13,14,15,16,17,18,19,20};
  
 int size1= sizeof(arr1)/sizeof(arr1[0]) ;
 int size2= sizeof(arr2)/sizeof(arr2[0]);
 
 int merged_arr[size1+size2];

merge_array(arr1,size1,arr2,size2,merged_arr);

 std::cout << " array after merged : ";
    for (int i = 0; i < (size1+size2); ++i) {
        std::cout << merged_arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;




}