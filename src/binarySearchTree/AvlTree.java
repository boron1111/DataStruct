package binarySearchTree;

import java.io.BufferedWriter;
import java.io.IOException;

public class AvlTree<AnyType extends Comparable<? super AnyType>> {

	private static class AvlNode<AnyType> {
		AvlNode(AnyType theElement, AvlNode<AnyType> lt, AvlNode<AnyType> rt) {
			element = theElement;
			left = lt;
			right = rt;
			height = 0;
		}

		AnyType element;
		AvlNode<AnyType> left;
		AvlNode<AnyType> right;
		int height;
	}

	private AvlNode<AnyType> root;

	public AvlTree() {
		root = null;
	}

	public boolean isEmpty() {
		return root == null;
	}

	public boolean contains(AnyType x) {
		return contains(x, root);
	}

	private boolean contains(AnyType x, AvlNode<AnyType> t) {
		if (t == null)
			return false;
		int compareResult = x.compareTo(t.element);
		if (compareResult < 0)
			return contains(x, t.left);
		else if (compareResult > 0)
			return contains(x, t.right);
		else
			return true;
	}

	public AnyType findMin() throws Exception {
		if (isEmpty())
			throw new Exception();
		return findMin(root).element;
	}

	public AnyType findMax() throws Exception {
		if (isEmpty())
			throw new Exception();
		return findMax(root).element;
	}

	public void insert(AnyType x) {
		root = insert(x, root);
	}

	public void remove(AnyType x) {
		root = remove(x, root);
	}

	private AvlNode<AnyType> findMin(AvlNode<AnyType> t) {
		if (t == null)
			return null;
		else if (t.left == null)
			return t;
		return findMin(t.left);
	}

	private AvlNode<AnyType> findMax(AvlNode<AnyType> t) {
		if (t != null)
			while (t.right != null)
				t = t.right;
		return t;
	}

	private AvlNode<AnyType> remove(AnyType x, AvlNode<AnyType> t) {
		if (t == null)
			return t;
		int compareResult = x.compareTo(t.element);
		if (compareResult < 0)
			t.left = remove(x, t.left);
		else if (compareResult > 0)
			t.right = remove(x, t.right);
		else if (t.left != null && t.right != null) {
			t.element = findMin(t.right).element;
			t.right = remove(t.element, t.right);
		} else
			t = (t.left != null) ? t.left : t.right;
		return t;
	}

	public void printTree() {
		if (isEmpty())
			System.out.println("Empty tree");
		else
			printTree(root);
	}

	public void printTree(BufferedWriter bw) throws IOException {
		if (isEmpty())
			bw.write("Empty tree\r\n");
		else
			printTree(root, bw);
	}

	private void printTree(AvlNode<AnyType> t) {
		if (t != null) {
			printTree(t.left);
			System.out.println(t.element);
			printTree(t.right);
		}
	}

	private void printTree(AvlNode<AnyType> t, BufferedWriter bw)
			throws IOException {
		if (t != null) {
			printTree(t.left, bw);
			bw.write(t.element + "\r\n");
			printTree(t.right, bw);
		}
	}

	private int height(AvlNode<AnyType> t) {
		return t == null ? -1 : t.height;
	}

	private AvlNode<AnyType> insert(AnyType x, AvlNode<AnyType> t) {
		if (t == null)
			return new AvlNode<AnyType>(x, null, null);

		int compareResult = x.compareTo(t.element);

		if (compareResult < 0) {
			t.left = insert(x, t.left);
			if (height(t.left) - height(t.right) == 2)
				if (x.compareTo(t.left.element) < 0)
					t = rotateWithLeftChild(t);
				else
					t = doubleWithLeftChild(t);
		} else if (compareResult > 0) {
			t.right = insert(x, t.right);
			if (height(t.right) - height(t.left) == 2)
				if (x.compareTo(t.right.element) > 0)
					t = rotateWithRightChild(t);
				else
					t = doubleWithRightChild(t);
		}
		t.height = Math.max(height(t.left), height(t.right)) + 1;
		return t;
	}

	/**
	 * Rotate binary tree node with left child. For AVL trees, this is a single
	 * rotation for case 1. Update heights, then return new root.
	 */
	private AvlNode<AnyType> rotateWithLeftChild(AvlNode<AnyType> k2) {
		AvlNode<AnyType> k1 = k2.left;
		k2.left = k1.right;
		k1.right = k2;
		k2.height = Math.max(height(k2.left), height(k2.right)) + 1;
		k1.height = Math.max(height(k1.left), k2.height) + 1;
		return k1;
	}

	private AvlNode<AnyType> rotateWithRightChild(AvlNode<AnyType> k2) {
		AvlNode<AnyType> k1 = k2.right;
		k2.right = k1.left;
		k1.left = k2;
		k2.height = Math.max(height(k2.left), height(k2.right)) + 1;
		k1.height = Math.max(height(k1.right), k2.height) + 1;
		return k1;
	}

	/**
	 * Double rotate binary tree node: first left child with its right child;
	 * then node k4 with new left child. For AVL trees, this is a bouble
	 * rotation for case 2. Update heights, then return new root.
	 */
	private AvlNode<AnyType> doubleWithLeftChild(AvlNode<AnyType> k3) {
		k3.left = rotateWithRightChild(k3.left);
		return rotateWithLeftChild(k3);
	}

	private AvlNode<AnyType> doubleWithRightChild(AvlNode<AnyType> k3) {
		k3.right = rotateWithLeftChild(k3.right);
		return rotateWithRightChild(k3);
	}
}
