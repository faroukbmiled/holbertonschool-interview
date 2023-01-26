#!/usr/bin/python3
"""Script that read stdin line by line and computes metrics"""
import fileinput


def metrics(total_size, status_codes):
    """Prints the metrics"""
    print('File size: {}'.format(total_size))
    for status_code in sorted(status_codes.keys()):
        print("{}: {}".format(status_code, status_codes[status_code]))


size = 0
status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
count = 0

if __name__ == "__main__":
    """ main """

    try:
        for i in fileinput.input():
            try:
                elements = i.split(" ")
                status_code = int(elements[7])
                file_size = int(elements[8])
                if status_code in status_codes:
                    status_codes[status_code] += 1
                    size += file_size
                count += 1
            except Exception:
                pass
            if count % 10 == 0:
                metrics(size, status_codes)
        metrics(size, status_codes)
    except KeyboardInterrupt:
        metrics(size, status_codes)
        raise
