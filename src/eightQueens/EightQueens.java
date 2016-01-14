package eightQueens;

import ticToc.TicToc;

public class EightQueens {

	private int count = 0;

	public static void main(String[] args) {
		TicToc ticToc = new TicToc();

		for (int i = 2; i < 100; i++) {
			ticToc.tic();
			System.out.print(Integer.toString(i) + ' ');
			System.out.println(new EightQueens().nQueens(i));
			ticToc.toc();
		}
	}

	public int nQueens(int n) {
		int[] board = new int[n * n];
		for (int i = 0; i < board.length; i++)
			board[i] = 0;
		count = 0;
		nQueens(1, n, board);
		return count;
	}

	private void nQueens(int m, int n, int[] board) {
		if (m > n) {
			count++;
			printBoard(board);
			return;
		}

		int[] board1 = new int[n * n];

		for (int i = 0; i < n; i++) {
			for (int id = 0; id < board1.length; id++)
				board1[id] = board[id];
			if (board1[i + (m - 1) * n] == 0) {
				putQueen(n, i + (m - 1) * n, board1);
				nQueens(m + 1, n, board1);
			}
		}
	}

	private void putQueen(int n, int pos, int[] board) {
		int row = pos / n;
		int column = pos % n;

		for (int i = n * row + 1; i < n * (row + 1); i++)
			board[i] = -1;

		for (int i = column + n; i < column + n * n; i += n)
			board[i] = -1;

		int pos1 = pos;
		int row1 = row;
		int column1 = column;
		while (row1 > 0 && column1 > 0) {
			row1--;
			column1--;
			pos1 -= n + 1;
			board[pos1] = -1;
		}

		pos1 = pos;
		row1 = row;
		column1 = column;
		while (row1 > 0 && column1 < n - 1) {
			row1--;
			column1++;
			pos1 -= n - 1;
			board[pos1] = -1;
		}

		pos1 = pos;
		row1 = row;
		column1 = column;
		while (row1 < n - 1 && column1 > 0) {
			row1++;
			column1--;
			pos1 += n - 1;
			board[pos1] = -1;
		}

		pos1 = pos;
		row1 = row;
		column1 = column;
		while (row1 < n - 1 && column1 < n - 1) {
			row1++;
			column1++;
			pos1 += n + 1;
			board[pos1] = -1;
		}

		board[pos] = 1;
	}

	private void printBoard(int[] board) {

	}
}
