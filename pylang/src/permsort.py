import itertools
import sys

def get_ord_val(arr):
    result = 0
    for i in range(len(arr)):
        place = abs(i - (len(arr)-1))
        ord_result = ord(arr[i]) if place == 0 else (ord(arr[i]) * (10**place))
        result += ord_result
    return result

def get_next_highest(test):
    splittest = (list(test))
    test_val = get_ord_val(splittest)
    vals = {} 
    perms = itertools.permutations(test)
    first = next(perms)
    try:
        next_out = next(perms)
        return "no answer" if (next_out == first) else "".join(next_out)
    except StopIteration:
        return("no answer")

def main():
    tests = int(sys.stdin.readline())
    strings = []
    for i in range(tests):
        raw_str = sys.stdin.readline()
        strip_str = raw_str.strip('\n')
        strings.append(strip_str)
    for s in strings:
        print(get_next_highest(s))

if __name__=='__main__':
    main()
