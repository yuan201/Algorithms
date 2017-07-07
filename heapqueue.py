import copy
import sys
from heapsort import *


class HeapUnderflow(Exception):
    pass


class HeapNewkeyError(Exception):
    pass


class MaxHeapQueue():
    def __init__(self, queue=None):
        if queue is None:
            self.queue = []
        else:
            self.queue = copy.deepcopy(queue)

    def maximum(self):
        return self.queue[0]

    def extract_max(self):
        if len(self.queue) == 0:
            raise HeapUnderflow()
        max = self.queue[0]
        if len(self.queue) > 1:
            self.queue[0] = self.queue.pop()
            max_heapify(self.queue, 0)
        else:
            self.queue.clear()
        return max

    def increase_key(self, i, key):
        if key < self.queue[i]:
            raise HeapNewkeyError()
        self.queue[i] = key
        while(i != 0 and self.queue[parent(i)] < self.queue[i]):
            pi = parent(i)
            self.queue[i], self.queue[pi] = self.queue[pi], self.queue[i]
            i = pi

    def insert(self, key):
        self.queue.append(-sys.maxsize)
        self.increase_key(len(self.queue)-1, key)

    def delete(self, i):
        if len(self.queue) > 1:
            self.queue[i] = self.queue.pop()
            max_heapify(self.queue, i)
        else:
            self.queue.clear()
            

class MinHeapQueue():
    def __init__(self, queue=None):
        if queue is None:
            self.queue = []
        else:
            self.queue = copy.deepcopy(queue)

    def minimum(self):
        return self.queue[0]

    def extract_min(self):
        if len(self.queue) == 0:
            raise HeapUnderflow()
        min = self.queue[0]
        if len(self.queue) > 1:
            self.queue[0] = self.queue.pop()
            min_heapify(self.queue, 0)
        else:
            self.queue.clear()
        return min

    def decrease_key(self, i, key):
        if key > self.queue[i]:
            raise HeapNewkeyError()
        self.queue[i] = key
        while(i != 0 and self.queue[parent(i)] > self.queue[i]):
            pi = parent(i)
            self.queue[i], self.queue[pi] = self.queue[pi], self.queue[i]
            i = pi

    def insert(self, key):
        self.queue.append(sys.maxsize)
        self.decrease_key(len(self.queue)-1, key)

class Item():
    def __init__(self, index, item):
        self.index = index
        self.item = item

    def __int__(self):
        return self.index
        
    def __lt__(self, other):
        return int(self) < int(other)

    def __gt__(self, other):
        return int(self) > int(other)

    def __repr__(self):
        return "{}:{}".format(self.index, self.item)
    
        
class Fifo():
    def __init__(self):
        self.queue = MaxHeapQueue()
        self.index = 0
        
    def size(self):
        return len(self.queue)
        
    def put(self, item):
        self.queue.insert(Item(self.index, item))
        self.index -= 1

    def get(self):
        return self.queue.extract_max().item


def build_max_heap_insert(array):
    heap = MaxHeapQueue()
    for item in array:
        heap.insert(item)
    return heap
