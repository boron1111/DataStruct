package binaryHeap;

public class BinaryHeap<AnyType extends Comparable<? super AnyType>> {
	public BinaryHeap() {
		this(DEFAULT_CAPACITY);
	}

	public BinaryHeap(int capacity) {
		if (capacity > DEFAULT_CAPACITY)
			array = (AnyType[]) new Comparable[capacity + 1];
		else {
			array = (AnyType[]) new Comparable[DEFAULT_CAPACITY + 1];
		}
		currentSize = 0;
	}

	public BinaryHeap(AnyType[] items) {
		this(items.length);
		for (int i = 0; i < items.length; i++)
			this.insert(items[i]);
	}

	/**
	 * Insert into the priority queue, maintaining heap order. Duplicate are
	 * allowed.
	 * 
	 * @param x
	 *            the item to insert.
	 */
	public void insert(AnyType x) {
		if (currentSize == array.length - 1)
			enlargeArray(array.length * 2 + 1);

		// Percolate up
		int hole = ++currentSize;
		for (; hole > 1 && x.compareTo(array[hole / 2]) < 0; hole /= 2)
			array[hole] = array[hole / 2];
		array[hole] = x;
	}

	public AnyType findMin() {
		if (!isEmpty())
			return array[1];
		else {
			return null;
		}
	}

	/**
	 * Remove the smallest item from the priority queue.
	 * 
	 * @return the smallest item, or throw UnderflowException, if empty.
	 */
	public AnyType deleteMin() {
		if (isEmpty())
			throw new ArrayIndexOutOfBoundsException();
		AnyType minItem = findMin();
		array[1] = array[currentSize--];
		percolateDown(1);

		return minItem;
	}

	public boolean isEmpty() {
		return currentSize == 0;
	}

	public void makeEmpty() {
		currentSize = 0;
		array = (AnyType[]) new Object[DEFAULT_CAPACITY + 1];
	}

	private static final int DEFAULT_CAPACITY = 10;

	private int currentSize;
	private AnyType[] array;

	/**
	 * Internal method to percolate down in the heap.
	 * 
	 * @param hole
	 *            the index at which the percolate begins.
	 */
	private void percolateDown(int hole) {
		int child;
		AnyType tmp = array[hole];

		for (; hole * 2 <= currentSize; hole = child) {
			child = hole * 2;
			if (child != currentSize
					&& array[child + 1].compareTo(array[child]) < 0)
				child++;
			if (array[child].compareTo(tmp) < 0)
				array[hole] = array[child];
			else {
				break;
			}
			array[child] = tmp;
		}
	}

	private void enlargeArray(int newSize) {
		AnyType[] old = array;
		array = (AnyType[]) new Comparable[newSize];
		for (int i = 0; i < old.length; i++)
			array[i] = old[i];
	}
}
