##########################################
# implement a few permutation algorithms
# and graph the result
##########################################

import sys
import numpy as np
import matplotlib.pyplot as plt
import random
from collections import defaultdict

LENGTH = 10000

def count_permute(permute):
    hit = defaultdict(int)
    array = list(range(4))
    for i in range(LENGTH):
        array = permute(array)
        hit[tuple(array)] += 1
    return hit

def system_permute(array):
    random.shuffle(array)
    return array

def showhitbar(hit):
    plt.figure(1)
    plt.subplot(111)
    x = np.arange(len(hit))
    plt.bar(x, hit.values())
    plt.show()

def sort_permute(array):
    rndmax = len(array)**3
    p = [(array[i],random.randint(1, rndmax))
         for i in range(len(array))]
    p.sort(key=lambda u:u[1])
    return [u[0] for u in p]

def swap_permute(array):
    for i in range(len(array)):
        j = random.randint(i, len(array)-1)
        array[i], array[j] = array[j], array[i]
    return array

def swapn_permute(array):
    for i in range(len(array)):
        j = random.randint(0, len(array)-1)
        array[i], array[j] = array[j], array[i]
    return array

def cyclic_permute(array):
    b = list(array)
    offset = random.randint(0,len(array)-1)
    for i in range(len(array)):
        dest = i + offset
        if dest > len(array)-1:
            dest -= len(array)
        b[dest] = array[i]
    return b

if __name__ == "__main__":
    if sys.argv[1] == 'sys':
        hit = count_permute(system_permute)
    elif sys.argv[1] == 'sort':
        hit = count_permute(sort_permute)
    elif sys.argv[1] == 'swap':
        hit = count_permute(swap_permute)
    elif sys.argv[1] == 'swapn':
        hit = count_permute(swapn_permute)
    elif sys.argv[1] == 'cyc':
        hit = count_permute(cyclic_permute)
    else:
        exit()

    showhitbar(hit)
