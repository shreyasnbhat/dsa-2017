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

        self.printDSU()

    def pathCompress(self,node):
        node.parent = self.findSet(node)
        return node

    def findSet(self,node):
        while(node.parent is not node):
            node = node.parent
        return node

    def printDSU(self):
        print "Data" , "Parent"
        for i in self.tasks:
            print self.tasks[i].data , self.tasks[i].parent.data

if __name__ == "__main__":
    dsu = DSU()

    for i in range(10):
        dsu.makeSet(i)

    dsu.union(0,1)
    dsu.union(0,2)
    dsu.union(2,5)
    dsu.union(3,7)
    dsu.union(8,9)
    dsu.union(8,0)
