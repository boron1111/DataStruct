package ticToc;

public class TicToc {
	private long startTime = 0;

	public void tic() {
		startTime = System.currentTimeMillis();
	}

	public long toc() {
		if (startTime != 0) {
			System.out.println((System.currentTimeMillis() - startTime)
					+ "ms elapsed");
			return System.currentTimeMillis() - startTime;
		} else {
			System.out.println("Please tic first");
			return -1;
		}
	}
}
