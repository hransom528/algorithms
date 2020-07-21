# Implementation of a recursive Fibonacci sequence in Python
# Harris Ransom

# Gets Fibonacci number associated with given position
def fib(pos):
    if ((pos == 0) or (pos == 1)):
        return pos
    return fib(position - 1) + fib(position - 2)

# Test cases
print fib(9)  # 9th Fib number
print fib(11) # 11th Fib number
print fib(0)  # 0th Fib number
