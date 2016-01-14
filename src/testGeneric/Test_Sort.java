package testGeneric;

import java.util.Random;

import sortMethods.MySort;
import ticToc.TicToc;

public class Test_Sort {

	public static void main(String[] args) {
		Random random = new Random();
		int totalNum = 1000;
		Integer[] items = new Integer[totalNum];
		for (int i = 0; i < items.length; i++)
			items[i] = random.nextInt(1000000);

		Integer[] items1 = items.clone();
		Integer[] items2 = items.clone();

		TicToc ticToc = new TicToc();
		ticToc.tic();

		// BinaryHeap<Integer> myBinaryHeap = new BinaryHeap<Integer>(items);
		// while (!myBinaryHeap.isEmpty()) {
		// System.out.println(myBinaryHeap.findMin());
		// myBinaryHeap.deleteMin();

		// LeftistHeap<Integer> myLeftistHeap = new LeftistHeap<Integer>();
		// LeftistHeap<Integer> myLeftistHeap1 = new LeftistHeap<Integer>();
		// for (int i = 0; i < items.length / 2; i++)
		// myLeftistHeap.insert(items[i]);
		// for (int i = items.length / 2 + 1; i < items.length; i++)
		// myLeftistHeap1.insert(items[i]);
		// myLeftistHeap.merge(myLeftistHeap1);
		// while (!myLeftistHeap.isEmpty()) {
		// System.out.print(myLeftistHeap.findMin());
		// System.out.print(' ');
		// myLeftistHeap.deleteMin();
		// }

		ticToc.tic();
		MySort.quickSort(items);
		ticToc.toc();

		ticToc.tic();
		MySort.mergeSort(items1);
		ticToc.toc();

		ticToc.tic();
		MySort.heapSort(items2);
		ticToc.toc();

		// for (int i = 0; i < items.length; ++i)
		// System.out.println(items[i]);

	}
}
