package myGraph;

public class Test_MapTopSort {

	public static void main(String[] args) {
		MyGraph graph = new MyGraph();

		int[] v1 = { 2, 4 };
		float[] w1 = { 1, 1 };
		graph.addVertex(1, MyGraph.createHashMap(v1, w1), 0);

		int[] v2 = { 1, 3 };
		float[] w2 = { 1, 1 };
		graph.addVertex(2, MyGraph.createHashMap(v2, w2), 1);

		int[] v3 = { 2, 4, 7 };
		float[] w3 = { 1, 1, 1 };
		graph.addVertex(3, MyGraph.createHashMap(v3, w3), 2);

		int[] v4 = { 1, 3, 5, 6 };
		float[] w4 = { 1, 1, 1, 1 };
		graph.addVertex(4, MyGraph.createHashMap(v4, w4), 3);

		int[] v5 = { 4, 6 };
		float[] w5 = { 1, 1 };
		graph.addVertex(5, MyGraph.createHashMap(v5, w5), 1);

		int[] v6 = { 4, 5 };
		float[] w6 = { 1, 1 };
		graph.addVertex(6, MyGraph.createHashMap(v6, w6), 3);

		int[] v7 = { 3 };
		float[] w7 = { 1 };
		graph.addVertex(7, MyGraph.createHashMap(v7, w7), 2);

		// try {
		// graph.topSort();
		// } catch (CyclicFoundException e) {
		// e.printStackTrace();
		// }

		// graph.weightedNegative(1);
		// printPath(graph, 7);

		// graph.prim();
		//
		// for (int i = 1; i < 8; i++) {
		// System.out.print(i);
		// System.out.print(' ');
		// System.out.print(graph.getVertex(i).path);
		// System.out.print(' ');
		// System.out.println((int) graph.getVertex(i).dist);
		// }
		// ArrayList<Edge> edges = graph.Kruskal();
		// for (Edge e : edges) {
		// System.out.println(Integer.toString(e.vertexes[0].id) + ' '
		// + Integer.toString(e.vertexes[1].id) + ' ' + e.weight);
		// }
		// graph.assignNum(1);
		// graph.assignLow(1);
		graph.findArt();
		// for (int i = 1; i < 8; i++) {
		// System.out.println(graph.getVertex(i).articulation);
		// }
	}

	@SuppressWarnings("unused")
	private static void printPath(MyGraph graph, int end) {
		if (graph.getVertex(end).path == 0)
			System.out.println(end);
		else {
			printPath(graph, (graph.getVertex(end).path));
			System.out.println(end);
		}
	}
}
