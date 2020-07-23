# Implementation of Quick Sort in Python
# Harris Ransom

# Pivots and partitions array
def partition(array, start, end):
    pivot = array[end]
    i = start - 1
    
    for j in range (start, end):
        if (array[j] <= pivot):
            i += 1
            array[i], array[j] = array[j], array[i]
    
    array[i + 1], array[end] = array[end], array[i + 1]
    return i + 1
    
# Quick Sort implementation
def quickSort(array, start, end):
    if (start < end):
        index = partition(array, start, end)
        quickSort(array, start, index - 1)
        quickSort(array, index + 1, end)
    return array

# Testing
test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
print quickSort(test, 0, len(test) - 1)
