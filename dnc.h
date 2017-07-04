struct MaxSubarray
{
  int left,right,sum;
};
  
MaxSubarray FindMaxCrossingSubarray(int* array, int low, int mid, int high);
MaxSubarray FindMaxSubarray(int* array, int low, int high);
MaxSubarray FindMaxSubarrayBrute(int* array, int low, int high);
  
