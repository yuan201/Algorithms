import nose
import linearsort as ls
import numpy as np
from test_sort import is_sorted

LENGTH = 10
K = 200

def test_countingsort():
    for i in range(10):
        a = np.random.randint(0, K, LENGTH)
        b = ls.countingsort(a, K)
        #print(b)
        assert is_sorted(b)

def test_radixsort():
    for i in range(10):
        a = np.random.randint(0, 9, LENGTH*3)
        a.resize(LENGTH,3)
        b = ls.radixsort(a)
        assert is_sorted(b[:,0]*100+b[:,1]*10+b[:,2])

def test_bucketsort():
    for i in range(10):
        a = np.random.random(LENGTH)
        assert is_sorted(ls.bucketsort(a))
