#!/usr/bin/python3
"""read stdin lines"""
import sys

size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
count = 0

try:
    for lines in sys.stdin:
        try:
            elements = lines.split(" ")
            status_code = int(elements[-2]) if elements[-2].isdigit() else 0
            file_size = int(elements[-1])

            if status_code in status_codes:
                status_codes[status_code] += 1
                size += file_size
            count += 1
        except Exception:
            pass
        if count % 10 == 0:
            print('File size: {}'.format(size))
            for status_code in sorted(status_codes.keys()):
                if status_codes[status_code] > 0:
                    print("{}: {}".format(status_code, status_codes[status_code]))
            count = 0
except KeyboardInterrupt:
    print('File size: {}'.format(size))
    for status_code in sorted(status_codes.keys()):
        if status_codes[status_code] > 0:
            print("{}: {}".format(status_code, status_codes[status_code]))
    raise
