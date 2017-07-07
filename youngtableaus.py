import numpy as np

def extract_min(young):
    if young.shape[0] == 1:
        return young[0, -1]
    if young.shape[1] == 1:
        return young[-1, 0]
    if young[0,1] < young[1,0]:
        return extract_min(young[1:])
    else:
        return extract_min(young[:, 1:])
