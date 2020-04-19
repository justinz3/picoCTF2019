
import java.util.*;

public class WordCounter {
	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		while(reader.hasNext()) {
			String line = reader.nextLine();
			System.out.printf("%d ", ((line.split(" ")).length - 1) / 3);
		}
		System.out.println();
	}
}
