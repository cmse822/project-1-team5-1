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
- question 1:   
see matrix_multiplication function in file part1.cpp.  
- question 2:   
`result[i][j] += matrix_one[i][k] * matrix_two[k][j];`.  
  2 flop, 3 memory operation.  
Putting this line of code into a three nested loop with given matrix size N, and we get result, 2*N^3
- question 3:  
  Average Time Computing: 0.00492464.   
 `Mflop_s = (pow(num,3)*2)/average_time`  
  performance in Mflop/s(scientific format): 4.06121e+08.  
  performance in Mflop/s: 406120805.89
- question 4: hint: you would calculate the theoretical peak performance as the product of the clock speed (in ticks per second), number of floating point units, and the
  number of cores. // citation: from textbook https://cmse822.github.io/assets/EijkhoutIntroToHPC2020.pdf 17.1



# Part 2