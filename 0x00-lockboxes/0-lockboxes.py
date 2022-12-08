#!/usr/bin/python3
"""check if all boxes can be opened"""

def canUnlockAll(boxes):
    done = []
    keys = [0]

    while len(keys) > 0:
        key = keys.pop()
        if key not in done:
            done.append(key)
            keys.extend(boxes[key])

    if len(done) == len(boxes):
        return True
    return False
