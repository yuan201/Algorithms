#include <iostream>
#include <cmath>
#include <climits>
#include "heapqueue.h"

int parent(int i)
{
    return int((i+1)/2-1);
}

int left(int i){
    return (i+1)*2-1;
}

int right(int i){
    return (i+1)*2;
}


void PrintHeap(const vector<int>& queue){
    int i;
    for(i=0; i<queue.size()-1; ++i)
	cout << queue[i] << ",";
    cout << queue[i] << endl;
}

MaxHeapQueue::MaxHeapQueue(const vector<int>& q)
{
    queue = q;
}

int MaxHeapQueue::Maximum(){
    if(queue.size() == 0)
	throw UnderflowError();
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

vector<int> MaxHeapQueue::HeapSort(){
    vector<int> sorted;
    int size = queue.size();
    sorted.resize(size);
    for(int i=0; i<size; ++i){
	sorted[size-i-1] = queue[0];
	queue[0] = queue[queue.size()-1];
	queue.pop_back();
	Heapify(0);
    }
    return sorted;
}

int MaxHeapQueue::ExtractMax(){
    if(queue.size()==0)
	throw UnderflowError();
    int max = queue[0];
    queue[0] = queue.back();
    queue.pop_back();
    Heapify(0);
    return max;
}

void MaxHeapQueue::IncreaseKey(int i, int key){
    if(key<queue[i])
	throw KeyvalueError();
    queue[i] = key;
    while(i>0 and queue[parent(i)] < queue[i]){
	swap(queue[parent(i)], queue[i]);
	i = parent(i);
    }
}

void MaxHeapQueue::Insert(int key){
    queue.push_back(INT_MIN);
    IncreaseKey(queue.size()-1, key);
}

