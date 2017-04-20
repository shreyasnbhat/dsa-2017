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

    def bfs(self,start):

        visited = [False]*len(self.adj_list)
        self.level = [0]*len(self.adj_list)
        queue = []

        queue.append(start)
        visited[start] = True
        self.level[start] = 0

        while queue :
            s = queue.pop()
            print s
            for i in self.adj_list[s]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
                    self.level[i] = self.level[s]+1

            print self.level

if __name__ == '__main__':

    graph = Graph()
    graph.addEdge(0,1)
    graph.addEdge(0,2)
    graph.bfs(0)


