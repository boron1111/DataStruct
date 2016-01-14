package testGeneric;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.TreeMap;

import ticToc.TicToc;

public class Test_Words {

	public static void main(String[] args) {
		TicToc ticToc = new TicToc();

		List<String> words = new ArrayList<String>();
		// String word = new String();

		ticToc.tic();

		words.add("fubavd");
		words.add("subavd");
		words.add("fubyvd");
		words.add("aubavd");
		words.add("fubbvd");

		// for (int i = 0; i < 28205; i++) {
		// do {
		// word = randomString(6);
		// } while (words.contains(word));
		// words.add(word);
		// }

		// for (int i = 0; i < 11989; i++) {
		// do {
		// word = randomString(7);
		// } while (words.contains(word));
		// words.add(word);
		// }
		//
		// for (int i = 0; i < 13672; i++) {
		// do {
		// word = randomString(8);
		// } while (words.contains(word));
		// words.add(word);
		// }
		//
		// for (int i = 0; i < 13014; i++) {
		// do {
		// word = randomString(9);
		// } while (words.contains(word));
		// words.add(word);
		// }
		//
		// for (int i = 0; i < 11297; i++) {
		// do {
		// word = randomString(10);
		// } while (words.contains(word));
		// words.add(word);
		// }
		//
		// for (int i = 0; i < 8617; i++) {
		// do {
		// word = randomString(11);
		// } while (words.contains(word));
		// words.add(word);
		// }

		ticToc.toc();

		// for (String x : words) {
		// System.out.println(x);
		// }

		ticToc.tic();
		Map<String, List<String>> adjWords = computeAdjacentWords(words);
		ticToc.toc();

		// ticToc.tic();
		// Map<String, List<String>> adjWords1 = computeAdjacentWords1(words);
		// ticToc.toc();

		for (Map.Entry<String, List<String>> entry : adjWords.entrySet()) {
			if (entry.getValue().size() > 0)
				System.out.println(entry.getValue());
			// System.out.println(adjWords1.get(entry.getKey()));
		}
	}

	/**
	 * Computes a map in which the keys are words and values are Lists words
	 * that differ in only one character from the correspoinding key. Uses a
	 * quadratic algorithm (with appropriate Map).
	 */
	public static Map<String, List<String>> computeAdjacentWords1(
			List<String> theWords) {
		Map<String, List<String>> adjWords = new TreeMap<String, List<String>>();
		String[] words = new String[theWords.size()];
		theWords.toArray(words);
		for (int i = 0; i < words.length; i++) {
			for (int j = i + 1; j < words.length; j++)
				if (oneCharOff(words[i], words[j])) {
					update(adjWords, words[i], words[j]);
					update(adjWords, words[j], words[i]);
				}
		}
		return adjWords;
	}

	private static boolean oneCharOff(String word1, String word2) {
		if (word1.length() != word2.length())
			return false;

		int diffs = 0;

		for (int i = 0; i < word1.length(); i++)
			if (word1.charAt(i) != word2.charAt(i))
				if (++diffs > 1)
					return false;
		return diffs == 1;
	}

	/**
	 * Compute a map in which the keys are words and values are Lists of words
	 * that differ in only one character from the corresponding key. Uses an
	 * efficient algorithm that is 0(N log N) with a TreeMap.
	 */
	public static Map<String, List<String>> computeAdjacentWords(
			List<String> words) {
		Map<String, List<String>> adjWords = new TreeMap<String, List<String>>();
		Map<Integer, List<String>> wordsByLength = new TreeMap<Integer, List<String>>();

		// Group the words by their length
		for (String w : words)
			update(wordsByLength, w.length(), w);

		// Work on each group separately
		for (Map.Entry<Integer, List<String>> entry : wordsByLength.entrySet()) {
			List<String> groupsWords = entry.getValue();
			int groupNum = entry.getKey();

			// Work on each position in each group
			for (int i = 0; i < groupNum; i++) {
				// Remove one character in specified position, computing
				// representative. Words with same representative are
				// adjacent, so first populate a map...
				Map<String, List<String>> repToWord = new TreeMap<String, List<String>>();

				for (String str : groupsWords) {
					String rep = str.substring(0, i) + str.substring(i + 1);
					update(repToWord, rep, str);
				}

				for (List<String> wordClique : repToWord.values())
					if (wordClique.size() >= 2)
						for (String s1 : wordClique)
							for (String s2 : wordClique)
								if (s1 != s2)
									update(adjWords, s1, s2);
			}
		}
		return adjWords;
	}

	public static <KeyType> void update(Map<KeyType, List<String>> m,
			KeyType key, String value) {
		List<String> lst = m.get(key);
		if (lst == null) {
			lst = new ArrayList<String>();
			m.put(key, lst);
		}
		lst.add(value);
	}

	/**
	 * Generate a random string
	 */

	private static Random randGen = null;
	private static char[] numbersAndLetters = null;

	public static final String randomString(int length) {
		if (length < 1) {
			return null;
		}
		if (randGen == null) {
			randGen = new Random();
			numbersAndLetters = ("abcdefghijklmnopqrstuvwxyz").toCharArray();
		}
		char[] randBuffer = new char[length];
		for (int i = 0; i < randBuffer.length; i++) {
			randBuffer[i] = numbersAndLetters[randGen
					.nextInt(numbersAndLetters.length - 1)];
		}
		return new String(randBuffer);
	}

}
