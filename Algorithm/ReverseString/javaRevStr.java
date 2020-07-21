// Implements both built-in and non-built-in string reverse methods in Java
// Harris Ransom

import java.util.Scanner;

class javaRevStr {
	public static String revStr(String origStr) {
		char[] ch = origStr.toCharArray();
		String ret = "";

		// Iterates backwards through origStr
		for (int i = origStr.length() - 1; i >= 0; i--) {
			ret += ch[i];
		}
		return ret;
	}

	// MAIN
	public static void main(String argv[]) {
		Scanner scnr = new Scanner(System.in);
		String origStr, biRev, rev;

		// Gets input
		System.out.println("Please input the string you would like to reverse: ");
		origStr = scnr.nextLine();
		scnr.close();

		// Built-in reverse method
		StringBuilder sb = new StringBuilder(origStr);
		biRev = sb.reverse().toString();

		// Implemented reverse method
		rev = revStr(origStr);

		// Outputs results
		System.out.println("\nResults: ");
		System.out.println("Built in reverse:\t" + biRev);
		System.out.println("Implemented reverse:\t" + rev);
	}
}
