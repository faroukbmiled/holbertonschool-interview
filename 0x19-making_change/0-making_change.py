#!/usr/bin/python3
"""0-making_change.py"""


def makeChange(coins, total):
    """makeChange func"""
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    memo = {}

    def dp(n):
        if n in memo:
            return memo[n]

        if n == 0:
            return 0

        min_coins = float('inf')

        for coin in coins:
            if coin <= n:
                min_coins = min(min_coins, dp(n - coin) + 1)

        memo[n] = min_coins
        return min_coins

    result = dp(total)

    if result == float('inf'):
        return -1

    return result
