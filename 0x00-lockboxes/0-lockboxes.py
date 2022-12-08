#!/usr/bin/python3
"""check if all boxes can be opened"""


def canUnlockAll(boxes):
    """canUnlockAll function"""
    done = []
    keys = [0]

    for key in keys:
        if key not in done:
            done.append(key)
            for box in boxes[key]:
                if box not in keys:
                    keys.append(box)

    if len(done) == len(boxes):
        return True
    return False
