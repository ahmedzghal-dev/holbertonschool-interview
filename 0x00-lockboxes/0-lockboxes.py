#!/usr/bin/python3
"""determines if all the boxes can be opened
"""

"""
def canUnlockAll(boxes):
    LK = []
    LB = []
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
"""
def canUnlockAll(boxes):
unlocked = [0]
    for box_id, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < len(boxes) and key not in unlocked and key != box_id:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False