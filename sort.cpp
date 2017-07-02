#include <iostream>

void InsertSort(int* array, int len)
{
  for(int j=1; j<len; ++j){
    int key = array[j];
    int i = j-1;
    while((i>=0)&&(array[i]>key)){
      array[i+1] = array[i];
      --i;
    }
    array[i+1] = key;
  }
}

void SelectionSort(int* array, int len)
{
  for(int i=0; i<len-1; ++i){
    int pos = i;
    int min = array[i];
    for(int j=i+1; j<len; ++j){
      if(array[j] < min){
	min = array[j];
	pos = j;
      }
      std::swap(array[i], array[pos]);
    }
  }
}

int main()
{
  int array[10] = {1,5,2,4,3,6,7,0,9,8};
  //InsertSort(array, 10);
  SelectionSort(array, 10);
  for(int i=0; i<10; ++i)
    std::cout << array[i] << std::endl;
  return 0;
}
