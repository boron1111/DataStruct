package imageLabel;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

import javax.imageio.ImageIO;

import ticToc.TicToc;
import disjSets.DisjSets;

public class ShowImage extends WindowAdapter {
	private Frame f;
	private BufferedImage image;

	public ShowImage() {
		f = new Frame();
		DrawCanvas dc = new DrawCanvas();
		f.add(dc);
		f.addWindowListener(this);// 添加关闭事件
		f.setBackground(new Color(255, 255, 255));// 设置背景颜色
		f.setLocationByPlatform(true);

		File file = new java.io.File("1.png");
		try {
			image = ImageIO.read(file);
		} catch (IOException e) {
			e.printStackTrace();
		}
		f.setSize(image.getWidth(null), image.getHeight(null));
		f.setVisible(true);
		f.setSize(image.getWidth(null) + 18, image.getHeight(null) + 45);

		// int type = image.getType();
		// if (type == BufferedImage.TYPE_INT_ARGB
		// || type == BufferedImage.TYPE_INT_RGB)
		// data = image.getRaster().getDataElements(0, 0,
		// image.getWidth(null), image.getHeight(null), null);
		// else
		// data = image.getRGB(0, 0, image.getWidth(null),
		// image.getHeight(null),
		// null, 0, image.getWidth());
		TicToc tictoc = new TicToc();
		tictoc.tic();
		// int[][][] rgb = new int[3][image.getWidth()][image.getHeight()];
		int[][] b = new int[image.getWidth()][image.getHeight()];

		for (int i = 0; i < b.length; i++)
			for (int j = 0; j < b[0].length; j++) {
				int pixel = image.getRGB(i, j);
				// rgb[0][i][j] = pixel & 0xFF0000 >> 16;
				// rgb[1][i][j] = pixel & 0xff00 >> 8;
				// rgb[2][i][j] = pixel & 0xff;
				// b[i][j] = (pixel & 0xff) > 20 ? 255 : 0;
				b[i][j] = pixel & 0xff;
				if (b[i][j] != 0 && b[i][j] != 255)
					System.out.println(b[i][j]);
			}

		for (int i = 0; i < b.length; i++)
			for (int j = 0; j < b[0].length; j++) {
				if (b[i][j] + (b[i][j] << 8) + (b[i][j] << 16) != 0
						&& b[i][j] + (b[i][j] << 8) + (b[i][j] << 16) != 0xffffff)
					System.out.println("faf");
				image.setRGB(i, j, b[i][j] + (b[i][j] << 8) + (b[i][j] << 16));
			}
		File outfile = new File("2.png");
		try {
			ImageIO.write(image, "png", outfile);
		} catch (IOException e) {
			e.printStackTrace();
		}

		tictoc.toc();
		tictoc.tic();
		DisjSets disj = new DisjSets(b.length * b[0].length);
		for (int i = 0; i < b.length; i++)
			for (int j = 0; j < b[0].length; j++)
				findAdjacentAndMerge(i, j, b, b.length, disj);
		tictoc.toc();
		tictoc.tic();
		ArrayList<Integer> roots = disj.findRoots();
		tictoc.toc();
		System.out.println(roots.size());
		HashMap<Integer, Integer> rootsMap = new HashMap<Integer, Integer>();
		int delta = 255 / roots.size();
		int[] depth = new int[roots.size()];
		depth[0] = 0;
		rootsMap.put(roots.get(0), 0);
		for (int i = 1; i < roots.size(); i++) {
			depth[i] = depth[i - 1] + delta;
			rootsMap.put(roots.get(i), i);
		}
		for (int i = 0; i < b.length; i++)
			for (int j = 0; j < b[0].length; j++) {
				b[i][j] = depth[rootsMap.get(disj.find(i + b.length * j))];
				image.setRGB(i, j, b[i][j] + (b[i][j] << 8) + (b[i][j] << 16));
			}
		outfile = new File("3.png");
		try {
			ImageIO.write(image, "png", outfile);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void findAdjacentAndMerge(int i, int j, int[][] b, int width,
			DisjSets disj) {
		try {
			if (b[i - 1][j - 1] == b[i][j])
				findAndUnion((i - 1) + width * (j - 1), i + width * j, disj);
		} catch (Exception e) {
		}
		try {
			if (b[i - 1][j] == b[i][j])
				findAndUnion((i - 1) + width * j, i + width * j, disj);
		} catch (Exception e) {
		}
		try {
			if (b[i - 1][j + 1] == b[i][j])
				findAndUnion(i - 1 + width * (j + 1), i + width * j, disj);
		} catch (Exception e) {
		}
		try {
			if (b[i][j - 1] == b[i][j])
				findAndUnion((i) + width * (j - 1), i + width * j, disj);
		} catch (Exception e) {
		}
		try {
			if (b[i - 1][j + 1] == b[i][j])
				findAndUnion((i - 1) + width * (j + 1), i + width * j, disj);
		} catch (Exception e) {
		}
		// try {
		// if (b[i + 1][j - 1] == b[i][j])
		// findAndUnion(i + 1 + width * (j - 1), i + width * j, disj);
		// } catch (Exception e) {
		// }
		// try {
		// if (b[i + 1][j] == b[i][j])
		// findAndUnion((i + 1) + width * j, i + width * j, disj);
		// } catch (Exception e) {
		// }
		// try {
		// if (b[i + 1][j + 1] == b[i][j])
		// findAndUnion((i + 1) + width * (j + 1), i + width * j, disj);
		// } catch (Exception e) {
		// }
	}

	private void findAndUnion(int a, int b, DisjSets disj) {
		int root1 = disj.find(a);
		int root2 = disj.find(b);
		if (root1 != root2) {
			disj.union(root1, root2);
		}
	}

	public static void main(String[] args) {
		new ShowImage();
	}

	public void windowClosing(WindowEvent e) {
		f.dispose();
	}

	class DrawCanvas extends Canvas { // 新建画布类
		/**
	 * 
	 */
		private static final long serialVersionUID = 1L;

		@Override
		// 重写方法
		public void paint(Graphics g) {
			g.drawImage(image, 0, 0, null);
		}
	}
}