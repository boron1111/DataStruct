package myGraph;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

import disjSets.DisjSets;

public class MyGraph {

	// Integer is ID of Vertex, Vertex is the Vertex
	private HashMap<Integer, Vertex> adjacencyList;
	public static int INFINITY = 1000;

	public MyGraph() {
		adjacencyList = new HashMap<Integer, Vertex>();
	}

	/**
	 * @param id
	 *            ���ı��
	 * @param adjacents
	 *            �ڽ��Լ�Ȩ�أ�ͬweigths
	 * @param inDegree
	 *            ���
	 */
	public void addVertex(int id, HashMap<Integer, Float> adjacents,
			int inDegree) {
		adjacencyList.put(id, new Vertex(id, adjacents, inDegree));
	}

	// private Vertex findNewVertexOfIndegreeZero() {
	// for (Map.Entry<Integer, Vertex> entry : adjacencyList.entrySet()) {
	// if (entry.getValue().inDegree == 0 && entry.getValue().topNum == -1)
	// return entry.getValue();
	// }
	// return null;
	// }

	// //with O(V2)
	// public void topSort() throws Exception {
	// for (int counter = 0; counter < adjacencyList.size(); counter++) {
	// Vertex v = findNewVertexOfIndegreeZero();
	// if (v == null)
	// throw new Exception();
	// v.topNum = counter;
	// for (Map.Entry<Integer, Float> entry : v.weigths.entrySet()) {
	// adjacencyList.get(entry.getKey()).inDegree--;
	// }
	// }
	// }

	// with O(E+V)
	public void topSort() throws CyclicFoundException {
		Queue<Vertex> q = new LinkedList<Vertex>();
		int counter = 0;
		Vertex tmp;
		for (Map.Entry<Integer, Vertex> entry : adjacencyList.entrySet())
			if ((tmp = entry.getValue()).inDegree == 0)
				q.offer(tmp);
		while (!q.isEmpty()) {
			Vertex v = q.poll();
			v.topNum = counter++;
			for (Map.Entry<Integer, Float> entry : v.weigths.entrySet()) {
				if (--(tmp = adjacencyList.get(entry.getKey())).inDegree == 0)
					q.offer(tmp);
			}
		}
		if (counter != adjacencyList.size())
			throw new CyclicFoundException();
	}

	// // ��Ȩ���·����O(N2)
	// public void unweighted1(int s) {
	// for (Vertex v : adjacencyList.values()) {
	// v.dist = MyGraph.INFINITY;
	// v.known = false;
	// }
	//
	// adjacencyList.get(s).dist = 0;
	//
	// for (int currDist = 0; currDist < adjacencyList.size(); currDist++)
	// for (Vertex v : adjacencyList.values())
	// if (!v.known && v.dist == currDist) {
	// v.known = true;
	// for (Integer adjacentID : v.weigths.keySet()) {
	// Vertex adjacent = adjacencyList.get(adjacentID);
	// if (adjacent.dist == MyGraph.INFINITY) {
	// adjacent.dist = currDist + 1;
	// adjacent.path = v.id;
	// }
	// }
	// }
	// }

	// //ʹ�ö��е�һ����̫�õ��㷨��ʹ����currDist��ѭ������currDist�ʵ�ʱ�ų���
	// public void unweighted(int s) {
	// Queue<Integer> q = new LinkedList<Integer>();
	// for (Vertex v : adjacencyList.values()) {
	// v.dist = MyGraph.INFINITY;
	// v.known = false;
	// }
	// adjacencyList.get(s).dist = 0;
	// q.offer(s);
	// adjacencyList.get(s).known = true;
	// for (int currDist = 0; currDist < adjacencyList.size(); currDist++) {
	// Vertex v;
	// while (!q.isEmpty()
	// && (v = adjacencyList.get(q.peek())).dist == currDist) {
	// q.poll();
	// for (Integer adjacentID : v.weigths.keySet()) {
	// if (!adjacencyList.get(adjacentID).known) {
	// adjacencyList.get(adjacentID).dist = currDist + 1;
	// adjacencyList.get(adjacentID).path = v.id;
	// adjacencyList.get(adjacentID).known = true;
	// q.offer(adjacentID);
	// }
	// }
	// }
	// }
	// }

	// ʹ�ö��У���һ��Ԫ�س��Ӻ��ٰ�dist��1��Ԫ����ӣ�
	// �����Ѿ����Ա�֤���ﰴdist��С�ĳ���֮���ٳ�dist+1����
	public void unweighted(int s) {
		Queue<Integer> q = new LinkedList<Integer>();
		for (Vertex v : adjacencyList.values())
			v.dist = MyGraph.INFINITY;

		adjacencyList.get(s).dist = 0;
		q.offer(s);

		while (!q.isEmpty()) {
			int currID = q.poll();
			// weigths.keySet���ڽӽ���id�ļ���
			for (int i : adjacencyList.get(currID).weigths.keySet()) {
				Vertex adjacentV;
				if ((adjacentV = adjacencyList.get(i)).dist == MyGraph.INFINITY) {
					adjacentV.dist = adjacencyList.get(currID).dist + 1;
					adjacentV.path = currID;
					q.offer(adjacentV.id);
				}
			}
		}
	}

	// used in dijkstra and prim
	private Vertex findSmallestDistanceVertex() {
		Vertex tmp = null;
		for (Vertex v : adjacencyList.values()) {
			if (v.known == false) {
				if (tmp == null)
					tmp = v;
				if (v.dist < tmp.dist)
					tmp = v;
			}
		}
		return tmp;
	}

	public void dijkstra(int s) {
		for (Vertex v : adjacencyList.values()) {
			v.dist = MyGraph.INFINITY;
			v.known = false;
		}

		adjacencyList.get(s).dist = 0;

		for (;;) {
			Vertex v = findSmallestDistanceVertex();
			if (v == null)
				break;
			v.known = true;

			for (Integer adjacentID : v.weigths.keySet()) {
				Vertex adjacentV = adjacencyList.get(adjacentID);
				if (!adjacentV.known)
					if (v.dist + v.weigths.get(adjacentID) < adjacentV.dist) {
						adjacentV.dist = v.dist + v.weigths.get(adjacentID);
						adjacentV.path = v.id;
					}
			}
		}
	}

	/*
	 * ��Dijkstra�㷨���ƣ�ֻ�����dist�Ĳ��ٱ��Ϊknow�� ��������ӡ� ����һ�ֿ�dist�᲻���С��ֱ�����ٸ�С����Ϊ��
	 * ���޸�Ȩ�ߵ�����£���Dijkstra�㷨���Ա�֤�� �����dist�Ľ�㲻���ٱ�����Ϊ��С��dist��
	 * ����˵���ڴ��ҳ�����С�����ڸ����ڽӵ����ָ�С�ġ� �����ߵĴ��ڴ������������
	 */
	public void weightedNegative(int s) {
		Queue<Integer> q = new LinkedList<Integer>();
		for (Vertex v : adjacencyList.values()) {
			v.dist = MyGraph.INFINITY;
		}

		adjacencyList.get(s).dist = 0;
		q.offer(s);

		while (!q.isEmpty()) {
			int id = q.poll();
			Vertex v = adjacencyList.get(id);
			for (int adjacentID : adjacencyList.get(id).weigths.keySet()) {
				Vertex adjacentV = adjacencyList.get(adjacentID);
				if (v.dist + v.weigths.get(adjacentID) < adjacentV.dist) {
					adjacentV.dist = v.dist + v.weigths.get(adjacentID);
					adjacentV.path = v.id;

					if (!q.contains(adjacentID))
						q.offer(adjacentID);
				}
			}
		}
	}

	/**
	 * prim������С�������������dist�Ǿ��ϸ�����dist
	 */
	public void prim() {
		for (Vertex v : adjacencyList.values()) {
			v.dist = MyGraph.INFINITY;
			v.known = false;
		}

		adjacencyList.get(1).dist = 0;

		for (;;) {
			Vertex v = findSmallestDistanceVertex();
			if (v == null)
				break;
			v.known = true;
			for (int adjacentID : v.weigths.keySet()) {
				Vertex adjacentV = adjacencyList.get(adjacentID);
				if (!adjacentV.known)
					if (v.weigths.get(adjacentID) < adjacentV.dist) {
						adjacentV.dist = v.weigths.get(adjacentID);
						adjacentV.path = v.id;
					}
			}
		}
	}

	/**
	 * ʹ��Kruskal�㷨������С������
	 */
	public ArrayList<Edge> Kruskal() {
		DisjSets vertexDisjSets = new DisjSets(adjacencyList.size());
		ArrayList<Edge> edges = getEdges();
		ArrayList<Edge> edgesAccepted = new ArrayList<Edge>();
		for (int i = 0; i < edges.size(); i++) {
			// ���v1��v2�ڲ��ཻ�����е�λ��
			int root1, root2;
			if ((root1 = vertexDisjSets
					.find(vertexToDisjID(edges.get(i).vertexes[0]))) != (root2 = vertexDisjSets
					.find(vertexToDisjID(edges.get(i).vertexes[1])))) {
				vertexDisjSets.union(root1, root2);
				edgesAccepted.add(edges.get(i));
				if (edgesAccepted.size() == adjacencyList.size() - 1)
					break;
			}
		}
		return edgesAccepted;
	}

	private int vertexToDisjID(Vertex v) {
		return v.id - 1;
	}

	// private Vertex disjIDToVertex(int id) {
	// return adjacencyList.get(id + 1);
	// }

	/**
	 * find the edges from the adjacent list
	 */
	public ArrayList<Edge> getEdges() {
		ArrayList<Edge> edges = new ArrayList<Edge>();
		for (Vertex v : adjacencyList.values()) {
			for (int adjacentID : v.weigths.keySet()) {
				Edge edge = new Edge(v, adjacencyList.get(adjacentID),
						v.weigths.get(adjacentID));
				if (!edges.contains(edge))
					edges.add(edge);
			}
		}
		edges.sort(new Edge.compareEdge());
		return edges;
	}

	/**
	 * �����ڽӱ���õĺ���
	 */
	public static HashMap<Integer, Float> createHashMap(int[] ids,
			float[] weigths) {
		HashMap<Integer, Float> HashMap = new HashMap<Integer, Float>();
		if (!(ids == null))
			for (int i = 0; i < ids.length; i++) {
				HashMap.put(ids[i], weigths[i]);
			}
		return HashMap;
	}

	/**
	 * �����ڽӱ���õĺ���
	 */
	public static HashMap<Integer, Float> createHashMap(int[] ids) {
		if (ids == null)
			return createHashMap(null, null);
		else {
			float[] weigths = new float[ids.length];
			for (int i = 0; i < weigths.length; i++)
				weigths[i] = 1;
			return createHashMap(ids, weigths);
		}
	}

	public Vertex getVertex(int id) {
		return adjacencyList.get(id);
	}

	/**
	 * ����������ȱ����ı��
	 */
	public void assignNum(int id) {
		for (Vertex v : adjacencyList.values()) {
			v.num = 0;
		}
		assignNum(id, 1);
	}

	private int assignNum(int id, int count) {
		adjacencyList.get(id).num = count++;
		for (int ida : adjacencyList.get(id).weigths.keySet()) {
			if (adjacencyList.get(ida).num == 0) {
				adjacencyList.get(ida).parent = id;
				count = assignNum(ida, count);
			}
		}
		return count;
	}

	/**
	 * Assign low also check for articulation points.
	 */
	private void assignLow1(int id) {
		Vertex v = adjacencyList.get(id); // Rule 1
		v.low = v.num;
		for (int ida : v.weigths.keySet()) {
			Vertex va = adjacencyList.get(ida);
			if (va.num > v.num) { // Forward edge
				assignLow1(ida);
				if (va.low >= v.num)
					v.articulation = true;
				v.low = v.low < va.low ? v.low : va.low; // Rule 3
			} else {
				if (v.parent != ida) // Backward edge
					v.low = v.low < va.num ? v.low : va.num; // Rule 2
			}
		}
	}

	public void assignLow(int id) {
		assignLow1(id);
		int checkRootCount = 0;
		for (int i = 1; i < adjacencyList.size() + 1; i++) {
			if (adjacencyList.get(i).parent == id)
				checkRootCount++;
		}
		if (checkRootCount < 2)
			adjacencyList.get(id).articulation = false;
	}

	public void findArt() {
		for (Vertex v : adjacencyList.values()) {
			v.num = 0;
		}

		int id = 1;
		findArt(id, 1);

		int checkRootCount = 0;
		for (int i = 1; i < adjacencyList.size() + 1; i++) {
			if (adjacencyList.get(i).parent == id)
				checkRootCount++;
		}
		if (checkRootCount < 2)
			adjacencyList.get(id).articulation = false;
	}

	/*
	 * ����������ͺ��������������
	 */
	private int findArt(int id, int count) {
		Vertex v = adjacencyList.get(id);
		v.low = v.num = count++;

		for (int ida : v.weigths.keySet()) {
			Vertex va = adjacencyList.get(ida);
			if (va.num == 0) {
				va.parent = id;
				count = findArt(ida, count);
				if (va.low >= v.num)
					v.articulation = true;
				v.low = v.low < va.low ? v.low : va.low;
			} else {
				if (v.parent != ida)
					v.low = v.low < va.num ? v.low : va.num;
			}
		}
		return count;
	}
}

class Vertex {
	// id�Ǳ������,��1��ʼ
	public int id;
	// ��HashMap��������Ľ�㣬Integer�ǽ���ţ�Float��Ȩֵ��
	public HashMap<Integer, Float> weigths;
	public int inDegree;
	public int topNum = -1;
	public float dist = MyGraph.INFINITY;
	public boolean known = false;
	public int path = 0;
	public int num, low;
	public int parent;
	public boolean articulation = false;

	public Vertex(int id) {
		this.id = id;
		weigths = new HashMap<Integer, Float>();
	}

	public Vertex(int id, HashMap<Integer, Float> weigths) {
		this.id = id;
		this.weigths = weigths;
	}

	public Vertex(int id, HashMap<Integer, Float> weigths, int inDegree) {
		this(id, weigths);
		this.inDegree = inDegree;
	}

	/**
	 * Used for adding adjacent outside
	 * 
	 * @param a
	 * @param weight
	 */
	public void addAdjacent(Integer a, float weight) {
		weigths.put(a, weight);
	}

}

class Edge implements Comparable<Edge> {
	public Vertex[] vertexes = new Vertex[2];
	public float weight;

	public Edge(Vertex a, Vertex b, float weight) {
		if (a.id < b.id) {
			vertexes[0] = a;
			vertexes[1] = b;
		} else {
			vertexes[0] = b;
			vertexes[1] = a;
		}
		this.weight = weight;
	}

	@Override
	public int compareTo(Edge o) {
		return Float.compare(weight, o.weight);
	}

	public boolean equals(Object a) {
		Edge a_Edge = (Edge) a;
		return vertexes[0] == a_Edge.vertexes[0]
				&& vertexes[1] == a_Edge.vertexes[1];
	}

	static class compareEdge implements Comparator<Edge> {
		@Override
		public int compare(Edge o1, Edge o2) {
			return o1.compareTo(o2);
		}
	}
}

class CyclicFoundException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

}