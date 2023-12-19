from multiprocessing import Pool
import os

def complicated_function(x):
    # Use the os (=operating system) package to report the process id
    print("parent ID: ", os.getppid())
    print("process id:", os.getpid())
    
    # Modify f(x) to be something much more complicated
    result = some_complicated_processing(x)
    
    return result

def some_complicated_processing(x):
    # Placeholder for a more complicated processing function
    # You can replace this with your actual complex logic
    return x * x + 2 * x - 1

# Create a team of 5 processes (it's better to view these as threads)
p = Pool(8)

# Modify the input list to pass millions of values to the map
input_list = list(range(1, 1000001))
result = p.map(complicated_function, input_list)

# Print only the first few results for brevity
print(result[:10])

