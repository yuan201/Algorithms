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
        sort.insertsort(array)
        assert array == range(LENGTH)


@nose.with_setup(setup)
def test_selectionsort():
    for i in range(10):
        random.shuffle(array)
        sort.selectionsort(array)
        assert array == range(LENGTH)
