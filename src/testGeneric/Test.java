package testGeneric;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

import ticToc.TicToc;
import binarySearchTree.AvlTree;

public class Test {

	public static void main(String[] args) throws IOException {
		Random random = new Random();
		int rand = 0;
		int min;
		int count = 0;
		java.io.File file = new java.io.File("a.txt");
		file.createNewFile();
		BufferedWriter bw = new BufferedWriter(new FileWriter(file));
		try {
			TicToc ticToc = new TicToc();
			AvlTree<Integer> tree = new AvlTree<Integer>();
			int iMax = 1000;
			for (int j = 1; j <= 4; ++j) {
				count = 0;
				ticToc.tic();
				for (int i = 1; i <= iMax; ++i) {
					rand = random.nextInt();
					if (!tree.contains(rand)) {
						tree.insert(rand);
						count++;
					}
				}
				tree.printTree(bw);
				for (int i = 1; i <= count; ++i) {
					min = tree.findMin();
					// System.out.println(min);
					tree.remove(min);
				}
				bw.write(ticToc.toc() + "ms elapsed\r\n");
				iMax *= 10;
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		bw.close();
	}
}
