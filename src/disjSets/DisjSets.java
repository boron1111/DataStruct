package disjSets;

import java.util.ArrayList;

public class DisjSets {
	public DisjSets(int numElements) {
		s = new int[numElements];
		for (int i = 0; i < s.length; i++)
			s[i] = -1;
	}

	public void union(int root1, int root2) {
		if (s[root2] < s[root1]) // root2 is deeper
			s[root1] = root2; // make root2 new root
		else {
			if (s[root1] == s[root2])
				s[root1]--; // Update height if same
			s[root2] = root1; // Make root1 new root
		}
	}

	public int find(int x) {
		if (s[x] < 0)
			return x;
		else
			return s[x] = find(s[x]); // perform a path compression
	}

	private int[] s;

	public ArrayList<Integer> findRoots() {
		ArrayList<Integer> roots = new ArrayList<Integer>();
		for (int i = 0; i < s.length; i++)
			if (s[i] < 0)
				roots.add(i);
			else
				find(i);
		return roots;
	}

}
