'''Heap Implementation in Python
   Standard Library Function 'heapq' could have been used
'''


class minHeap:
    def __init__(self):
        self.heap = []
        self.size = 0

    def parentNode(self, i):
        return (i - 1) / 2

    def insertKey(self, key):

        if len(self.heap) == 0:
            self.heap.append(key)
        else:
            self.heap.append(key)
            t = self.size
            ''' Up-heap Bubbling
                Need to swap till condition is met in order to maintain heap-property
            '''
            while self.heap[t] < self.heap[self.parentNode(t)] and t > 0:
                self.heap[t], self.heap[self.parentNode(t)] = (self.heap[self.parentNode(t)], self.heap[t])
                t = self.parentNode(t)
        self.size += 1

    def getMinElement(self):
        return self.heap[0]

    ''' Need to remove minimum element from the tree '''

    def extractMinimum(self):
        toBeReturned = self.getMinElement()
        self.heap[0] = self.heap[self.size - 1]
        t = 0
        ''' Need to perform Down-heap Bubbling '''
        while 2 * t + 2 < self.size and (self.heap[t] > self.heap[2 * t + 1] or self.heap[t] > self.heap[2 * t + 2]):
            ''' Swap with Left Node if it is lesser than Right Node '''
            if self.heap[2 * t + 1] < self.heap[2 * t + 2]:
                self.heap[t], self.heap[2 * t + 1] = self.heap[2 * t + 1], self.heap[t]
                t = 2 * t + 1
            else:
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
            self.heap[t], self.heap[self.parentNode(t)] = (self.heap[self.parentNode(t)], self.heap[t])
            t = self.parentNode(t)

        self.extractMinimum()

    def printHeap(self):
        print self.heap


if __name__ == '__main__':

    numberOfCookies, minSweetness = map(int, raw_input().strip().split())
    heapObj = minHeap()
    sweetnessLevel = list(map(int, raw_input().strip().split()))
    for i in range(0, numberOfCookies):
        heapObj.insertKey(sweetnessLevel[i])
    counter = 0

    while heapObj.size > 0:
        if heapObj.getMinElement() < minSweetness and heapObj.size > 1:
            ele1 = heapObj.extractMinimum()
            ele2 = heapObj.extractMinimum()
            heapObj.insertKey(ele1 + 2 * ele2)
            counter += 1
        else:
            break

    if heapObj.getMinElement() < minSweetness:
        print -1
    else:
        print counter


