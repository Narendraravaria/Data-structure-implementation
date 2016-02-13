package stringalgo;
import java.util.ArrayList;

//HeapIndex starts from 1...size

//METHODS:
//		heapBuild()				RUNNING TIME : O(n)
//		findMin()				RUNNING TIME : O(1)
//		insertElement(int e)	RUNNING TIME : O(log(n))
//	    int deleteMin()			RUNNING TIME : O(log(n))
//		heapify(int heapIndex)	RUNNING TIME : O(log(n))
//		heapSort()				RUNNING TIME : O(nlogn)

public class MyHeapImpl implements MyHeap {
	
	//public int [] heap;
	//public int size;
	private ArrayList<Integer> heap = new ArrayList<Integer>();
	private int size ;
	
	public MyHeapImpl(int[] elements){
		
		for (int i = 0; i < elements.length; i++)
			heap.add(elements[i]);
		size = heap.size();
	}
	
	
	public int parent(int childIndex)
	{
		//return (int) Math.floor(childIndex/2);
		return (childIndex >> 1);
	}
	
	
	public int leftChild(int parentIndex)
	{
		if (parentIndex << 1 > size)
			return 0;
		else
			return parentIndex << 1;
	}
	
	
	public int rightChild(int parentIndex)
	{
		if (((parentIndex << 1) + 1) > size)
			return 0;
		else
			return ((parentIndex << 1) + 1);
	}
	
	
	public void heapBuild()
	{
		//int len =(int) Math.floor(heap.length/2);
		int len = heap.size() >> 1;
		int i;
		for (i = len; i >= 1; i--)
		{
			this.heapify(i);
		}
		
	}
	
	
	public int findMin()
	{
		return heap.get(0);
	}
	
	
	public void heapify(int heapIndex)
	{
		int currentIndex = heapIndex - 1;
		
		while (true)
		{
			int leftChild = leftChild(currentIndex + 1) - 1;
			int rightChild = rightChild(currentIndex + 1) - 1;
			
			if (leftChild == -1 && rightChild == -1)
			{
				break;
			}
			else if (leftChild != -1 && rightChild != -1)
			{
				
				if (heap.get(leftChild) <= heap.get(rightChild))
				{	
					
					if (heap.get(leftChild) >= heap.get(currentIndex))
						break;
					else 
					{
						int temp = heap.get(leftChild);
						heap.add(leftChild, heap.get(currentIndex));
						heap.remove(leftChild + 1);
						heap.add(currentIndex, temp);
						heap.remove(currentIndex + 1);
						currentIndex = leftChild;
					}
					
				}
				else
				{
					
					if (heap.get(rightChild) >= heap.get(currentIndex))
						break;
					else 
					{
						int temp = heap.get(rightChild);
						heap.add(rightChild, heap.get(currentIndex));
						heap.remove(rightChild + 1);
						heap.add(currentIndex, temp);
						heap.remove(currentIndex + 1);
						currentIndex = rightChild;
					}
				}
				
								
			}
			else if (rightChild == -1)
			{
				if (heap.get(leftChild) >= heap.get(currentIndex))
					break;
				else 
				{
					int temp = heap.get(leftChild);
					heap.add(leftChild, heap.get(currentIndex));
					heap.remove(leftChild + 1);
					heap.add(currentIndex, temp);
					heap.remove(currentIndex + 1);
				}
				
			}
			else if(leftChild == -1)
			{
				System.out.println("ERROR: Can't possible to have right child but no left child Voilating STRUCTURAL PROPERTY");
			}
			
			
		}
	}
	
	
	public void insertElement(int e)
	{
		heap.add(e);
		int parentIndex;
		int currentIndex = heap.size() - 1;
		
		while (true)
		{
			parentIndex = parent(currentIndex + 1) - 1;
			
			if (parentIndex == -1)
			{
				break;
			}
			else
			{
				if (heap.get(parentIndex) > heap.get(currentIndex))
				{
					int temp = heap.get(parentIndex);
					heap.add(parentIndex, heap.get(currentIndex));
					heap.remove(parentIndex + 1);
					heap.add(currentIndex, temp);
					heap.remove(currentIndex + 1); 
				}
				currentIndex = parentIndex;
			}
		}
	}
	
	
	public int deleteMin()
	{
		int temp = heap.remove(heap.size() - 1);
		int min = heap.remove(0);
		heap.add(0, temp);
		display();
		heapify(1);
		return min;
	}
	
	
	public void heapSort()
	{
		int heapSize = heap.size();
		for (int i = 1; i < heapSize; i++)
		{
			int temp = heap.remove(heapSize - i);
			int min = heap.remove(0);
			heap.add(0, temp);
			heap.add(heapSize - i, min);
			size = heapSize - i;
			heapify(1);
		}
		size = heapSize;
	}
	
	
	public void display()
	{
		int h = 1;
		System.out.println(heap.get(0));
		for (int i = 1; i < heap.size(); i++)
		{
			if(i == (2<<h)-1)
			{
				System.out.println();
				System.out.print(heap.get(i) + " ");
				h++;
			}
			else
			{
				System.out.print(heap.get(i) + " ");
			}
			
		}
		System.out.println();
	}
	
	
	public static void main(String[] args)
	{
		
		int[] a = {8,7,25,8,13,46,3,12,11,17,19,36};
		
		MyHeapImpl heap1 = new MyHeapImpl(a);
		heap1.display();
		
		//BUILD A HEAP
		System.out.println("BUILD A HEAP : ");
		heap1.heapBuild();
		heap1.display();
		System.out.println("Min: "+ heap1.findMin());
		System.out.println(heap1.heap.size());
		
		//INSERT AN ELEMENT IN HEAP
		System.out.println("INSERT : ");
		heap1.insertElement(2);
		heap1.display();
		System.out.println("Min: "+ heap1.findMin());
		System.out.println(heap1.heap.size());
		
		//DELETE MINIMUM VALUE FROM HEAP
		System.out.println("DELETE : ");
		System.out.println("Delete Min: "+ heap1.deleteMin());
		heap1.display();
		System.out.println(heap1.heap.size());
		
		//Heap Sort
		System.out.println("HEAP SORT : ");
		heap1.heapSort();
		heap1.display();
		System.out.println(heap1.heap.size());
		
		//BUILD A HEAP
		System.out.println("BUILD A HEAP : ");
		heap1.heapBuild();
		heap1.display();
		System.out.println("Min: "+ heap1.findMin());
		System.out.println(heap1.heap.size());
	}
}
