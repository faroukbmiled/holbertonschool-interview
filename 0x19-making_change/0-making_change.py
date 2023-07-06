#!/usr/bin/python3
"""0-making_change.py"""


def makeChange(coins, total):
    """makeChange func"""
    dp = {0: 0}

    for i in range(1, total + 1):
        dp[i] = float('inf')

        for coin in sorted(coins, reverse=True):
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)
            else:
                break

    if dp[total] == float('inf'):
        return -1

    return dp[total]
