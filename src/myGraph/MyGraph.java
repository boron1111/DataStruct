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
	 *            结点的编号
	 * @param adjacents
	 *            邻接以及权重，同weigths
	 * @param inDegree
	 *            入度
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

	// // 无权最短路径，O(N2)
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

	// //使用队列的一个不太好的算法，使用了currDist的循环，在currDist适当时才出队
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

	// 使用队列，第一个元素出队后再把dist加1的元素入队，
	// 这样已经可以保证队里按dist较小的出完之后再出dist+1的了
	public void unweighted(int s) {
		Queue<Integer> q = new LinkedList<Integer>();
		for (Vertex v : adjacencyList.values())
			v.dist = MyGraph.INFINITY;

		adjacencyList.get(s).dist = 0;
		q.offer(s);

		while (!q.isEmpty()) {
			int currID = q.poll();
			// weigths.keySet是邻接结点的id的集合
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
	 * 与Dijkstra算法类似，只是算过dist的不再标记为know， 而是再入队。 再来一轮看dist会不会更小，直到不再更小，队为空
	 * 在无负权边的情况下，用Dijkstra算法可以保证， 计算过dist的结点不会再被更新为更小的dist。
	 * 或者说，第次找出的最小不会在更新邻接点后出现更小的。 而负边的存在打破了这种情况
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
	 * prim计算最小生成树，这里的dist是距上个结点的dist
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
	 * 使用Kruskal算法计算最小生成树
	 */
	public ArrayList<Edge> Kruskal() {
		DisjSets vertexDisjSets = new DisjSets(adjacencyList.size());
		ArrayList<Edge> edges = getEdges();
		ArrayList<Edge> edgesAccepted = new ArrayList<Edge>();
		for (int i = 0; i < edges.size(); i++) {
			// 存放v1和v2在不相交集类中的位置
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
	 * 建立邻接表调用的函数
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
	 * 建立邻接表调用的函数
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
	 * 分配深度优先遍历的编号
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
	 * 将先序遍历和后序遍历联合起来
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
	// id是本结点编号,从1开始
	public int id;
	// 此HashMap存放相连的结点，Integer是结点编号，Float是权值。
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