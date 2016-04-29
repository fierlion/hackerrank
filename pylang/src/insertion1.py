import sys

def nice_print(arr_in):
    sys.stdout.write(str(arr_in[0]))
    for i in range(1, len(arr_in)):
        sys.stdout.write(" " + str(arr_in[i]))
    sys.stdout.write('\n')

def main():
    arr_size = int(sys.stdin.readline())
    arr_raw = sys.stdin.readline()
    unsorted = list(map(int, arr_raw.strip('\n').split(' ')))
    e = unsorted[-1]
    #find insertion point
    for i in range(len(unsorted)):
        if e < unsorted[i]:
	    #make space
            for j in range(len(unsorted)-1, i, -1):
                unsorted[j] = unsorted[j-1]
                nice_print(unsorted) 
            unsorted[i] = e
            nice_print(unsorted)
            break

if __name__=='__main__':
    main()
