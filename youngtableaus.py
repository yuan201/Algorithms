import numpy as np
import sys

def extract_min(young, point):
    print(young)
    print(point)
    p = point
    if p[0] == young.shape[0]-1: # point at last row
        young[p[0],p[1]:] = np.concatenate(
            (young[p[0],p[1]+1:],[sys.maxsize]))
        return young
    if p[1] == young.shape[1]-1: # point at last col
        young[p[0]:,p[1]] = np.concatenate(
            (young[p[0]+1:,p[1]],[[sys.maxsize]]))
        return young
    
    if young[p[0],p[1]+1] < young[p[0]+1,p[1]]:
        young[p] = young[p[0],p[1]+1]
        return extract_min(young, (p[0],p[1]+1))
    else:
        young[p] = young[p[0]+1,p[1]]
        return extract_min(young, (p[0]+1,p[1]))
                        
