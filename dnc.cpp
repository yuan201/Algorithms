#include <climits>
#include <iostream>
using namespace std;

#include "dnc.h"

MaxSubarray FindMaxCrossingSubarray(int* array, int low, int mid, int high)
{
  int leftsum = INT_MIN;
  int sum = 0;
  int maxleft, maxright;
  for(int i=mid-1; i>=low; --i){
    sum += array[i];
    if(sum > leftsum){
      leftsum = sum;
      maxleft = i;
    }
  }
  sum = 0;
  int rightsum = INT_MIN;
  for(int i=mid; i<high; ++i){
    sum += array[i];
    if(sum > rightsum){
      rightsum = sum;
      maxright = i;
    }
  }
  return MaxSubarray({maxleft, maxright, leftsum+rightsum});
}

MaxSubarray FindMaxSubarray(int* array, int low, int high)
{
  //cout << low << ", " << high << endl;
  if(low==high)
    return MaxSubarray({0,0,array[low]});
  int mid = int((low+high)/2);
  //cout << mid << endl;
  MaxSubarray left = FindMaxSubarray(array, low, mid);
  MaxSubarray right = FindMaxSubarray(array, mid+1, high);
  MaxSubarray cross = FindMaxCrossingSubarray(array, low, mid, high);
  //cout << left.sum << ", " << right.sum << ", " << cross.sum << endl;
  if(left.sum >= right.sum && left.sum >= cross.sum)
    return left;
  else if(right.sum >= left.sum && right.sum >= cross.sum)
    return right;
  else
    return cross;
}

MaxSubarray FindMaxSubarrayBrute(int* array, int low, int high)
{
  MaxSubarray maxsb = {0,0,INT_MIN};
  int sum;
  for(int i=low; i<high; ++i){
    sum = 0;
    for(int j=i; j<high; ++j){
      sum += array[j];
      if(sum > maxsb.sum){
	maxsb.sum = sum;
	maxsb.left = i;
	maxsb.right = j;
      }
    }
  }
  return maxsb;
}

