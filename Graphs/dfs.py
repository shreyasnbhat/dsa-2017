from collections import defaultdict

class Graph :

    '''Level has been augmented here'''
    def __init__(self,size):
        self.adj_list = defaultdict(list)
        self.level = []
        self.size = size
        self.visited = [False]*size
        self.parent = defaultdict(int)

    '''This caters to an undirected graph representation'''
    def addEdge(self,u,v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

    def set_visited_all_false(self):
        self.visited = [False]*self.size

    def dfs_r(self,s):

        self.visited[s] = True
        print s

        for n in self.adj_list[s]:
            if self.visited[n] == False:
                self.dfs_r(n)

    def dfs_i(self,s):

        self.set_visited_all_false()

        self.visited[s] = True
        node_stack = []
        node_stack.append(s)

        while node_stack :
            m = node_stack[-1]
            node_stack.pop()
            print m
            for i in self.adj_list[m]:
                if self.visited[i] == False:
                    node_stack.append(i)
                    self.visited[i] = True

    def cycle_detect(self):
        return

if __name__ == '__main__':

    cases = int(raw_input().strip())

    for i in range(cases):

        vertex, edges = list(map(int, raw_input().strip().split()))
        g = Graph(vertex)

        for j in range(edges):
            u, v = list(map(int, raw_input().strip().split()))

            #Need to do this to enable zero-indexing
            g.addEdge(u - 1, v - 1)

        print "Recusrive DFS"
        g.dfs_r(0)
        print "Iterative DFS"
        g.dfs_i(0)











