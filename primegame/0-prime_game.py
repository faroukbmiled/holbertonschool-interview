#!/usr/bin/python3
"""Prime Game Module"""


def is_prime(n):
    """is_prime: Check if a number is prime"""
    if n < 2:
        return False

    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False

    for i in range(2, int(n**0.5) + 1):
        if sieve[i]:
            for j in range(i * i, n + 1, i):
                sieve[j] = False

    return sieve[n]


def isWinner(x, nums):
    """
    isWinner: Determines the winner of the prime game for each round.
    """
    if not nums or x <= 0:
        return None

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        prime_count = sum(1 for i in range(1, n + 1) if is_prime(i))
        if prime_count % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
