import random
import nose
import sort

LENGTH = 1000

array = []

def setup():
    global array
    array = list(range(LENGTH))

    
@nose.with_setup(setup)    
def test_insertsort():
    for i in range(10):
        random.shuffle(array)
        sorted = sort.insertsort(array)
        assert sorted == range(LENGTH)


@nose.with_setup(setup)
def test_selectionsort():
    for i in range(10):
        random.shuffle(array)
        sorted = sort.selectionsort(array)
        assert sorted == range(LENGTH)

@nose.with_setup(setup)
def test_mergesort():
    random.shuffle(array)
    sorted = sort.mergesort(array)
    assert sorted == range(LENGTH)
