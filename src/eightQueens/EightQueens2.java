package eightQueens;

import java.util.Stack;

import ticToc.TicToc;

public class EightQueens2 {

	private int count = 0;

	public static void main(String[] args) {
		TicToc ticToc = new TicToc();

		for (int i = 2; i < 100; i++) {
			ticToc.tic();
			System.out.print(Integer.toString(i) + ' ');
			System.out.println(new EightQueens2().nQueens(i));
			ticToc.toc();
		}
	}

	public int nQueens(int n) {
		count = 0;
		Stack<Queen> queens = new Stack<Queen>();
		nQueens(1, n, queens);
		return count;
	}

	private void nQueens(int m, int n, Stack<Queen> queens) {
		if (m > n) {
			count++;
			queens.pop();
			return;
		}
		for (int i = 1; i < n + 1; i++) {
			Queen queen = new Queen(i, m);
			if (!queens.contains(queen)) {
				queens.push(queen);
				nQueens(m + 1, n, queens);
			}
		}
		if (!queens.isEmpty())
			queens.pop();
	}
}
