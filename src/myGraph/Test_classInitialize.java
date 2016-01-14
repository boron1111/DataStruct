package myGraph;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;

public class Test_classInitialize {
	public static void main(String[] args) {
		// ABC abc = createABC(1);
		// System.out.println(abc.a);
		// int[] a = { 1, 2 };
		// float[] b = { 2f, 3f };
		// HashMap<Integer, Float> hashMap = createHashMap(a, b);
		// System.out.println(hashMap.get(1));

		// 两个HashSet可以相等，但包含相等HashSet的类的实例不相等
		// contains方法调用equals(Object)方法
		// sort方法要调用一个comparator的实例
		// Set中的元素不能重复
		// HashSet<Integer> a = new HashSet<Integer>();
		// HashSet<Integer> b = new HashSet<Integer>();
		// a.add(1);
		// a.add(2);
		// b.add(2);
		// b.add(3);
		// ABC aa = new ABC(2, a), bb = new ABC(1, b);
		// System.out.println(aa.hashSet.equals(bb.hashSet));
		// System.out.println(aa.equals(bb));
		// System.out.println(a.contains(1));
		// LinkedList<ABC> xx = new LinkedList<ABC>();
		// xx.add(aa);
		// System.out.println(xx.contains(bb));
		// System.out.println(xx.size());
		// xx.add(bb);
		// System.out.println(xx.size());
		// TreeSet<ABC> yy = new TreeSet<ABC>();
		// yy.add(aa);
		// System.out.println(yy.contains(bb));
		// System.out.println(yy.size());
		// yy.add(bb);
		// System.out.println(yy.size());
		// xx.sort(aa.new CompareABC());
		// System.out.println(xx.get(0).a);

		// 数组不能equals,List可以
		int[] a = { 1, 2, 3 };
		int[] b = { 1, 2, 3 };
		System.out.println(a.equals(b));
		ArrayList<Integer> aa = new ArrayList<Integer>();
		aa.add(1);
		aa.add(2);
		ArrayList<Integer> bb = new ArrayList<Integer>();
		bb.add(2);
		bb.add(1);
		System.out.println(aa.equals(bb));
		bb.sort(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return o1.compareTo(o2);
			}
		});
		System.out.println(aa.equals(bb));
	}

	private static ABC createABC(int i) {
		ABC tmp = new ABC(i, null);
		return tmp;
	}

	private static HashMap<Integer, Float> createHashMap(int[] is, float[] fs) {
		HashMap<Integer, Float> tmp = new HashMap<Integer, Float>();
		for (int i = 0; i < is.length; i++)
			tmp.put(is[i], fs[i]);
		return tmp;
	}
}

class ABC implements Comparable<ABC> {
	public int a;
	public HashSet<Integer> hashSet;

	public ABC(int a, HashSet<Integer> hashSet) {
		this.a = a;
		this.hashSet = hashSet;
	}

	public boolean equals(Object a) {
		return hashSet.equals(((ABC) a).hashSet);
	}

	@Override
	public int compareTo(ABC arg0) {
		return Integer.compare(a, arg0.a);
	}

	class CompareABC implements Comparator<ABC> {

		@Override
		public int compare(ABC o1, ABC o2) {
			return o1.compareTo(o2);
		}

	}

}