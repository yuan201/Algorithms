#include <iostream>
#include <cmath>
#include "heapqueue.h"

int parent(int i)
{
  return int((i+1)/2);
}

int left(int i){
  return (i+1)*2-1;
}

int right(int i){
  return (i+1)*2;
}

void PrintHeap(MaxHeapQueue mhq){
  return;
}

MaxHeapQueue::MaxHeapQueue(const vector<int>& q)
{
  queue = q;
}

int MaxHeapQueue::Maximum(){
  if(queue.size() > 0)
    return queue[0];
}
 
void MaxHeapQueue::Heapify(int i){
  int l = left(i);
  int r = right(i);
  int largest;
  if(l < queue.size() and queue[l] > queue[i]){
    largest = l;
  } else {
    largest = i;
  }
  if(r < queue.size() and queue[r] > queue[largest]){
    largest = r;
  }
  if(largest != i){
    swap(queue[i], queue[largest]);
    Heapify(largest);
  }
}

vector<int> MaxHeapQueue::Queue(){
  return queue;
}

void MaxHeapQueue::BuildHeap(){
  for(int i=int(queue.size()/2)-1; i>=0; --i)
    Heapify(i);
}
