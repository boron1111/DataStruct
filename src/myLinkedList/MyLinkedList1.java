package myLinkedList;

public class MyLinkedList1<AnyType> implements Iterable<AnyType> {
	private class Node {
		public Node(AnyType d, Node p, Node n) {
			data = d;
			prev = p;
			next = n;
		}

		public AnyType data;
		public Node prev;
		public Node next;
	}

	public MyLinkedList1() {
		clear();
	}

	public void clear() {
		beginMarker = new Node(null, null, null);
		endMarker = new Node(null, beginMarker, null);
		beginMarker.next = endMarker;

		theSize = 0;
		modCount++;
	}

	public int size() {
		return theSize;
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	public boolean add(AnyType x) {
		add(size(), x);
		return true;
	}

	public void add(int idx, AnyType x) {
		addBefore(getNode(idx), x);
	}

	public AnyType get(int idx) {
		return getNode(idx).data;
	}

	public AnyType set(int idx, AnyType newVal) {
		Node p = getNode(idx);
		AnyType oldVal = p.data;
		p.data = newVal;
		return oldVal;
	}

	public AnyType remove(int idx) {
		return remove(getNode(idx));
	}

	private void addBefore(Node p, AnyType x) {
		Node newNode = new Node(x, p.prev, p);
		newNode.prev.next = newNode;
		p.prev = newNode;
		theSize++;
		modCount++;
	}

	private AnyType remove(Node p) {
		p.next.prev = p.prev;
		p.prev.next = p.next;
		theSize++;
		modCount++;
		return p.data;
	}

	private Node getNode(int idx) {
		Node p;
		if (idx < 0 || idx > size())
			throw new IndexOutOfBoundsException();
		if (idx < size() / 2) {
			p = beginMarker.next;
			for (int i = 0; i < idx; i++)
				p = p.next;
		} else {
			p = endMarker;
			for (int i = size(); i > idx; i--)
				p = p.prev;
		}
		return p;
	}

	public java.util.Iterator<AnyType> iterator() {
		return new LinkedListIterator();
	}

	private class LinkedListIterator implements java.util.Iterator<AnyType> {
		private Node current = beginMarker.next;
		private int expectedModCount = modCount;
		private boolean okToRemove = false;

		public boolean hasNext() {
			return current != endMarker;
		}

		public AnyType next() {
			if (modCount != expectedModCount)
				throw new java.util.ConcurrentModificationException();
			if (!hasNext())
				throw new java.util.NoSuchElementException();

			AnyType nextItem = current.data;
			current = current.next;
			okToRemove = true;
			return nextItem;
		}

		public void remove() {
			if (modCount != expectedModCount)
				throw new java.util.ConcurrentModificationException();
			if (!okToRemove)
				throw new IllegalStateException();

			MyLinkedList1.this.remove(current.prev);
			okToRemove = false;
			expectedModCount++;
		}

	}

	private int theSize;
	private int modCount = 0; // 改变次数的计数
	private Node beginMarker;
	private Node endMarker;
}
