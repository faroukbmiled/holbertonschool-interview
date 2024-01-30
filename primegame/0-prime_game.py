#!/usr/bin/python3
"""Prime Game Module"""


def is_prime_number(n):
    """is_prime_number"""
    for i in range(2, int(n ** 0.5) + 1):
        if not n % i:
            return False
    return True


def add_prime_number(n, primes_list):
    """add_prime_number"""
    last_prime = primes_list[-1]
    if n > last_prime:
        for i in range(last_prime + 1, n + 1):
            if is_prime_number(i):
                primes_list.append(i)
            else:
                primes_list.append(0)


def determine_round_winner(round_number, primes_list):
    """determine_round_winner"""
    prime_count = sum((i != 0 and i <= round_number) for i in primes_list[:round_number + 1])
    return "Maria" if prime_count % 2 else "Ben"


def isWinner(num_rounds, round_values):
    """isWinner"""
    players_score = {"Maria": 0, "Ben": 0}
    primes = [0, 0, 2]
    add_prime_number(max(round_values), primes)

    for current_round in range(num_rounds):
        round_winner = determine_round_winner(round_values[current_round], primes)
        if round_winner:
            players_score[round_winner] += 1

    if players_score["Maria"] > players_score["Ben"]:
        return "Maria"
    elif players_score["Ben"] > players_score["Maria"]:
        return "Ben"

    return None
