from collections import defaultdict

class Graph :

    '''Level has been augmented here'''
    def __init__(self):
        self.adj_list = defaultdict(list)
        self.level = []

    '''This caters to an undirected graph representation'''
    def addEdge(self,u,v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

    def bfs(self,start,size):

        visited = [False]*size
        self.level = [0]*size
        queue = []

        queue.append(start)
        visited[start] = True
        self.level[start] = 0

        while queue :
            '''Deque to get the element on which bfs has to be done'''
            s = queue.pop(0)
            for i in self.adj_list[s]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
                    self.level[i] = self.level[s]+1

if __name__ == '__main__':

    cases = int(raw_input().strip())

    for i in range(cases):

        vertex , edges = list(map(int,raw_input().strip().split()))
        g = Graph()

        for j in range(edges):

            u , v = list(map(int,raw_input().strip().split()))
            g.addEdge(u-1,v-1)

        start_node = int(raw_input().strip())
        g.bfs(start_node-1,vertex)
        level_list = [6*g.level[i] if i!=start_node-1 else -1 for i in range(0,len(g.level))]
        level_list.pop(start_node-1)
        level_list = ['-1' if x==0 else str(x) for x in level_list]
        print (" ").join(level_list)




