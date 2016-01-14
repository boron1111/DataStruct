package sortMethods;

public class MySort {
	public static <AnyType extends Comparable<? super AnyType>> void insertionSort(
			AnyType[] a) {
		int j;

		for (int p = 1; p < a.length; p++) {
			AnyType tmp = a[p];
			for (j = p; j > 0 && tmp.compareTo(a[j - 1]) < 0; j--)
				a[j] = a[j - 1];
			a[j] = tmp;
		}
	}

	public static <AnyType extends Comparable<? super AnyType>> void selectionSort(
			AnyType[] a) {
		for (int i = 0; i < a.length; i++) {
			int minIndex = i;
			for (int j = i + 1; j < a.length; j++) {
				if (a[j].compareTo(a[minIndex]) < 0)
					minIndex = j;
			}
			AnyType tmp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = tmp;
		}
	}

	public static <AnyType extends Comparable<? super AnyType>> void bubbleSort(
			AnyType[] a) {
		AnyType temp;
		for (int i = a.length - 1; i > 0; --i) {
			for (int j = 0; j < i; ++j) {
				if (a[j + 1].compareTo(a[j]) < 0) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}

	public static <AnyType extends Comparable<? super AnyType>> void shellSort(
			AnyType[] a) {
		int j;
		for (int gap = a.length / 2; gap > 0; gap /= 2)
			for (int i = gap; i < a.length; i++) {
				AnyType tmp = a[i];
				for (j = i; j >= gap && tmp.compareTo(a[j - gap]) < 0; j -= gap)
					a[j] = a[j - gap];
				a[j] = tmp;
			}
	}

	/**
	 * Internal method for heapsort.
	 * 
	 * @i the index of an item in the heap.
	 * @return the index of the left child.
	 */
	private static int leftChild(int i) {
		return 2 * i + 1;
	}

	/**
	 * Internal method for heapsort that is used in deleteMax and buildHeap.
	 * 
	 * @param a
	 *            an array of Comparable items.
	 * @int i the position from which to percolate down.
	 * @int n the logical size of the binary heap.
	 */
	private static <AnyType extends Comparable<? super AnyType>> void percDown(
			AnyType[] a, int i, int n) {
		int child;
		AnyType tmp;

		for (tmp = a[i]; leftChild(i) < n; i = child) {
			child = leftChild(i);
			if (child != n - 1 && a[child].compareTo(a[child + 1]) < 0)
				child++;
			if (tmp.compareTo(a[child]) < 0)
				a[i] = a[child];
			else
				break;
		}
		a[i] = tmp;
	}

	/**
	 * Standart heapsort.
	 * 
	 * @param a
	 *            an array of Comparable items.
	 */
	public static <AnyType extends Comparable<? super AnyType>> void heapSort(
			AnyType[] a) {
		for (int i = a.length / 2; i >= 0; i--)
			// buildHeap
			percDown(a, i, a.length);
		for (int i = a.length - 1; i > 0; i--) {
			// deleteMax
			AnyType tmp = a[0];
			a[0] = a[i];
			a[i] = tmp;
			percDown(a, 0, i);
		}
	}

	/**
	 * Indternal method that makes recursive calls.
	 * 
	 * @param a
	 *            an array of Comparable items.
	 * @param tmpArray
	 *            an array to place the merged result.
	 * @param left
	 *            the left-most index of the subarray.
	 * @param right
	 *            the right-most index of the subarray.
	 */
	private static <AnyType extends Comparable<? super AnyType>> void mergeSort(
			AnyType[] a, AnyType[] tmpArray, int left, int right) {
		if (left < right) {
			int center = (left + right) / 2;
			// System.out.println(center);
			mergeSort(a, tmpArray, left, center);
			mergeSort(a, tmpArray, center + 1, right);
			merge(a, tmpArray, left, center + 1, right);
		}
	}

	/**
	 * Internal method that merges two sorted halves of a subarray.
	 */
	private static <AnyType extends Comparable<? super AnyType>> void merge(
			AnyType[] a, AnyType[] tmpArray, int leftPos, int rightPos,
			int rightEnd) {
		int leftEnd = rightPos - 1;
		int tmpPos = leftPos;
		int numElements = rightEnd - leftPos + 1;

		// Main loop
		while (leftPos <= leftEnd && rightPos <= rightEnd)
			if (a[leftPos].compareTo(a[rightPos]) <= 0)
				tmpArray[tmpPos++] = a[leftPos++];
			else
				tmpArray[tmpPos++] = a[rightPos++];

		while (leftPos <= leftEnd)
			// Copy rest of first half
			tmpArray[tmpPos++] = a[leftPos++];
		while (rightPos <= rightEnd)
			// Copy rest of right half
			tmpArray[tmpPos++] = a[rightPos++];

		// Copy tmpArray back

		for (int i = 0; i < numElements; i++) {
			a[rightEnd] = tmpArray[rightEnd];
			rightEnd--;
		}
	}

	/**
	 * Mergesort algorithm.
	 * 
	 * @param a
	 *            an array of Comparable items.
	 */
	public static <AnyType extends Comparable<? super AnyType>> void mergeSort(
			AnyType[] a) {
		AnyType[] tmpArray = (AnyType[]) new Comparable[a.length];
		mergeSort(a, tmpArray, 0, a.length - 1);
	}

	/**
	 * Quicksort algorithm.
	 * 
	 * @param a
	 *            an array of Comparable items.
	 */
	public static <T extends Comparable<? super T>> void quickSort(T[] a) {
		quickSort(a, 0, a.length - 1);
	}

	/**
	 * Return median of left,center,and right. Order these and hid the pivot.
	 */
	private static <T extends Comparable<? super T>> T median3(T[] a, int left,
			int right) {
		int center = (left + right) / 2;
		if (a[center].compareTo(a[left]) < 0)
			swapReferences(a, left, center);
		if (a[right].compareTo(a[left]) < 0)
			swapReferences(a, left, right);
		if (a[right].compareTo(a[center]) < 0)
			swapReferences(a, center, right);

		// Place pivot at position right-1
		swapReferences(a, center, right - 1);
		// System.out.println(center);
		return a[right - 1];
	}

	private static <T extends Comparable<? super T>> void swapReferences(T[] a,
			int b, int c) {
		T tmp = a[b];
		a[b] = a[c];
		a[c] = tmp;
	}

	/**
	 * Internal quick sort method that makes recursive calls. Uses
	 * median-of-three partitioning and a cutoff of 10.
	 * 
	 * @param a
	 *            an array of Comparable items.
	 * @param left
	 *            the left-most index of the subarray.
	 * @param right
	 *            the right-most index of the subarray.
	 */
	private static <AnyType extends Comparable<? super AnyType>> void quickSort(
			AnyType[] a, int left, int right) {
		if (left + 10 <= right) {
			AnyType pivot = median3(a, left, right);

			// Begin partitioning
			int i = left + 1, j = right;
			for (;;) {
				while (a[i].compareTo(pivot) < 0)
					i++;
				while (a[j].compareTo(pivot) > 0)
					j--;
				if (i < j)
					swapReferences(a, i, j);
				else
					break;
			}
			swapReferences(a, i, right - 1); // Restore pivot

			quickSort(a, left, i - 1);
			quickSort(a, i + 1, right);
		} else {
			insertionSort(a);
		}
	}
}