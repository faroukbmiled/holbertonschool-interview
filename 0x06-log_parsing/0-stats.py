#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics"""""
import sys


def metrics(total_size, status_codes):
    """Prints the metrics"""
    print(f'File size: {total_size}')
    for status_code in sorted(status_codes.keys()):
        print(f"{status_code}: {status_codes[status_code]}")


size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
count = 0
try:
    while True:
        line = input()
        count += 1
        elements = line.split()
        if len(elements) != 9:
            continue
        status_code = int(elements[7])
        file_size = int(elements[8])
        if status_code in status_codes:
            status_codes[status_code] += 1
            size += file_size
        if count % 10 == 0:
            metrics(size, status_codes)
except KeyboardInterrupt:
    metrics(size, status_codes)
