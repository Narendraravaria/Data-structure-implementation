import abc

class MyHeap(object):
    __metaclass__ = abc.ABCMeta
    
    @abc.abstractmethod
    
    def display(self):
        pass 
    def parent(self, childIndex):
        pass
    def leftChild(self, parentIndex):
        pass
    def rightChild(self, parentIndex):
        pass 
    def  heapBuild(self):
        pass
    def findMin(self):
        pass
    def heapify(self, heapIndex):
        pass
    def insertElement(self, e):
        pass
    def deleteMin(self):
        pass
    def heapSort(self):
        pass 