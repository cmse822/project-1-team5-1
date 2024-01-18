# Warm-up
1.   `Y[j] += Y[j] + A[j][i] * B[i]`.  
3 flop, 4 memory operation
2. ` s += A[i] * A[i]`.  
2 flop, 1 memory operation
3. ` s += A[i] * B[i]`.  
2 flop, 2 memory operation
4. ` Y[i] = A[i] + C*B[i]`.  
2 flop, 3 memory operation

# Part 1
- question 1: see matrix_multiplication function in file part1.cpp.  
- question 2: `result[i][j] += matrix_one[i][k] * matrix_two[k][j];`.  
  2 flop, 3 memory operation.  
Putting this line of code into a three nested loop with given matrix size N, and we get result, N^3/12
- question 3: execution time: 0.00534606
- question 4: hint: you would calculate the theoretical peak performance as the product of the clock speed (in ticks per second), number of floating point units, and the
  number of cores.



# Part 2