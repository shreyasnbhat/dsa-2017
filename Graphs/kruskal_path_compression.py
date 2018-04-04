from collections import defaultdict

class Node:
    def __init__(self,data):
        self.data = data
        self.parent = self
        self.rank = 0

class DSU:

    tasks = {}

    def __init__(self):
        self.tasks = {}

    def makeSet(self,data):
        self.tasks[data] = Node(data)

    def union(self,entry1,entry2):
        node1 = self.tasks[entry1]
        node2 = self.tasks[entry2]

        parent1 = self.pathCompress(node1)
        parent2 = self.pathCompress(node2)

        if parent1.data == parent2.data:
            return
        elif parent1.rank > parent2.rank:
            parent2.parent = parent1
        elif parent1.rank == parent2.rank:
            parent1.rank+=1
            parent2.parent = parent1
        else:
            parent1.parent = parent2

    def pathCompress(self,node):
        node.parent = self.findSet(node)
        return node.parent

    def findSet(self,node):
        while(node.parent is not node):
            node = node.parent
        return node

    def printDSU(self):
        print "Data" , "Parent"
        for i in self.tasks:
            print self.tasks[i].data , self.tasks[i].parent.data

class Graph:
    def __init__(self,vertices,edges):
        self.adj_list = defaultdict(list)
        self.vertices = vertices
        self.edges = edges

    def add_edge(self,u,v,w):
        self.adj_list[u].append((v,w))
        self.adj_list[v].append((u,w))


if __name__ == "__main__":

    vertices,edges = map(int,raw_input().strip().split(' '))
    graph = Graph(vertices,edges)

    edge_list = []

    for i in range(edges):
        u,v,w = map(int,raw_input().strip().split(' '))
        graph.add_edge(u,v,w)
        edge_list.append((u,v,w))

    chooser = sorted(edge_list,key = lambda x : (x[2], x[0] + x[1] + x[2]))

    dsu = DSU()

    # Make Set for DSU
    for i in range(vertices):
        dsu.makeSet(i+1)

    weight_sum = 0
    chosen_edges = 0
    for u,v,w in chooser:
        if chosen_edges <= vertices - 2:
            u_task = dsu.tasks[u]
            v_task = dsu.tasks[v]
            if dsu.pathCompress(u_task).parent != dsu.pathCompress(v_task).parent :
                weight_sum+=w
                chosen_edges+=1
                dsu.union(u,v)

    print weight_sum
