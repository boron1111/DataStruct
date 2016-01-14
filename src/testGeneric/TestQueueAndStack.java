package testGeneric;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class TestQueueAndStack {
	/**
	 * @param args
	 * @author JavaAlpha Info ���Զ���
	 */
	public static void main(String[] args) {
		Stack<String> stack = new Stack<String>();
		stack.push("1");// ����һ��Ԫ��
		stack.push("2");
		stack.push("3");
		// ��ӡԪ�ظ���
		System.out.println("stack.size()" + stack.size());
		// ������ӡ���е�Ԫ��,��װ������˳���ӡ
		// for (String string : queue) {
		// System.out.println(string);
		// }
		while (!stack.isEmpty()) {
			System.out.println(stack.pop());
		}

		Queue<String> queue = new LinkedList<String>();
		queue.offer("1"); // ����һ��Ԫ��
		queue.offer("2");
		queue.offer("3");
		// ��ӡԪ�ظ���
		System.out.println("queue.size()" + queue.size());
		// ������ӡ���е�Ԫ��,��װ������˳���ӡ
		while (!queue.isEmpty()) {
			System.out.println(queue.poll());
		}
	}
}
