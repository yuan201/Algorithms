#include "sort.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
  int array[5] = {2,3,8,6,5};
  int inversions = CountInversion(array, 5);
  cout << inversions << endl;
  return 0;
}
