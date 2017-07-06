#include "gtest/gtest.h"
#include "dnc.h"
#include "utility.h"

const int LENGTH = 100;

TEST(DivideConquerTest, FindMaxSubarray) {
  for(int i=0; i<10; ++i) {
    int array[LENGTH] = {};
    GenerateUnsortedArray(array, LENGTH);
    MaxSubarray maxsb1 = FindMaxSubarray(array, 0, LENGTH);
    MaxSubarray maxsb2 = FindMaxSubarrayBrute(array, 0, LENGTH);
    EXPECT_EQ(maxsb1.sum, maxsb2.sum);
  }
}
    
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

