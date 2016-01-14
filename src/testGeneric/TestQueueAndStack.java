package testGeneric;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class TestQueueAndStack {
	/**
	 * @param args
	 * @author JavaAlpha Info 测试队列
	 */
	public static void main(String[] args) {
		Stack<String> stack = new Stack<String>();
		stack.push("1");// 插入一个元素
		stack.push("2");
		stack.push("3");
		// 打印元素个数
		System.out.println("stack.size()" + stack.size());
		// 遍历打印所有的元素,安装插入是顺序打印
		// for (String string : queue) {
		// System.out.println(string);
		// }
		while (!stack.isEmpty()) {
			System.out.println(stack.pop());
		}

		Queue<String> queue = new LinkedList<String>();
		queue.offer("1"); // 插入一个元素
		queue.offer("2");
		queue.offer("3");
		// 打印元素个数
		System.out.println("queue.size()" + queue.size());
		// 遍历打印所有的元素,安装插入是顺序打印
		while (!queue.isEmpty()) {
			System.out.println(queue.poll());
		}
	}
}
