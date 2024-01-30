#!/usr/bin/python3
"""0-making_change.py"""


def makeChange(coins, total):
    """makeChange func"""
    if total < 0:
        return 0

    coins.sort(reverse=True)
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        if coin > total:
            continue

        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
