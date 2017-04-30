class IndexMinHeap:

    def __init__(self):
        self.heap = []
        self.size = 0
        self.numberIndexArray = {}

    def parentNode(self, i):
        return (i - 1) / 2

    def insertKey(self, key):

        t = self.size
        self.numberIndexArray[key] = t
        self.heap.append(key)

        '''Up Heap Bubbling'''
        while self.heap[t] < self.heap[self.parentNode(t)] and t > 0:
            # Index Update while Insert
            self.numberIndexArray[self.heap[t]] = self.parentNode(t)
            self.numberIndexArray[self.heap[self.parentNode(t)]] = t
            self.heap[t], self.heap[self.parentNode(t)] = (self.heap[self.parentNode(t)], self.heap[t])
            t = self.parentNode(t)

        self.size += 1

        return t


    '''Function to return the minimum element'''
    def extractMin(self):

        '''Put the last element as the first element of the heap and heapify'''
        toReturn = self.heap[0]
        self.numberIndexArray[self.heap[self.size-1]] = 0
        self.heap[0] = self.heap[self.size-1]

        del self.numberIndexArray[toReturn]

        self.heapify(0)
        self.heap.pop()
        self.size-=1

        return toReturn

    '''Function to delete a node from the heap'''
    def deleteNode(self,value):

        '''Now we will reduce the value of this node to minus infinity'''
        '''And then we will call extractMin'''
        self.decreaseKey(value,float('-inf'))
        self.extractMin()
        del self.numberIndexArray[value]


    '''Function to decrease a value to another value that is strictly lesser than the orgValue'''
    def decreaseKey(self,orgValue,newValue):

        '''Assuming that the value will be smaller'''
        index = self.numberIndexArray[orgValue]
        self.heap[index] = newValue

        t = index

        while self.heap[t] < self.heap[self.parentNode(t)] and t > 0:
            # Index update while delete
            self.numberIndexArray[self.heap[t]] = self.parentNode(t)
            self.numberIndexArray[self.heap[self.parentNode(t)]] = t
            self.heap[t], self.heap[self.parentNode(t)] = (self.heap[self.parentNode(t)], self.heap[t])
            t = self.parentNode(t)

    '''Function to maintain heap-order property'''
    '''Left stored at 2*i+1 and Right at 2*i+2'''
    def heapify(self,i):

        left = 2*i+1
        right = 2*i+2

        smallest = i

        if left < self.size :
            if self.heap[left]<self.heap[i]:
                smallest = left
            else :
                smallest = i

        if right < self.size:
            if right <= self.size and self.heap[right]<self.heap[smallest]:
                smallest = right

        if smallest!=i:

            self.numberIndexArray[self.heap[i]] = smallest
            self.numberIndexArray[self.heap[smallest]] = i
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]

            '''Call heapify recursively'''
            self.heapify(smallest)

    def printHeap(self):
        print "Heap"
        print self.heap
        print "Value Index"
        print self.numberIndexArray

if __name__ == '__main__':

    li = [5,4,3,2,1]

    h = IndexMinHeap()

    for i in range(len(li)):
        h.insertKey(li[i])







