package eightQueens;

public class Queen {
	public int i;
	public int j;

	public Queen(int i, int j) {
		this.i = i;
		this.j = j;
	}

	public boolean equals(Object b) {
		Queen b_Queen = (Queen) b;
		Queen a = this;
		return a.i == b_Queen.i || a.j == b_Queen.j
				|| a.i - a.j == b_Queen.i - b_Queen.j
				|| a.i + a.j == b_Queen.i + b_Queen.j;
	}
}