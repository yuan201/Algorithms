#chapter divide and conquer

import sys

def find_max_crossing_subarray(array, mid):
    leftsum = -sys.maxsize
    sum = 0
    for i in range(mid-1, -1, -1):
        sum += array[i]
        if sum > leftsum:
            leftsum = sum
            maxleft = i

    rightsum = -sys.maxsize
    sum = 0
    for i in range(mid, len(array)):
        sum += array[i]
        if sum > rightsum:
            rightsum = sum
            maxright = i
    return maxleft, maxright, leftsum+rightsum

def find_max_subarray(array):
    if len(array)==1:
        return 0,0,array[0]
    else:
        mid = int(len(array)/2)
        leftlow, lefthigh, leftsum = find_max_subarray(array[:mid])
        rightlow, righthigh, rightsum = find_max_subarray(array[mid:])
        crosslow, crosshigh, crosssum = find_max_crossing_subarray(array, mid)
        if leftsum >= rightsum and leftsum >= crosssum:
            return leftlow, lefthigh, leftsum
        elif crosssum >= leftsum and crosssum >= rightsum:
            return crosslow, crosshigh, crosssum
        else:
            return rightlow+mid, righthigh+mid, rightsum
            

def find_max_subarray_brute(array):
    max = -sys.maxsize
    for i in range(len(array)):
        sum = 0
        for j,key in enumerate(array[i:]):
            sum += key
            if sum>max:
                max = sum
                left = i
                right = j
    return left, right, max


def find_max_subarray_linear(array):
    max_sum = 0 # sum of max subarray in array[0:i]
    max_lead = 0 # sum of max subarray in array[0:i] that end in i
    left = 0
    scan_left = 0
    for i, key in enumerate(array):
        if key+max_lead < 0:
            max_lead = 0
            scan_left = i+1
        else:
            max_lead += key
        if max_lead > max_sum:
            max_sum = max_lead;
            left = scan_left
            right = i

    return left, right, max_sum
