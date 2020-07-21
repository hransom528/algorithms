// Implementation of Binary Search algorithm in Java
// Harris Ransom

public class javaBinSearch {
	// Binary Search implementation
	public static int binSearch(int arr[], int val) {
		int bottom = 0;
		int top = arr.length - 1;
		
		while (bottom <= top) {
			int middle = (int) ((top + bottom) / 2);
			if (arr[middle] == val) {
				return middle;
			}
			else if (val > arr[middle]) {
				bottom = middle + 1;
			}
			else {
				top = middle - 1;
			}
		}
		return -1;
	}
	
	// MAIN
	public static void main (String[] args) {
		int[] testArr = {1, 3, 9, 11, 15, 19, 29};
		int test1 = 25;
		int test2 = 15;
		
		System.out.println("\nTest case 1 (" + test1 + "): " + binSearch(testArr, test1));
		System.out.println("\nTest case 2 (" + test2 + "): " + binSearch(testArr, test2));
	}
}
