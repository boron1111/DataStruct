package testGeneric;

import java.util.Random;

import binarySearchTree.AvlTree;

public class Test1 {

	public static void main(String[] args) {
		Random random = new Random();
		AvlTree<Integer> tree = new AvlTree<Integer>();
		int rand;
		int min;
		int count = 0;
		for (int i = 1; i <= 20; ++i) {
			rand = random.nextInt();
			if (!tree.contains(rand)) {
				tree.insert(rand);
				count++;
			}
		}
		for (int i = 1; i <= count; ++i) {
			try {
				min = tree.findMin();
				tree.remove(min);
				System.out.println(min);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		tree.printTree();
	}

}
