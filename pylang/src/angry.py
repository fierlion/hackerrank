import sys

def main():
    tests = int(sys.stdin.readline())
    for i in range(tests):
        raw_counts = sys.stdin.readline()
        num_studs, num_req = map(int, raw_counts.strip('\n').split(' '))
        raw_times = sys.stdin.readline()
        times = list(map(int, raw_times.strip('\n').split(' ')))
        on_time = [t for t in times if t <= 0]
        print("NO") if on_time >= num_req else print("YES")

if __name__=='__main__':
    main()
