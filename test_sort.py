import random
import nose
import sort
import quicksort as qs

LENGTH = 10

array = []

def setup():
    global array
    array = list(range(LENGTH))

def is_sorted(a):
    for i in range(len(a)-1):
        if a[i] > a[i+1]:
            return False
    return True
    
@nose.with_setup(setup)    
def test_insertsort():
    for i in range(10):
        random.shuffle(array)
        sorted = sort.insertsort(array)
        #print(sorted)
        assert is_sorted(sorted)


@nose.with_setup(setup)
def test_selectionsort():
    for i in range(10):
        random.shuffle(array)
        sorted = sort.selectionsort(array)
        assert is_sorted(sorted)

@nose.with_setup(setup)
def test_mergesort():
    random.shuffle(array)
    sorted = sort.mergesort(array)
    assert is_sorted(sorted)

@nose.with_setup(setup)
def test_quicksort():
    random.shuffle(array)
    sorted = qs.quicksort(array)
    assert is_sorted(sorted)
