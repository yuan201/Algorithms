#include <iostream>
using namespace std;

#include "sort.h"
#include "dnc.h"

int main(int argc, char **argv)
{
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
  return 0;
}
