import sys

def lex_next(ar):
    i = len(ar) - 2
    while not (i < 0 or ar[i] < ar[i+1]):
        i -= 1
    if i < 0:
        return False
    j = len(ar) - 1
    while not (ar[j] > ar[i]):
        j -= 1
    ar[i], ar[j] = ar[j], ar[i]
    ar[i+1:] = reversed(ar[i+1:])
    return True

def main():
    tests = int(sys.stdin.readline())
    strings = []
    for i in range(tests):
        raw_str = sys.stdin.readline()
        strip_str = raw_str.strip('\n')
        strings.append(strip_str)
    for s in strings:
        chars = list(s)
        if lex_next(chars):
            print("".join(chars))
        else:
            print("no answer")

if __name__=='__main__':
    main()
