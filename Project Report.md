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
  Average Time Computing: 0.0112917.   
 `Mflop_s = (pow(num,3)*2)/average_time`  
  performance in Mflop/s(scientific format): 1.77121e+08.  
  performance in Mflop/s: 177121369.81.
- question 4: 
  Machine: Intel(R) Xeon(R) Gold 6148 CPU @ 2.40GHz
  `Theoretical Peak = Clock Speed x No. of Floating Point Units x No. of Cores`
  Clock Speed = 2.40GHz.
  No. of Floating Point Units = 1.
  No. of Cores = 40
  Theoretical Peak = 96 GFLOPS


# Part 2