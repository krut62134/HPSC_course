# python_script.py

import ctypes

# Load the shared library
libprime = ctypes.CDLL('./libprime.so')

# Define the argument and return types for the checkPrime function
libprime.checkPrime.argtypes = [ctypes.c_int]
libprime.checkPrime.restype = None

# Call the C function from Python
for i in range(1000):
    N = 1000000000 + i
    libprime.checkPrime(N)

