#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics
"""
import sys
import datetime
from collections import Counter


counter = 0
total_f_size = 0
status_codes = {'200': 0, '301': 0, '400': 0,
                '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}
try:
    for line in sys.stdin:
        try:
            counter += 1
            f_size = int(line.split()[-1].strip())
            s_code = line.split()[-2].strip()
            total_f_size += f_size
            if s_code in status_codes.keys():
                status_codes[s_code] += 1
            f_size = 0
            if counter % 10 == 0:
                print("File size: " + str(total_f_size))
                for key in sorted(status_codes.keys()):
                    if status_codes[key] != 0:
                        print(key + ": " + str(status_codes[key]))
        except Exception:
            pass
    print("File size: " + str(total_f_size))
    for key in sorted(status_codes.keys()):
        if status_codes[key] != 0:
            print(key + ": " + str(status_codes[key]))
except KeyboardInterrupt:
    print("File size: " + str(total_f_size))
    for key in sorted(status_codes.keys()):
        if status_codes[key] != 0:
            print(key + ": " + str(status_codes[key]))
    raise
