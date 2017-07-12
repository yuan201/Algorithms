#include <iostream>
#include <vector>
using namespace std;

class MaxHeapQueue
{
public:
  MaxHeapQueue(const vector<int>& q);
  int Maximum();
  int ExtractMax();
  void Heapify(int i);
  vector<int> Queue();
  void BuildHeap();
  vector<int> HeapSort();
  
private:
  vector<int> queue;
  
};

int parent(int i);
int left(int i);
int right(int i);
void PrintHeap(const vector<int>& queue);

