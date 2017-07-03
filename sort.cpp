#include <iostream>
#include "sort.h"

void PrintArray(int* array, int len)
{
  for(int i=0; i<len; ++i)
    std::cout << array[i] << ", ";
  std::cout << std::endl;
}

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
    }
    //std::cout << min << ", " << pos << std::endl;
    std::swap(array[i], array[pos]);
    //PrintArray(array, len);
  }
}
