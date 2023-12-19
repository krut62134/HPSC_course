from multiprocessing import Pool
import os

def f(x):
    # Use the os (=operating system) package to report the process id
    print("parent ID: ", os.getppid())
    print("process id:", os.getpid())
    
    # Compute the value of some function f(x) = x*x
    result = x * x
    return result

# Create a team of 5 processes (it's better to view these as threads)
p = Pool(5)

# Tell each process to compute f(x) where x is one of 1, 2, 3
input_list = [1, 2, 3]
result = p.map(f, input_list)
print(result)

