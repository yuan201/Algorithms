import random
import nose
import heapsort

LENGTH = 1000

array = []

def setup():
    global array
    array = list(range(LENGTH))
    random.shuffle(array)

@nose.with_setup(setup)
def test_heapsort():
    copy = list(array)
    sorted = heapsort.heap_sort(array)
    copy.sort()
    #print(copy)
    #print(array)
    assert copy == sorted
