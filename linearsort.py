import numpy as np
from sort import insertsort

#assume array is a one dimension array that
#need to be sorted
def countingsort(array, k):
    c = np.zeros(k+1, dtype=np.int32)
    b = np.empty_like(array)
    for key in array:
        c[key] += 1
    for i in range(k):
        c[i+1] = c[i+1] + c[i]
    for key in array[::-1]:
        b[c[key]-1] = key
        c[key] -= 1
    return b

def radixsort(array):
    d = array.shape[1]
    for i in reversed(range(d)):
        array = countingsortd(array, i, 9)
    return array

#assume array is a 2 dimension array that
#need to be sorted on d column
def countingsortd(array, d, k):
    c = np.zeros(k+1, dtype=np.int32)
    b = np.empty_like(array)
    for key in array[:, d]:
        c[key] += 1
    for i in range(k):
        c[i+1] = c[i+1] + c[i]
    for key in reversed(array):
        #print(key)
        b[c[key[d]]-1] = key
        c[key[d]] -= 1
    return b


def bucketsort(array):
    b = [[] for i in array]
    for key in array:
        b[int(key)].append(key)
    result = []
    for l in b:
        result.extend(insertsort(l))
    return result
