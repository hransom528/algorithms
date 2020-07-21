# Implementation of the Bubble Sort algorithm in Python
# Harris Ransom

# Bubble Sort algorithm implementation
def bubbleSort(listToSort):
	while (True):
		swapped = False
		for i in range (0, len(listToSort) - 1):
			if (listToSort[i] > listToSort[i + 1]):
				listToSort[i], listToSort[i + 1] = listToSort[i + 1], listToSort[i]
				swapped = True
		if (not swapped):
			break

# Unsorted
nums = [14, 2, 20, 18, 8, 15, 1, 10, 6, 17, 4, 13, 9, 19, 3, 12, 7, 16, 5, 11]
print("List before sorting: ")
print(nums)

# Sorted
bubbleSort(nums)
print("List after Bubble Sort: ")
print(nums)

