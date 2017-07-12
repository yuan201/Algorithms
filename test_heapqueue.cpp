#include <random>
#include <vector>
#include "gtest/gtest.h"
#include "heapqueue.h"
#include "utility.h"
using namespace std;

const int LENGTH = 10000;
const int MIN = -1000;
const int MAX = 1000;

TEST(HeapqueueTest, Heapify) {
    vector<int> array{};
    array.resize(LENGTH);
    for(int i=0; i<100; ++i){
	GenerateUnsortedArray(array);
	MaxHeapQueue mhq = MaxHeapQueue(array);
	mhq.BuildHeap();
	EXPECT_TRUE(IsMaxHeap(mhq.Queue()));
    }
}

TEST(HeapqueueTest, Heapsort) {
    vector<int> array{};
    array.resize(LENGTH);
    for(int i=0; i<100; ++i){
	GenerateUnsortedArray(array);
	MaxHeapQueue mhq = MaxHeapQueue(array);
	mhq.BuildHeap();
	vector<int> sorted = mhq.HeapSort();
	EXPECT_TRUE(IsOrdered(sorted));
    }
}
