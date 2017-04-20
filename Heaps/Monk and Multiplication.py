'''Heap Implementation in Python
   Standard Library Function 'heapq' could have been used
'''


class maxHeap:
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
            while self.heap[t] > self.heap[self.parentNode(t)] and t > 0:
                self.heap[t], self.heap[self.parentNode(t)] = (self.heap[self.parentNode(t)], self.heap[t])
                t = self.parentNode(t)
        self.size += 1

    def getMaxElement(self):
        return self.heap[0]

    ''' Need to remove minimum element from the tree '''

    def extractMaximum(self):
        toBeReturned = self.getMaxElement()
        self.heap[0] = self.heap[self.size - 1]
        t = 0
        ''' Need to perform Down-heap Bubbling '''
        while 2 * t + 2 < self.size and (self.heap[t] < self.heap[2 * t + 1] or self.heap[t] < self.heap[2 * t + 2]):
            ''' Swap with Left Node if it is lesser than Right Node '''
            if self.heap[2 * t + 1] > self.heap[2 * t + 2]:
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
        if index != 0:
            self.heap[index] -= float("-inf")
            t = index
            ''' Up-heap Bubbling / MinHeapify '''
            while self.heap[t] > self.heap[self.parentNode(t)] and t > 0:
                self.heap[t], self.heap[self.parentNode(t)] = (self.heap[self.parentNode(t)], self.heap[t])
                t = self.parentNode(t)

            self.extractMaximum()
        else:
            self.extractMaximum()

    def printHeap(self):
        print self.heap

    def getHeap(self):
        return self.heap


def heapSort(t):
    k = []
    for j in range(0, t.size):
        k.append(t.getMaxElement())
        t.extractMaximum()
    return k


if __name__ == '__main__':

    '''Needed to construct a deepcopy of the heap'''
    import copy

    cases = int(raw_input())
    p = list(map(int, raw_input().strip().split()))
    heapObj = maxHeap()

    m = []
    '''Prints product of max 3 numbers for a range [0,i]'''
    for i in range(0, cases):
        heapObj.insertKey(p[i])
        heapObj.printHeap()
        if i < 2:
            print -1
        elif i == 2:
            m = heapSort(copy.deepcopy(heapObj))
            print m[0] * m[1] * m[2]
        else:
            if p[i] > m[0]:
                m[2] = m[1]
                m[1] = m[0]
                m[0] = p[i]
            elif p[i] > m[1]:
                m[2] = m[1]
                m[1] = p[i]
            elif p[i] > m[2]:
                m[2] = p[i]
            print m[0] * m[1] * m[2]
