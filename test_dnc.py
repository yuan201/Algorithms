import random
import nose
import dnc

LENGTH = 1000

def test_find_max_subarray():
    for i in range(10):
        array = [random.randint(-100,100) for i in range(LENGTH)]
        assert (dnc.find_max_subarray(array)[2] ==
                dnc.find_max_subarray_brute(array)[2])
        assert (dnc.find_max_subarray(array)[2] ==
                dnc.find_max_subarray_linear(array)[2])
