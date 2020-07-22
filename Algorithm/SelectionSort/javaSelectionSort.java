// Implementation of the Selection Sort algorithm in Java
// Harris Ransom

public class javaSelectionSort {
	// Selection Sort implementation
	public static void selectionSort(int[] arr) {
		int temp, min;
		for (int i = 0; i < arr.length - 1; i++) {	// Iterate through arr
			min = i;
			for (int j = i + 1; j < arr.length; j++) {	// Iterate through rest of arr
				if (arr[j] < arr[min]) {	// Get smallest remaining element
					min = j;
				}
			}
			
			// Swap min to end of sorted section
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	
	// Print out array
	public static void printArr(int[] arr) {
		for (int i : arr) {
			System.out.println("\t" + i);
		}
	}
	// MAIN
	public static void main (String[] args) {
		// Initial array
		int[] nums = {8, 2, 7, 1, 4, 2, 5, 9, 6, 10, 3};
		System.out.println("Initial array: ");
		printArr(nums);
		
		// Sorts array and outputs results
		selectionSort(nums);
		System.out.println("Sorted array: ");
		printArr(nums);
	}
}
