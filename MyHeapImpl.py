#import MyHeap;
from copy import deepcopy

class MyHeapImpl ():
    def __init__ (self, heap):
        self.__heap = deepcopy(heap)
        self.__size = len(self.__heap);
        print self.__heap;
    
    
    def parent(self, childIndex):
        return int(childIndex >> 1);    #left shift : div by 2
    
    
    def leftChild(self, parentIndex):
        if(parentIndex << 1 > self.__size):
            return 0;
        else:
            return parentIndex << 1;
    
    
    def rightChild(self, parentIndex):
        if(((parentIndex << 1 )+ 1) > self.__size):
            return 0;
        else:
            return ((parentIndex << 1) + 1);

    
    def findMin(self):
        return self.__heap[0];

        
    def buildHeap(self):
        len = self.__size;
        start = int(len >> 1);
        for i in range(start,0,-1):
            self.heapify(i);
    
    
    def heapify(self, heapIndex):   #heapIndex : index on which want to perform heapify (heapIndex = 1, 2, )
        currentIndx = heapIndex - 1;   #currentIndex : starts from 0
        while (True):
            leftChild = self.leftChild(currentIndx + 1) - 1;    #leftChild : starts from 0
            rightChild = self.rightChild(currentIndx + 1) - 1;  #rightChild : starts from 0
            
            if (leftChild == -1 and rightChild == -1):
                break;
            elif (leftChild != -1 and rightChild != -1 ):
                if (self.__heap[leftChild] <= self.__heap[rightChild]):
                    if (self.__heap[leftChild] >= self.__heap[currentIndx]):
                        break;
                    else:
                        temp = self.__heap[currentIndx];
                        self.__heap[currentIndx] = self.__heap[leftChild];
                        self.__heap[leftChild] = temp;
                        currentIndx = leftChild;
                else:
                    if (self.__heap[rightChild] > self.__heap[currentIndx]):
                        break;
                    else:
                        temp = self.__heap[currentIndx];
                        self.__heap[currentIndx] = self.__heap[rightChild];
                        self.__heap[rightChild] = temp;
                        currentIndx = rightChild;
            elif (rightChild == -1):
                if (self.__heap[leftChild] >= self.__heap[currentIndx]):
                    break;
                else:
                    temp = self.__heap[currentIndx];
                    self.__heap[currentIndx] = self.__heap[leftChild];
                    self.__heap[leftChild] = temp;
                    currentIndx = leftChild;
                    break;
            elif (leftChild == -1):
                raise "INVALID HEAP, VIOLATING STRUCTURAL PROPERTY", leftChild;
                
                
    def insertElement(self, e):
        self.__heap.append(e);  # add an element at the end of list
        self.__size = len(self.__heap); #update private size memnber
        currentIndx = self.__size - 1; # form 0
        
        while(1):
            parentIndx = self.parent(currentIndx + 1) - 1; # form 0
            if(parentIndx == -1):
                break;
            else:
                if(self.__heap[parentIndx] > self.__heap[currentIndx]):
                    temp = self.__heap[currentIndx];
                    self.__heap[currentIndx] = self.__heap[parentIndx];
                    self.__heap[parentIndx] = temp;
                    currentIndx = parentIndx;
                else:
                    break;
    
    
    def deleteMin(self):
        rmin = self.findMin();
        self.__heap[0] = self.__heap.pop();
        self.__size = len(self.__heap);
        self.display();
        self.heapify(1);
        return rmin
        
        
    def heapSort(self):
        heapSize = self.__size;
        for i in range(1,heapSize):
            min = self.findMin();
            self.__heap[0] = self.__heap.pop(heapSize - i);
            self.__heap.insert(heapSize - i, min);
            self.__size = heapSize - i;
            self.heapify(1);
        self.__size = heapSize;
        
    def display(self):
        h = 1;
        i = 1;
        print self.__heap[0]
        
        for e in self.__heap[1:]:
            if (i == (2<<h) - 1):
                print e,
                print 
                h += 1;
            else:
                print e,
            i += 1;
        print "\n"
        
        
h = [8,7,25,8,13,46,3,12,11,17,19,36];

a = MyHeapImpl(h);
a.display();

print "Build a Heap:";
a.buildHeap();
a.display();
print "Min: %d"%a.findMin();

print "Insert an Element:";
a.insertElement(2);
a.display();
print "Min: %d"%a.findMin();

print "Delete Min Element: ";
min = a.deleteMin();
a.display();
print "Removed Min: %d"%min;
print "New Min: %d"%a.findMin();

print "Sort a Heap Decreasing order In place: ";
a.heapSort();
a.display();
a.buildHeap();
a.display();