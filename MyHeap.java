package stringalgo;

public interface MyHeap {
	
	public int parent(int childIndex);
	public int leftChild(int parentIndex);
	public int rightChild(int parentIndex);
	public void heapBuild();
	public int findMin();
	public void heapify(int heapIndex);
	public void insertElement(int e);
	public int deleteMin();
	public void heapSort();
	public void display();

}
