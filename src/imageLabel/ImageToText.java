package imageLabel;

import java.awt.image.BufferedImage;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import javax.imageio.ImageIO;

public class ImageToText {
	public static void main(String[] args) {
		File file = new File("1.png");
		try {
			BufferedImage image = ImageIO.read(file);
			int[][] b = new int[image.getWidth()][image.getHeight()];
			for (int i = 0; i < b.length; i++)
				for (int j = 0; j < b[0].length; j++) {
					b[i][j] = (image.getRGB(i, j) & 0xff) / 255;
				}
			file = new File("1.txt");
			file.createNewFile();
			BufferedWriter bw = new BufferedWriter(new FileWriter(file));
			for (int j = 0; j < b[0].length; j++) {
				for (int i = 0; i < b[0].length; i++)
					bw.write(Integer.toString(b[i][j]) + ' ');
				bw.write("\r\n");
			}
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
