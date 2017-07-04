#include <random>
#include "utility.h"

const int MIN = -100;
const int MAX = 100;

void GenerateUnsortedArray(int* array, int len)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(MIN, MAX);
    for(int i=0; i<len; ++i) {
      int number = distribution(generator);
      array[i] = number;
    }
}
