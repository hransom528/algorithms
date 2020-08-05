// Implementation of the Gnome Sort algorithm in Java
// Harris Ransom

class javaGnomeSort {
    /** Functions **/
    // Gnome Sort implementation
    static void gnomeSort(int arr[]) {
        int i = 1;
        int len = arr.length;
        int temp;
        
        while (i < len) {
            if (i == 0) {
                i++;
            }
            if (arr[i] >= arr[i - 1]) {
                i++;
            }
            else {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                i--;
            }
        }
    }
    
    // Utility to format and print array
    static void printArr(int arr[]) {
        StringBuilder sb = new StringBuilder();
        sb.append("Size: ");
        sb.append(arr.length + "\n");
        
        for (int i : arr) sb.append(i + "\n");
        System.out.println(sb.toString());
    }
    
    /** MAIN **/
    public static void main(String[] args) {
        int nums[] = {3, 6, 10, 5, 1, 7, 4, 9, 2, 8};
        System.out.println("Initial array: ");
        printArr(nums);
        
        gnomeSort(nums);
        System.out.println("Sorted array: ");
        printArr(nums);
    }
}
