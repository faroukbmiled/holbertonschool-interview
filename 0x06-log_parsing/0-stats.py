#!/usr/bin/python3
"""Script that read stdin line by line and computes metrics"""

import signal
import sys

size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
count = 0


def metrics():
    """Prints the metrics"""
    print('File size: {}'.format(size))
    for status_code in sorted(status_codes.keys()):
        print("{}: {}".format(status_code, status_codes[status_code]))


def keyboardInterruptHandler(signal, frame):
    """Handles the keyboard interrupt signal"""
    metrics()
    exit(0)


signal.signal(signal.SIGINT, keyboardInterruptHandler)

if __name__ == "__main__":
    """main function"""

    try:
        for lines in sys.stdin:
            try:
                elements = lines.split(" ")
                status_code = int(elements[7])
                file_size = int(elements[8])
                if status_code in status_codes:
                    status_codes[status_code] += 1
                    size += file_size
                count += 1
            except Exception:
                pass
            if count % 10 == 0:
                metrics()
                count = 0
    except KeyboardInterrupt:
        keyboardInterruptHandler()
