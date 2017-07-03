import random
#import unittest

def insertsort(array):
    for i, key in enumerate(array[1:]):
        while (i>=0) and array[i]>key:
            array[i+1] = array[i]
            i -= 1
        array[i+1] = key

def selectionsort(array):
    for i, key in enumerate(array[:-1]):
        pos, min_ = findmin(array[i:])
        array[i], array[i+pos] = array[i+pos], array[i]

def findmin(array):
    pos = 0
    min_ = array[0]
    for i,key in enumerate(array):
        if key < min_:
            min_ = key
            pos = i
    return pos, min_

def merge(array, p, q, r):
    result = list()
    left = array[p:q]
    right = array[q:r]
    left.append(1000000)
    right.append(1000000)
    i=0
    j=0
    for k in range(r-p):
        if left[i] < right[j]:
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+=1
    return result

