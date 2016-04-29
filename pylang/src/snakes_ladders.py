import sys

def dijkstra(graph, src, dest, visited, distances, predecessors):
    if src == dest:
        path=[]
        pred=dest
        while pred != None:
            path.append(pred)
            pred=predecessors.get(pred,None)
        try:
            print(str(distances[dest]))
        except KeyError:
            print("-1")
    else :     
        if not visited: 
            distances[src]=0
        for neighbor in graph[src] :
            if neighbor not in visited:
                new_distance = distances[src] + graph[src][neighbor]
                if new_distance < distances.get(neighbor,float('inf')):
                    distances[neighbor] = new_distance
                    predecessors[neighbor] = src
        visited.append(src)
        unvisited={}
        for k in graph:
            if k not in visited:
                unvisited[k] = distances.get(k,float('inf'))        
        x=min(unvisited, key=unvisited.get)
        dijkstra(graph,x,dest,visited,distances,predecessors)

def main():
    tests = []
    num_tests = int(sys.stdin.readline())
    for i in range(num_tests):
        snakes = []
        ladders = []
        num_snakes = int(sys.stdin.readline())
        for j in range(num_snakes):
            s_line = sys.stdin.readline()
            snakes.append(map(int, s_line.strip('\n').split(' ')))
        num_ladders = int(sys.stdin.readline())
        for j in range(num_ladders):
            l_line = sys.stdin.readline()
            ladders.append(map(int, l_line.strip('\n').split(' ')))
        tests.append([snakes, ladders])
    for test in tests:
        board = [i for i in range(1,101)]
        # create graph
        board_al = {}
        for square in range(100):
            sq_val = board[square]
            if square < 95:
                board_al[sq_val] = set([sq for sq in board[square+1:square+7]])
            else:
                board_al[sq_val] = set([sq for sq in board[square+1:]])
        for l in test[0]:
            board_al.pop(l[0])
            for key in range(l[0]-6, l[0]):
                if key in board_al:
                    val = board_al[key]
                    if l[0] in val:
                        val.remove(l[0])
                        val.add(l[1])
        for s in test[1]:
            board_al.pop(s[0])
            for key in range(s[0]-6, s[0]):
                if key in board_al:
                    val = board_al[key]
                    if s[0] in val:
                        val.remove(s[0])
                        val.add(s[1])
        keys = [k for k in board_al]
        values = [board_al[k] for k in keys]
        val_dicts = [{v:1 for v in val} for val in values]
        board_dict = dict(zip(keys, val_dicts))
        visited = []
        distances = {} 
        predecessors = {}
        dijkstra(board_dict, 1, 100, visited, distances, predecessors)
       
if __name__=='__main__':
    main()

