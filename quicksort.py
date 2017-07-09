import random

def partition(array):
    if len(array) == 0:
        return
    a = array
    x = a[-1]
    i = -1
    for j in range(len(array)-1):
        if array[j] < x:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i+1], a[-1] = a[-1], a[i+1]
    return i+1

def quicksort(array):
    print(array)
    if len(array) <= 1:
        return array
    p = partition(array)
    array[:p] = quicksort(array[:p])
    array[p:] = quicksort(array[p:])
    return array
