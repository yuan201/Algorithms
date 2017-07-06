import random
import nose
import heapsort

LENGTH = 1000

array = []

def setup():
    global array
    array = list(range(LENGTH))
    random.shuffle(array)
    
def test_heapsort():
    copy = list(array)
    heapsort.heapsort(array)
    copy.sort()
    assert copy == array
