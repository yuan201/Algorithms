#include "sort.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  int array[10] = {4,5,1,-6,3,-5,2,-4,6,0};
  SelectionSort(array, 10);
  PrintArray(array, 10);
  return 0;
}
