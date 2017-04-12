from collections import defaultdict

class Graph :

    '''Components and edges_visited has been augmented here'''
    def __init__(self,size):
        self.adj_list = defaultdict(list)
        self.components = 0
        self.size = size
        self.edge_count_visited = 0
        self.visited = [False]*size
        self.parent = defaultdict(int)

    '''This caters to an undirected graph representation'''
    def addEdge(self,u,v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)

    def set_visited_all_false(self):
        self.visited = [False]*self.size

    def dfs_visit_i(self,s):

        self.visited[s] = True
        node_stack = []
        node_stack.append(s)

        while node_stack :
            m = node_stack[-1]
            node_stack.pop()
            for i in self.adj_list[m]:
                if self.visited[i] == False:
                    node_stack.append(i)
                    self.edge_count_visited += 1
                    self.visited[i] = True

    '''Function to do a complete dfs of the graph if it has many connected components'''
    def dfs_complete(self):
        for i in range(0,len(self.visited)):
            if self.visited[i] == False :
                self.components+=1
                self.dfs_visit_i(i)

if __name__ == '__main__':

    cases = int(raw_input().strip())

    for i in range(cases):

        vertex,edges,c_lib,c_road = list(map(int, raw_input().strip().split()))
        g = Graph(vertex)

        total_cost = 0

        for j in range(edges):
            u, v = list(map(int, raw_input().strip().split()))

            #Need to do this to enable zero-indexing
            g.addEdge(u - 1, v - 1)

        g.dfs_complete()

        '''Makes more sense to contruct a library in each city'''
        if c_road > c_lib :
            total_cost = vertex * c_lib
            print total_cost
        else :
            total_cost = g.edge_count_visited * c_road + c_lib*g.components
            print total_cost
