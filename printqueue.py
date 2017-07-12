import sys
import math

def print_heap(heap):
    depth = math.ceil(math.log2(len(heap)))
    maxwidth = len(str(max(heap)))
    # make maxwidth an even number
    if maxwidth % 2:
        maxwidth += 1
    space = maxwidth + 2
    arrows = [' /', '\\  ']
    for i in range(depth):
        l = 2**i-1
        r = 2**(i+1)-1
        line = ""
        arrow = ""
        pos = 0
        for j in range(l, min(r,len(heap))):
            fill=space*(2**(depth-i-1))
            line += "{:^{f}}".format(
                heap[j], f=fill, end='')
            arrow += "{:^{f}}".format(
                arrows[pos], f=fill, end='')
            pos = (pos+1)%2
        if(i != 0):
            print(arrow)
        print(line)

def usage():
    print("Usage:\n  {} type file".format(sys.argv[0]))

def load_heap(file):
    with open(file) as hfile:
        l = hfile.read().strip().split(',')
        return [int(i) for i in l]
    
if __name__ == "__main__":
    if len(sys.argv) != 3 and len(sys.argv) != 1:
        usage()
        exit()
    if len(sys.argv) == 3:
        if sys.argv[1] == "heap":
            heap = load_heap(sys.argv[2])
            print_heap(heap)
    else:
        for line in sys.stdin:
            heap = [int(k) for k in line.split(',')]
            print_heap(heap)
            print()
