from collections import defaultdict

class Graph :

    '''Level has been augmented here'''
    def __init__(self,size):
        self.size = size
        self.adj_list = defaultdict(list)
        self.visited = [False]*size
        self.level = [0]*size
        self.color = [0]*size

    '''This caters to an undirected graph representation'''
    def addEdge(self,u,v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

    '''Assuming colors are 1 and 2'''
    def bfs(self,start):
        queue = []
        queue.append(start)
        self.visited[start] = True
        self.level[start] = 0
        self.color[start] = 1

        while queue :
            s = queue.pop()
            for i in self.adj_list[s]:
                if self.visited[i] == False:
                    queue.append(i)
                    self.visited[i] = True
                    self.level[i] = self.level[s]+1
                    if self.color[s] == 1 :
                        self.color[i] = 2
                    elif self.color[s] == 2 :
                        self.color[i] = 1

    def bipartite_check(self):

        check = 0

        for i in range(len(self.adj_list)):
            nodes = self.adj_list[i]
            for j in nodes:
                if self.color[i] == self.color[j]:
                    check = 1
                    break
        if check == 0 :
            print "Graph is Bipartite"
        elif check==1 :
            print "Graph is not Bipartite"



if __name__ == '__main__':

    cases = int(raw_input().strip())

    for i in range(cases):

        vertex, edges = list(map(int, raw_input().strip().split()))
        g = Graph(vertex)

        for j in range(edges):
            u, v = list(map(int, raw_input().strip().split()))

            # Need to do this to enable zero-indexing
            g.addEdge(u - 1, v - 1)

        g.bfs(0)
        g.bipartite_check()

