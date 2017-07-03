import random
import math, sys

def insertsort(array):
    for i, key in enumerate(array[1:]):
        while (i>=0) and array[i]>key:
            array[i+1] = array[i]
            i -= 1
        array[i+1] = key
    return array


def selectionsort(array):
    for i, key in enumerate(array[:-1]):
        pos, min_ = findmin(array[i:])
        array[i], array[i+pos] = array[i+pos], array[i]
    return array


def findmin(array):
    pos = 0
    min_ = array[0]
    for i,key in enumerate(array):
        if key < min_:
            min_ = key
            pos = i
    return pos, min_


def merge(left, right):
    result = list()
    left.append(sys.maxint)
    right.append(sys.maxint)
    i=0
    j=0
    for k in range(len(left)+len(right)-2):
        if left[i] < right[j]:
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+=1
    return result


def mergesort(array):
    if len(array) == 1:
        return array
    else:
        mid = int(len(array)/2)
        left = mergesort(array[:mid])
        right = mergesort(array[mid:])
        return merge(left, right)

    
