#include <random>
#include <vector>
#include "utility.h"
#include "heapqueue.h"
using namespace std;

const int MIN = -1000;
const int MAX = 1000;

void GenerateUnsortedArray(int* array, int len)
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(MIN, MAX);
    for(int i=0; i<len; ++i) {
      int number = distribution(generator);
      array[i] = number;
    }
}

void GenerateUnsortedArray(vector<int>& array)
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(MIN, MAX);
    for(int i=0; i<array.size(); ++i) {
	int number = distribution(generator);
	array[i] = number;
    }
}

bool IsMaxHeap(const vector<int>& heap)
{
  for(int i=heap.size()-1; i>0; --i){
    if(heap[i] > heap[parent(i)]){
      cout << i << endl;
      cout << heap[i] << ", " << heap[parent(i)] << endl;
      return false;
    }
  }
  return true;
}

bool IsOrdered(int *array, int len)
{
  for(int i=0; i<len-1; ++i){
    if(array[i] > array[i+1])
      return false;
  }
  return true;
}

bool IsOrdered(const vector<int>& array)
{
    for(int i=0; i<array.size()-1; ++i)
	if(array[i] > array[i+1])
	    return false;
    return true;
}
