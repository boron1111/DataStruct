package myGraph;

import java.util.ArrayList;

public class TestArrayList {

	public static void main(String[] args) {
		ArrayList<Integer> al = new ArrayList<Integer>();
		al.add(1);
		al.add(2);
		al.add(3);
		System.out.println(getElement(al, 4));
	}

	private static Integer getElement(ArrayList<Integer> al, Integer a) {
		for (int i = 0; i < al.size(); i++) {
			if (al.get(i) == a)
				return al.get(i);
		}
		return null;
	}
}
