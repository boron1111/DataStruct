package eightQueens;

import java.util.Stack;

import ticToc.TicToc;

public class EightQueens1 {

	private int count = 0;

	public static void main(String[] args) {
		TicToc ticToc = new TicToc();

		for (int i = 2; i < 100; i++) {
			ticToc.tic();
			System.out.print(Integer.toString(i) + ' ');
			System.out.println(new EightQueens1().nQueens(i));
			ticToc.toc();
		}
	}

	public int nQueens(int n) {
		count = 0;
		Stack<Queen> queens = new Stack<Queen>();
		int i, j;
		boolean endLine = false;

		queens.push(new Queen(1, 1));
		while (!queens.isEmpty()) {
			Queen queen1 = queens.peek();
			if (!endLine) {
				i = 1;
				j = queen1.j + 1;
			} else {
				i = queen1.i + 1;
				j = queen1.j;
				queens.pop();
				if (i == n + 1)
					continue;
			}
			do {
				endLine = false;
				Queen queen2 = new Queen(i, j);
				if (!queens.contains(queen2)) {
					queens.push(queen2);
					if (!(j == n))
						break;
					else {
						count++;
						queens.pop();
					}
				}
				i++;
			} while (i < n + 1);
			if (i == (n + 1))
				endLine = true;
		}

		return count;
	}
}
