import sys

def max_heapify(heap, i):
    l=left(i)
    r=right(i)
    heapsize = len(heap)
    if l < heapsize and heap[l] > heap[i]:
        largest = l
    else:
        largest = i
    if r < heapsize and heap[r] > heap[largest]:
        largest = r
    if largest != i:
        heap[i], heap[largest] = heap[largest], heap[i]
        max_heapify(heap, largest)

def max_heapify_loop(heap, i):
    while(i<len(heap)):
        l=left(i)
        r=right(i)
        heapsize = len(heap)
        if l < heapsize and heap[l] > heap[i]:
            largest = l
        else:
            largest = i
        if r < heapsize and heap[r] > heap[largest]:
            largest = r
        if largest != i:
            heap[i], heap[largest] = heap[largest], heap[i]
            i = largest
        else:
            break;

def min_heapify(heap, i):
    l=left(i)
    r=right(i)
    heapsize=len(heap)
    if l < heapsize and heap[l] < heap[i]:
        smallest = l
    else:
        smallest = i
    if r < heapsize and heap[r] < heap[smallest]:
        smallest = r
    if smallest != i:
        heap[i], heap[smallest] = heap[smallest], heap[i]
        min_heapify(heap, smallest)
        
def left(i):
    return ((i+1)<<1)-1;

def right(i):
    return (i+1)<<1;

def parent(i):
    return ((i+1)>>1)-1;

def build_max_heap(heap):
    for i in range(int(len(heap)/2)-1,-1,-1):
        max_heapify(heap,i)

def build_min_heap(heap):
    for i in range(int(len(heap)/2)-1,-1,-1):
        min_heapify(heap, i)

def heap_sort(array):
    result = []
    build_max_heap(array)
    for i in range(len(array)):
        result.insert(0, array[0])
        array[0] = -sys.maxsize
        max_heapify(array, 0)
    return result

