import ctypes
from concurrent.futures import ProcessPoolExecutor

# Load the shared library
libprime = ctypes.CDLL('./libprime.so')
libprime.checkPrime.argtypes = [ctypes.c_int]
libprime.checkPrime.restype = None

def check_prime_wrapper(N):
    libprime.checkPrime(N)

def main():
    # Number of iterations
    num_iterations = 1000

    # List of numbers to process
    numbers = [1000000000 + i for i in range(num_iterations)]

    # Use ProcessPoolExecutor to parallelize the loop
    with ProcessPoolExecutor() as executor:
        # Submit tasks to the pool
        futures = [executor.submit(check_prime_wrapper, N) for N in numbers]

        # Wait for all tasks to complete
        for future in futures:
            future.result()

if __name__ == "__main__":
    main()

