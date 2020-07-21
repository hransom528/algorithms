// Factorial finder written in Java
// Harris Ransom
import java.util.Scanner;

public class javaFactorial {
	static final short MAX_NUM = 20; // Maximum input before overflow
	
	// Recursively finds factorial of given num
	public static long findFactorial(int num) {
		if (num <= 1) {
			return 1;
		}
		else if (num > MAX_NUM) {
			return -1;
		}
		else {
			long result = num * findFactorial(num - 1);
			return result;
		}
	}
	
	
	// MAIN
	public static void main (String[] args) {
		// Gets input
		Scanner scnr = new Scanner(System.in);
		short input; 
		System.out.print("Enter the number you wish to calculate the factorial for: ");
		input = scnr.nextShort();
		while (input > MAX_NUM) {
			System.out.print("Please enter " + MAX_NUM + " or lower: ");
			input = scnr.nextShort();
		}
		
		// Calculates and returns factorial
		System.out.print("Results of " + input + "!: " + findFactorial(input));
	}
}
