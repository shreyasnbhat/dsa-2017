'''Heap Implementation in Python
   Standard Library Function 'heapq' could have been used
'''


class minHeap:
    def __init__(self):
        self.heap = []
        self.numberIndexArray = {}
        self.size = 0

    def parentNode(self, i):
        return (i - 1) / 2

    def insertKey(self, key):

        t = self.size
        self.numberIndexArray[key] = t

        if len(self.heap) == 0:
            self.heap.append(key)
        else:
            self.heap.append(key)
            ''' Up-heap Bubbling
                Need to swap till condition is met in order to maintain heap-property
            '''
            while self.heap[t] < self.heap[self.parentNode(t)] and t > 0:
                #Index Update while Insert
                self.numberIndexArray[self.heap[t]] = self.parentNode(t)
                self.numberIndexArray[self.heap[self.parentNode(t)]] = t
                self.heap[t], self.heap[self.parentNode(t)] = (self.heap[self.parentNode(t)], self.heap[t])
                t = self.parentNode(t)

        self.size += 1
        return t

    def getMinElement(self):
        return self.heap[0]

    ''' Need to remove minimum element from the tree '''

    def extractMinimum(self):

        toBeReturned = self.getMinElement()
        self.numberIndexArray[self.heap[self.size - 1]] = 0
        self.heap[0] = self.heap[self.size - 1]
        t = 0
        ''' Need to perform Down-heap Bubbling '''
        while 2 * t + 2 < self.size and (self.heap[t] > self.heap[2 * t + 1] or self.heap[t] > self.heap[2 * t + 2]):
            ''' Swap with Left Node if it is lesser than Right Node '''
            if self.heap[2 * t + 1] < self.heap[2 * t + 2]:
                #Index Update while delete
                self.numberIndexArray[self.heap[t]] = 2 * t + 1
                self.numberIndexArray[self.heap[2 * t + 1]] = t
                self.heap[t], self.heap[2 * t + 1] = self.heap[2 * t + 1], self.heap[t]
                t = 2 * t + 1
            else:
                #Index Update while delete
                self.numberIndexArray[self.heap[t]] = 2 * t + 2
                self.numberIndexArray[self.heap[2 * t + 2]] = t
                self.heap[t], self.heap[2 * t + 2] = self.heap[2 * t + 2], self.heap[t]
                t = 2 * t + 2
        self.heap.pop()
        self.size -= 1
        return toBeReturned

    def deleteNode(self, index):
        ''' Need to find key and reduce it the minus infinity technically -infinity ---> float("-inf') '''
        self.heap[index] -= float("inf")
        t = index
        ''' Up-heap Bubbling / MinHeapify '''
        while self.heap[t] < self.heap[self.parentNode(t)] and t > 0:
            #Index update while delete
            self.numberIndexArray[self.heap[t]] = self.parentNode(t)
            self.numberIndexArray[self.heap[self.parentNode(t)]] = t
            self.heap[t], self.heap[self.parentNode(t)] = (self.heap[self.parentNode(t)], self.heap[t])
            t = self.parentNode(t)
        self.extractMinimum()

    def printHeap(self):
        print self.heap

def search(arr,key):
    for i in range(0,len(arr)):
        if arr[i] == key :
            return i
    return -1


if __name__ == '__main__':

    minHeapObj = minHeap()
    queries = int(raw_input())
    k = 0
    for i in range(0,queries):

        q = list(map(int,raw_input().strip().split()))
        #Insert Into Heap
        if q[0] == 1 :
            minHeapObj.insertKey(q[1])
        elif q[0] == 2:
            minHeapObj.deleteNode(minHeapObj.numberIndexArray[q[1]])
        elif q[0] == 3 :
            print minHeapObj.getMinElement()


