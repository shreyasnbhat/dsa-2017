import heapq
from collections import defaultdict

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

class Graph :

    '''Components and edges_visited has been augmented here'''
    def __init__(self,size):
        self.adj_list = defaultdict(list)
        self.size = size
        self.visited = [False]*size
        self.parent = defaultdict(int)
        self.dist = defaultdict(int)

    '''This caters to an undirected graph representation'''
    def addEdge(self,u,v,w):
        self.adj_list[u].append((v,w))
        self.adj_list[v].append((u,w))

    def djikstra(self,start):

        #Insert into priority queue
        fin_dist = [(i,float('inf')) if i!=start else (i,0) for i in range(self.size)]

        #Set all distances to infinity
        for i in range(self.size):
            self.dist[i] = float('inf')

        imh = IndexMinHeap()

        self.dist[start] = 0

        for i in range(self.size):
            imh.insertKey(fin_dist[i])

        while imh.size != 0 :

            vertex,distance = imh.extractMin()
            self.visited[vertex] = True

            #Update extracted distance in the self.dist[] dict
            for j in self.adj_list[vertex] :
                if self.visited[j[0]]==False:
                    alt_dist = self.dist[vertex] + j[1]
                    #Need to relax the distances
                    index = imh.numberIndexArray[j[0]]
                    dist_imh = imh.heap[index][1]
                    if alt_dist < dist_imh:
                        imh.decreaseKey((j[0],dist_imh),(j[0],alt_dist))
                        self.dist[j[0]] = alt_dist

if __name__ == '__main__':

    import sys

    cases = int(sys.stdin.readline().strip())



    for i in range(cases):

        vertex, edges = list(map(int, sys.stdin.readline().strip().split()))
        g = Graph(vertex)

        for j in range(edges):
            u, v , weight = list(map(int, sys.stdin.readline().strip().split()))

            # Need to do this to enable zero-indexing
            g.addEdge(u - 1, v - 1,weight)

        start = int(sys.stdin.readline().strip())

        g.djikstra(start-1)

        for k in range(len(g.dist)):
            if k!=start-1:
                if g.dist[k] == float('inf'):
                    sys.stdout.write(str(-1)+" ")
                else :
                    sys.stdout.write(str(g.dist[k])+" ")

        print

