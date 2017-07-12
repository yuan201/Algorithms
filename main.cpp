#include <iostream>
using namespace std;

#include "sort.h"
#include "dnc.h"
#include "heapqueue.h"

int main(int argc, char **argv)
{
  /*
  int array[5] = {4,-3,8,-6,5};

  MaxSubarray maxsb = FindMaxCrossingSubarray(array, 0, 2, 5);
  cout << "find crossing" << endl;
  cout << maxsb.left << ", "
       << maxsb.right << ", "
       << maxsb.sum
       << endl;


  maxsb = FindMaxSubarray(array, 0, 5);
  cout << "find max" << endl;
  cout << maxsb.left << ", "
       << maxsb.right << ", "
       << maxsb.sum
       << endl;
  */

  MaxHeapQueue mhq({4,1,3,2,16,9,10,14,8,7});
  PrintHeap(mhq.Queue());
  mhq.BuildHeap();
  vector<int> sorted = mhq.HeapSort();
  PrintHeap(sorted);

  return 0;
}
