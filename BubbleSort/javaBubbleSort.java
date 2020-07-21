// Implementation of Bubble Sort algorithm in Java
// Harris Ransom

public class javaBubbleSort {
	// Bubble Sort algorithm
	public static void bubbleSort(int[] arr) {
		boolean swapped;
		int temp;
		do {
			swapped = false;
			for (int i = 0; i < arr.length - 1; i++) {
				if (arr[i] > arr[i + 1]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					swapped = true;
				}
			}
		} while (swapped);
	}
	
	// MAIN
	public static void main (String[] args) {
		// Initialization
		int nums[] = {14, 2, 20, 18, 8, 15, 1, 10, 6, 17, 4, 13, 9, 19, 3, 12, 7, 16, 5, 11};
		System.out.println("Initial array: ");
		for (int i = 0; i < nums.length; i++) {
			if (i <= 9) {
				System.out.println("\tIndex " + i + "  - " + nums[i]);
	 		}
	 		else {
				System.out.println("\tIndex " + i + " - " + nums[i]);
			}
		}
		
		bubbleSort(nums); // Sorts
		
		// Displays results
		System.out.println("\nBubble Sort results: ");
		for (int i = 0; i < nums.length; i++) {
			if (i <= 9) {
				System.out.println("\tIndex " + i + "  - " + nums[i]);
	 		}
	 		else {
				System.out.println("\tIndex " + i + " - " + nums[i]);
			}
		}	
	}
}
