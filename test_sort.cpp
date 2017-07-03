#include <random>
#include "gtest/gtest.h"
#include "sort.h"

const int LENGTH = 10000;
const int MIN = -1000;
const int MAX = 1000;

bool IsOrdered(int *array, int len)
{
  for(int i=0; i<len-1; ++i){
    if(array[i] > array[i+1])
      return false;
  }
  return true;
}

void GenerateUnsortedArray(int* array, int len)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(MIN, MAX);
    for(int i=0; i<len; ++i) {
      int number = distribution(generator);
      array[i] = number;
    }
}


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

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
