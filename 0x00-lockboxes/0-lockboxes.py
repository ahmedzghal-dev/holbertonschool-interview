#!/usr/bin/python3
"""determines if all the boxes can be opened
"""


def canUnlockAll(boxes):
    LK = []
    LB = []
    a = 0
    for i in range(len(boxes) - 1):
        LB.append(i+1)
    LK.extend(boxes[0])
    T = []
    B = []
    Z = LK[0:len(LK)]
    while len(LB) != 0 and T != B:
        Z = LK[0:len(LK)]
        T = len(LB)
        for i in Z:
            if i in LB:
                LK.extend(boxes[i])
            if i in LB:
                LB.pop(LB.index(i))
            else:
                True
        B = len(LB)
    if len(LB) == 0:
        print("True")
    else:
        print("False")
