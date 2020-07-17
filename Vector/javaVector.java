// Implementation of Vector (ArrayList) in Java
// Harris Ransom
import java.util.ArrayList;

public class javaVector {
	// Prints contents of given integer ArrayList
	static void printAL(ArrayList<Integer> al) {
		for (int i = 0; i < al.size(); i++) {
			System.out.println(al.get(i));
		}
		System.out.println("----");
	}
	
	// MAIN
	public static void main(String args[]) {
		ArrayList<Integer> nums = new ArrayList<Integer>(); // Built-in data structure
		
		// Appends 5 ints to list
		for (int i = 0; i < 5; i++) {
			nums.add(i);
		}
		printAL(nums);
		
		// Removes 2nd element
		nums.remove(1);
		printAL(nums);
		
		// Inserts 1 at index 3
		nums.add(3, 1);
		printAL(nums);
		
		// Pops the last element and inserts it at index 1
		int popped = nums.remove(nums.size() - 1);
		nums.add(1, popped);
		printAL(nums);
		
		// Clears list
		nums.clear();
		printAL(nums); 
	}
}
