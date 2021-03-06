#include <random>
#include "gtest/gtest.h"
#include "sort.h"
#include "utility.h"

const int LENGTH = 10000;
const int MIN = -1000;
const int MAX = 1000;

TEST(SortTest, InsertSort) {
    for(int i=0; i<10; ++i){
	int array[LENGTH] = {};
	GenerateUnsortedArray(array, LENGTH);
	InsertSort(array, LENGTH);
	EXPECT_TRUE(IsOrdered(array, LENGTH));
    }
}

TEST(SortTest, SelectionSort) {
    for(int i=0; i<10; ++i){
	int array[LENGTH] = {};
	GenerateUnsortedArray(array, LENGTH);
	SelectionSort(array, LENGTH);
	EXPECT_TRUE(IsOrdered(array, LENGTH));
    }
} 

TEST(SortTest, MergeSort) {
    for(int i=0; i<10; ++i){
	int array[LENGTH] = {};
	GenerateUnsortedArray(array, LENGTH);
	MergeSort(array, LENGTH);
	EXPECT_TRUE(IsOrdered(array, LENGTH));
    }
}

TEST(SortTest, RecursiveInsertSort) {
    for(int i=0; i<10; ++i){
	int array[LENGTH] = {};
	GenerateUnsortedArray(array, LENGTH);
	RecursiveInsertSort(array, LENGTH);
	EXPECT_TRUE(IsOrdered(array, LENGTH));
    }
}

TEST(SortTest, QuickSort) {
    for(int i=0; i<10; ++i){
	int array[LENGTH] = {};
	GenerateUnsortedArray(array, LENGTH);
	QuickSort(array, 0, LENGTH-1);
	EXPECT_TRUE(IsOrdered(array, LENGTH));
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
