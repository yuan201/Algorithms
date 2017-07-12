#include <iostream>
#include <cstring>
#include "sort.h"
using namespace std;

void PrintArray(int* array, int len)
{
    for(int i=0; i<len; ++i)
	cout << array[i] << ", ";
    cout << endl;
}

void InsertSort(int* array, int len)
{
    for(int j=1; j<len; ++j){
	int key = array[j];
	int i = j-1;
	while((i>=0)&&(array[i]>key)){
	    array[i+1] = array[i];
	    --i;
	}
	array[i+1] = key;
    }
}

void RecursiveInsertSort(int* array, int len)
{
    if(len==1) {
	return;
    } else {
	RecursiveInsertSort(array, len-1);
	//PrintArray(array, len);
	for(int i=0; i<len-1; ++i){
	    int key = array[len-1];
	    if(key < array[i]) {
		memmove(array+i+1, array+i, (len-i-1)*sizeof(int));
		array[i] = key;
	    }
	}
	//PrintArray(array, len);
    }
}

void SelectionSort(int* array, int len)
{
    for(int i=0; i<len-1; ++i){
	int pos = i;
	int min = array[i];
	for(int j=i+1; j<len; ++j){
	    if(array[j] < min){
		min = array[j];
		pos = j;
	    }
	}
	//std::cout << min << ", " << pos << std::endl;
	swap(array[i], array[pos]);
	//PrintArray(array, len);
    }
}

void Merge(int* array, int start, int mid, int end)
{
    int nl = mid-start;
    int nr = end-mid+1;
    int* left = new int[nl];
    int* right = new int[nr];
    memcpy(left, array, nl*sizeof(int));
    memcpy(right, array+mid, nr*sizeof(int));
    int i,j,cur;
    i=j=cur=0;
    while(i<nl && j<nr){
	if(left[i] < right[j]) {
	    array[cur++] = left[i++];
	} else {
	    array[cur++] = right[j++];
	}
    }
    if(i<nl)
	memcpy(array+cur, left+i, (nl-i)*sizeof(int));
    if(j<nr)
	memcpy(array+cur, right+j, (nr-j)*sizeof(int));
    delete left;
    delete right;
}

void MergeSort(int* array, int len)
{
    if(len==1) {
	return;
    } else {
	int mid = int(len/2);
	MergeSort(array, mid);
	MergeSort(array+mid, len-mid);
	Merge(array, 0, mid, len-1);
    }
}

int CountInversion(int* array, int len)
{
    if(len==1) {
	return 0;
    } else {
	int mid = int(len/2);
	int inversions;
	inversions = CountInversion(array, mid);
	inversions += CountInversion(array+mid, len-mid);
	inversions += MergeInversion(array, 0, mid, len-1);
	return inversions;
    } 
}

int MergeInversion(int* array, int start, int mid, int end)
{
    int inversions = 0;
    int nl = mid-start;
    int nr = end-mid+1;
    int* left = new int[nl];
    int* right = new int[nr];
    memcpy(left, array, nl*sizeof(int));
    memcpy(right, array+mid, nr*sizeof(int));
    int i,j,cur;
    i=j=cur=0;
    while(i<nl && j<nr){
	if(left[i] < right[j]) {
	    array[cur++] = left[i++];
	} else {
	    array[cur++] = right[j++];
	    inversions += nl-i;
	}
    }
    if(i<nl)
	memcpy(array+cur, left+i, (nl-i)*sizeof(int));
    if(j<nr)
	memcpy(array+cur, right+j, (nr-j)*sizeof(int));
    delete left;
    delete right;
    return inversions;
}

int Partition(int* array, int p, int r)
{
    int x = array[r];
    int i = p-1;
    for(int j=p; j<=r-1; ++j){
	if(array[j] <= x)
	    swap(array[++i], array[j]);
    }
    swap(array[i+1], array[r]);
    return i+1;
}

void QuickSort(int* array, int p, int r)
{
    if(p<r){
	int q = Partition(array, p, r);
	QuickSort(array, p, q-1);
	QuickSort(array, q+1, r);
    }
}
