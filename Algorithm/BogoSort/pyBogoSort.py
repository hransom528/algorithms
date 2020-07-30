# Implementation of the Bogo Sort joke algorithm
import random

# Checks if list is sorted
def sorted(arr):
    val = True
    for i in range(len(arr) - 1):
        if (arr[i] > arr[i+1]):
            val = False
    return val

# Bogosort algorithm implementation
def bogoSort(arr):
    while (not sorted(arr)):
        random.shuffle(arr)

l = [4, 2, 5, 3, 1]
print("Initial list: " + str(l))
bogoSort(l)
print("Sorted list: " + str(l))

