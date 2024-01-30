#!/usr/bin/python3
"""0-making_change.py"""


def makeChange(coins, total):
    """makeChange func with memoization"""

    if total < 0:
        return 0

    memo = {}

    def dp(amount):
        if amount < 0:
            return float('inf')
        if amount == 0:
            return 0
        if amount not in memo:
            memo[amount] = min(dp(amount - coin) + 1 for coin in coins)
        return memo[amount]

    result = dp(total)
    return result if result != float('inf') else -1
