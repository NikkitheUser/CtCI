import java.util.Arrays;
import java.util.Random;

public class heavierPills {
	
	public static double findPills(double[] arr) {
		double sum = 0;;
		
		for (int i = 0; i < arr.length; i++)
			sum += arr[i] * (i+1);
		
		return (sum - 210);
	}
	

	public static void main(String[] args) {
		Random rand = new Random();
		int diff = rand.nextInt(20);
		double[] arr = new double[20];
		Arrays.fill(arr, 1);
		for (int i = 0; i < 20; i++)
			if (i == diff)
				arr[i] = 1.1;
		double result = findPills(arr);
		
		System.out.println("Heavier pills are in bottle " + (int)(result/0.1));
		
	}
}
	
	
