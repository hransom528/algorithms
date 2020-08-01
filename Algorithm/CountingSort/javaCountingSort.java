// Implementation of Counting Sort algorithm in Java
// Harris Ransom

class javaCountingSort {
	static void countingSort(short[] arr) {
		int len = arr.length;		 // Grabs length
		short[] output = new short[len]; // Initializes return array
		
		// Initialize count array
		short[] count = new short[Short.MAX_VALUE];
		for (int i = 0; i < count.length; i++)
			count[i] = 0;

		// Store count of each item
		for (int i = 0; i < len; i++)
			++count[arr[i]];	// Increments count of item when found
		
		// Change count[i] to represent actual position in array
		for (int i = 1; i <= count.length - 1; i++)
			count[i] += count[i-1];

		// Build output array
		for (int i = len - 1; i >= 0; i--) {
			output[count[arr[i]] - 1] = arr[i];
			--count[arr[i]];
		}

		// Copy output to arr
		for (int i = 0; i < len; i++)
			arr[i] = output[i];
	}

	// Array to String utility
	static String arrToStr(short[] arr) {
		StringBuilder sb = new StringBuilder();
		sb.append('[');

		for (int i = 0; i < arr.length; i++) {
			if (i == arr.length - 1) {
				sb.append(arr[i]);
				sb.append(']');
			}
			else {
				sb.append(arr[i]);
				sb.append(", ");
			}
		}
		return sb.toString();
	}

	// MAIN
	public static void main(String args[]) {
		short[] nums = {3, 0, 2, 5, 4, 1};
		System.out.println("Initial array: ");
		System.out.println(arrToStr(nums));

		countingSort(nums);
		System.out.println("Sorted array: ");
		System.out.println(arrToStr(nums));
	}
}

