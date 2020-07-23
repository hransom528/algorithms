// Implementation of the Quick Sort algorithm in Java
// Harris Ransom

public class javaQuickSort {
	// Helper method to partition array with pivot
	private static int partition(int arr[], int start, int end) {
		int pivot = arr[end];
		int i = (start - 1);	// Tracks sorted elements
		int temp;
		
		// Iterates through array to partition elements
		for (int j = start; j < end; j++) {
			if (arr[j] <= pivot) {
				i++;	// Moves partition forward
				
				// Swaps smaller value and larger value
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		
		// Swaps end of sorted with end of arr
		temp = arr[i + 1];
		arr[i + 1] = arr[end];
		arr[end] = temp;
		
		return i + 1;	// Return final sorted position
	}
	
	// Quick Sort implementation
	public static void quickSort(int arr[], int start, int end) {
		if (start < end) {
			int index = partition(arr, start, end);	// Partitions array and grabs index
			
			// Recursively sort two partitions
			quickSort(arr, start, index - 1);
			quickSort(arr, index + 1, end);
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
		int[] nums = {2, 5, 1, 9, 7, 4, 10, 6, 3, 8};
		System.out.println("Initial array: ");
		printArr(nums);
		
		// Sorts array and outputs results
		quickSort(nums, 0, nums.length - 1);
		System.out.println("\nSorted array: ");
		printArr(nums);
	}
}
