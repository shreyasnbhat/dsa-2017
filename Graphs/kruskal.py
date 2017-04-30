from collections import defaultdict

class Graph :

    '''Level has been augmented here'''
    def __init__(self,size):
        self.adj_list = defaultdict(list)
        self.size = size

    '''This caters to an undirected graph representation'''
    def addEdge(self,u,v,w):
        self.adj_list[u].append((v,w))
        self.adj_list[v].append((u,w))

class DisjointSetUnion:
    def __init__(self):
        self.sets = []
        self.size = 0

    def makeSet(self,size):
        self.size = size
        #Initially all components are disjoint
        self.sets = [i for i in range(size)]

    def union(self,a,b):

       max_set_no = max(self.findSet(a),self.findSet(b))
       min_set_no = min(self.findSet(a),self.findSet(b))


       self.sets[:] = [min_set_no if x==max_set_no else x for x in self.sets ]




    def findSet(self,a):

        return self.sets[a]

    def printSet(self):

        print self.sets


if __name__ == '__main__':

    vertex,edges = map(int,raw_input().strip().split())
    g = Graph(vertex)
    p = minHeap()
    edge_list = []
    sorted_p = []

    DSU = DisjointSetUnion()

    DSU.makeSet(vertex)

    for i in range(edges):
        u,v,w = map(int,raw_input().strip().split())
        g.addEdge(u-1,v-1,w)
        p.insertKey((u-1,v-1,w))
        edge_list.append((u-1,v-1,w))

    sorted_edge_list = sorted(edge_list,key= lambda x :(x[2],x[0]+x[1]+x[2]))

    weight = 0
    counter = 0
    i = 0


    # Now the edges are in proper priority
    while i < len(sorted_edge_list) and counter <= vertex - 1:

        u,v,w = sorted_edge_list[i]

        if DSU.findSet(u) != DSU.findSet(v):
            weight+=w
            DSU.union(u,v)
            counter+=1

        i+=1

    print weight




