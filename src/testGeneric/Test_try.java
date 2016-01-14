package testGeneric;

public class Test_try {

	public static void main(String[] args) {
		int[] a = new int[10];
		try {
			a[-1] = 1;
		} catch (Exception e) {
			// e.printStackTrace();
		}
		int i = 3 / 4;
		System.out.println(i);
	}
}
