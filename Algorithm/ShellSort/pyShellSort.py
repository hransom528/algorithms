# Implementation of Shell Sort algorithm in Python

def shellSort(arr):
    interval = 1
    # Initializes interval
    while (interval < (len(arr) // 3)):
        interval = (interval * 3) + 1
    
    
    while (interval > 0):
        for i in range(interval, len(arr)):
            # Select val to be inserted
            val = arr[i]
            j = i
            
            # Shift element right
            while ((j > interval - 1) and (arr[j - interval] >= val)):
                arr[j] = arr[j - interval]
                j -= interval
            
            # Insert val at hole position
            arr[j] = val
            
        # Calculate interval
        interval = (interval - 1) / 3
    
l = [4, 1, 2, 5, 3]
print("Initial list: " + str(l))
shellSort(l)
print("Sorted list: " + str(l))
