# Warm-up
1. `Y[j] += Y[j] + A[j][i] * B[i]`  
Memory Opertaion: 3   
FLOP: 4   

2. `s += A[i] * A[i]`   
Memory Opertaion: 2   
FLOP: 1   

3. `s += A[i] * B[i]`   
Memory Opertaion: 2   
FLOP: 2   

4. `Y[i] = A[i] + C*B[i]`   
Memory Opertaion: 2   
FLOP: 3   

# Part 1
1. file part1.cpp   

2. `result[i][j] += matrix_one[i][k] * matrix_two[k][j];`   
Memory Opertaion: 2   
FLOP: 3    
Putting this line of code into a three nested loop with given matrix size N, and we get result, 2*N^3

3. `Mflop_s = (pow(num,3)*2) /average_time/ pow(10,6)`    
Average Time Computing: 0.0115497    
Performance in Mflop/s(scientific format): 1.73e+02    
Performance in Mflop/s: 173.16    

4. `Theoretical Peak = Clock Speed x No. of Floating Point Units x No. of Cores`   
Machine: Intel(R) Xeon(R) Gold 6148 CPU @ 2.40GHz    
Clock Speed = 2.40GHz    
No. of Floating Point Units = 1    
No. of Cores = 40    
Theoretical Peak = 96 Gflop/s    
The measured performance is significantly lower than the theoretical peak performance. 
  
5.

6.

# Part 2