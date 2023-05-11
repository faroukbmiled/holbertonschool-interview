#!/usr/bin/python3
"""count using reddit api"""
import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """begin func"""
    if counts is None:
        counts = {}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {"User-Agent": "Mozilla/5.0"}
    params = {"limit": 100, "after": after}
    response = requests.get(url, headers=headers, params=params)

    if response.status_code == 200:
        data = response.json()
        articles = data["data"]["children"]

        for article in articles:
            title = article["data"]["title"].lower()

            for word in word_list:
                if word.lower() in title:
                    counts[word] = counts.get(
                        word, 0) + title.count(word.lower())

        after = data["data"]["after"]
        if after is not None:
            return count_words(subreddit, word_list, after, counts)

    sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))

    for word, count in sorted_counts:
        print(f"{word}: {count}")
