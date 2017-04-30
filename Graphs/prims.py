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


class IndexMinHeap:

    def __init__(self):
        self.heap = []
        self.size = 0
        self.numberIndexArray = {}

    def parentNode(self, i):
        return (i - 1) / 2

    def insertKey(self, key):

        t = self.size
        self.numberIndexArray[key[0]] = t
        self.heap.append(key)

        '''Up Heap Bubbling'''
        while self.heap[t][1] < self.heap[self.parentNode(t)][1] and t > 0:
            # Index Update while Insert
            self.numberIndexArray[self.heap[t][0]] = self.parentNode(t)
            self.numberIndexArray[self.heap[self.parentNode(t)][0]] = t
            self.heap[t], self.heap[self.parentNode(t)] = (self.heap[self.parentNode(t)], self.heap[t])
            t = self.parentNode(t)

        self.size += 1

        return t

    '''Function to return the minimum element'''
    def extractMin(self):

        '''Put the last element as the first element of the heap and heapify'''
        toReturn = self.heap[0]
        self.numberIndexArray[self.heap[self.size-1][0]] = 0
        self.heap[0] = self.heap[self.size-1]


        self.heapify(0)
        self.heap.pop()
        self.size-=1

        return toReturn

    '''Function to delete a node from the heap'''
    def deleteNode(self,value):

        '''Now we will reduce the value of this node to minus infinity'''
        '''And then we will call extractMin'''
        self.decreaseKey(value,(value[0],float('-inf')))
        self.extractMin()
        del self.numberIndexArray[value[0]]


    '''Function to decrease a value to another value that is strictly lesser than the orgValue'''
    def decreaseKey(self,orgValue,newValue):

        '''Assuming that the value will be smaller'''
        index = self.numberIndexArray[orgValue[0]]
        self.heap[index] = newValue

        t = index

        while self.heap[t][1] < self.heap[self.parentNode(t)][1] and t > 0:
            # Index update while delete
            self.numberIndexArray[self.heap[t][0]] = self.parentNode(t)
            self.numberIndexArray[self.heap[self.parentNode(t)][0]] = t
            self.heap[t], self.heap[self.parentNode(t)] = (self.heap[self.parentNode(t)], self.heap[t])
            t = self.parentNode(t)

    '''Function to maintain heap-order property'''
    '''Left stored at 2*i+1 and Right at 2*i+2'''
    def heapify(self,i):

        left = 2*i+1
        right = 2*i+2

        smallest = i

        if left < self.size :
            if self.heap[left][1]<self.heap[i][1]:
                smallest = left
            else :
                smallest = i

        if right < self.size:
            if right <= self.size and self.heap[right][1]<self.heap[smallest][1]:
                smallest = right

        if smallest!=i:

            self.numberIndexArray[self.heap[i][0]] = smallest
            self.numberIndexArray[self.heap[smallest][0]] = i
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]

            '''Call heapify recursively'''
            self.heapify(smallest)

    def printHeap(self):
        print "Heap"
        print self.heap
        print "Value Index"
        print self.numberIndexArray


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
    p = IndexMinHeap()

    DSU = DisjointSetUnion()

    DSU.makeSet(vertex)

    for i in range(edges):
        u, v, w = map(int, raw_input().strip().split())
        g.addEdge(u - 1, v - 1, w)

    start = int(raw_input().strip())
    weight = 0
    marked = [False]*vertex
    #Insert in the format of (weight,vertex)
    p.insertKey((start-1,0))

    while len(p.heap)!=0 :

        #Select edge with minimum weight
        v,w = p.extractMin()
        if marked[v] == True :
            continue
        else :
            weight+=w

            marked[v] = True
            for i in g.adj_list[v]:
                if marked[i[0]] == False:
                    p.insertKey(i)

    print weight


