#include <iostream>
using namespace std;

#include "sort.h"
#include "dnc.h"
#include "heapqueue.h"

int main(int argc, char **argv)
{
  int array[] = {2,8,7,1,3,5,6,4};
  QuickSort(array, 0, 7);
  PrintArray(array, 8);
  return 0;
}
