#!/usr/bin/python3
"""read stdin lines"""
import sys

size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
count = 0

try:
    for lines in sys.stdin:
        try:
            sp = lines.split(" ")
            if len(sp) > 2:
                size += int(sp[-1])
                status_code = int(sp[-2]) if sp[-2].isdigit() else 0
                if status_code in status_codes:
                    status_codes[status_code] += 1
            count += 1
        except Exception:
            pass
        if count % 10 == 0:
            print("File size: {}".format(size))
            for key, value in sorted(status_codes.items()):
                if value != 0:
                    print("{}: {}".format(key, value))
            count = 0

except KeyboardInterrupt:
    print("File size: {}".format(size))
    for key, value in sorted(status_codes.items()):
        if value != 0:
            print("{}: {:d}".format(key, value))
    raise
