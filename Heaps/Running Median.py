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

def average(a,b):
    return (a+b)/2.0

def getMedian(element,median,lHeap,rHeap):

    sign = lHeap.size - rHeap.size

    if sign == 1 :

        if element < median :
            rHeap.insertKey(lHeap.extractMaximum())
            lHeap.insertKey(element)
        else :
            rHeap.insertKey(element)

        return average(rHeap.getMinElement(),lHeap.getMaxElement())
    elif sign == 0 :

        if element < median :
            lHeap.insertKey(element)
            return lHeap.getMaxElement()
        else :
            rHeap.insertKey(element)
            return rHeap.getMinElement()

    elif sign == -1 :

        if element > median :
            lHeap.insertKey(rHeap.extractMinimum())
            rHeap.insertKey(element)
        else :
            lHeap.insertKey(element)

        return average(rHeap.getMinElement(),lHeap.getMaxElement())



if __name__ == '__main__':

    arr = []
    minH = minHeap()
    maxH = maxHeap()
    median = 0
    size = int(raw_input().strip())
    i = 0

    for i in range(0,size):
        arr.append(float(raw_input().strip()))

    m = 0
    for i in range(0,len(arr)):

        m = getMedian(arr[i],m,maxH,minH)
        print m

