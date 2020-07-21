# Implementation of the Binary Search algorithm in Python
# Harris Ransom
 
def binary_search(input_array, value):
    bottom = 0
    top = len(input_array) - 1
    
    while (bottom <= top):
        middle = int((bottom + top) / 2)     # Gets middle index
        if (input_array[middle] < value):    # Case 1: middle < value, cut bottom
            bottom = middle + 1
        elif (input_array[middle] > value):  # Case 2: middle > value, cut top
            top = middle - 1
        else:
            return middle                    # Case 3: middle == value, return middle
    return -1                                # Algorithm unsuccessful
    
test_list = [1,3,9,11,15,19,29]
test_val1 = 25
test_val2 = 15
print(binary_search(test_list, test_val1))
print(binary_search(test_list, test_val2))
