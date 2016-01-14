package testGeneric;

import java.util.Comparator;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

public class Test_Compare {

	public static void main(String[] args) {
		Set<String> s = new TreeSet<String>(new CaseInsensitiveCompare());
		s.add("Hello");
		s.add("hello");
		System.out.println(s.size());
		s.add("a");
		s.add("b");

		String[] words = new String[s.size()];
		String[] words1 = new String[s.size()];
		words1 = s.toArray(words);
		for (int i = 0; i < words1.length; ++i) {
			System.out.println(words1[i].equals(words[i]));
		}

		Set<ABC> a = new TreeSet<ABC>(new ComparatorOfABC());
		a.add(new ABC(1));
		a.add(new ABC(2));
		System.out.println(a.size());

		Set<BCD> b = new TreeSet<BCD>();
		b.add(new BCD(1));
		b.add(new BCD(2));
		System.out.println(b.size());

		// Map是个接口
		Map<Integer, String> map = new TreeMap<Integer, String>();
		map.put(1, "a");
		map.put(2, "b");
		for (Map.Entry<Integer, String> entry : map.entrySet()) {
			System.out.println(entry.getValue());
		}
	}
}

class CaseInsensitiveCompare implements Comparator<String> {
	public int compare(String lhs, String rhs) {
		return lhs.compareToIgnoreCase(rhs);
	}
}

class ABC {
	int a;

	public ABC(int a) {
		this.a = a;
	}
}

class ComparatorOfABC implements Comparator<ABC> {

	public int compare(ABC o1, ABC o2) {
		return Integer.compare(o1.a, o2.a);
	}

}

class BCD extends ABC implements Comparable<BCD> {

	public BCD(int a) {
		super(a);
	}

	@Override
	public int compareTo(BCD o) {
		return Integer.compare(a, o.a);
	}

}