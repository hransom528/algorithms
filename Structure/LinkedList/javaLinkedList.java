// Implementation of built-in Linked List data structure in Java 
// Harris Ransom
import java.util.LinkedList;
import java.util.ListIterator;

public class javaLinkedList {
	static final int NUM_ITEMS = 25; // Total number of starting nums in LL
	
	// Prints out list
	public static void printList(LinkedList ll) {
		if (!ll.isEmpty()) {
			ListIterator it = ll.listIterator(0);		// Gets iterator for list
			StringBuilder sb = new StringBuilder();		// For building output
			sb.append('\n');
			
			while (it.hasNext()) {				// Iterates over entire list
				sb.append(it.next());
				sb.append(" - ");
			}
			sb.delete(sb.length() - 3, sb.length() - 1);	// Trims last dash
			System.out.println(sb.toString());		// Prints out result
		}
		else { // List empty
			System.out.println("\nEmpty list");
		}
	}
	
	// MAIN
	public static void main(String[] args) {
		// Initializes list
		LinkedList<Integer> ll = new LinkedList<Integer>();
		for (int i = 0; i < NUM_ITEMS; i++) {
			ll.add(i);
		}
		System.out.print("Initial list: ");
		printList(ll);
		
		// Inserts 75 at head
		ll.addFirst(75);
		System.out.print("\nAdded 75 at head");
		printList(ll);
		
		// Determines if list contains 100 and 13
		System.out.println("\nContains 100? " + ll.contains(100));
		System.out.println("Contains 13? " + ll.contains(13));
		
		// Finds 13 and gets it
		int temp = ll.indexOf(13);
		System.out.println("\nIndex of 13: " + temp);
		System.out.println("Item at index: " + ll.get(temp));
		
		// Gets tail of list
		temp = ll.pollLast();
		System.out.println("\nTail of list: " + temp);
		
		// Appends 20 to tail
		ll.addLast(20);
		System.out.print("\n20 appended to tail");
		printList(ll);
		System.out.println("New tail: " + ll.pollLast());
		
		// Clears list
		ll.clear();
		System.out.print("\nCleared Linked List");
		printList(ll);
	}
}
