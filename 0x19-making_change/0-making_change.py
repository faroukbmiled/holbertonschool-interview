#!/usr/bin/python3
"""0-making_change.py"""


def makeChange(coins, total):
    """makeChange func"""
    if total <= 0:
        return 0

    list = [float('inf')] * (total + 1)
    list[0] = 0

    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                list[i] = min(list[i], list[i - coin] + 1)

    if list[total] == float('inf'):
        return -1

    return list[total]
