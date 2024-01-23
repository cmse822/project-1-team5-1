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
    Machine: Intel(R) Xeon(R) Gold 6148 CPU @ 2.40GHz (Intel18)       
    Average Time Computing: 0.0115497    
    Performance in Mflop/s(scientific format): 1.73e+02    
    Performance in Mflop/s: 173.16    
        
    AMD EPYC 7H12 64-Core Processor (AMD20)        
    Average Time Computing: 0.000941665    
    Performance in Mflop/s(scientific format): 2.12e+03    
    Performance in Mflop/s: 2123.90    

4. `Theoretical Peak = Clock Speed x No. of Floating Point Units x No. of Cores`   
    Machine: Intel(R) Xeon(R) Gold 6148 CPU @ 2.40GHz (Intel18)   
    Clock Speed = 2.40GHz    
    No. of Floating Point Units = 1    
    No. of Cores = 40    
    Theoretical Peak (total) = 96 Gflop/s    
    Theoretical Peak (per core) = 2.4 Gflop/s      
    The measured performance is significantly lower than the theoretical peak performance.     
        
    AMD EPYC 7H12 64-Core Processor (AMD20)    
    Clock Speed = 2.595009GHz        
    No. of Floating Point Units = 1    
    No. of Cores = 128    
    Theoretical Peak = 332.161152 Gflop/s    
    Theoretical Peak (per core) = 2.60 Gflop/s      
    The measured performance is significantly lower than the theoretical peak performance.   

5.  
<img src="part1/result_intel18.png" width="50%" height="auto">

<img src="part1/result_amd20.png" width="50%" height="auto">

6.   
    Machine: Intel(R) Xeon(R) Gold 6148 CPU @ 2.40GHz (Intel18)   
    Architecture: x86_64      
    Clock Speed: 2.40GHz    
    No. of Cores: 40    
    Theoretical Peak: 96 Gflop/s  
    Theoretical Peak (per core) = 2.4 Gflop/s    
    Measured Speed (per core): 0.0946 Gflop/s      
    L1d cache: 32K     
    L1i cache: 32K    
    L2 cache: 1024K     
    L3 cache: 28160K     
        
    AMD EPYC 7H12 64-Core Processor (AMD20)    
    Architecture: x86_64      
    Clock Speed: 2.595009GHz         
    No. of Cores: 128    
    Theoretical Peak: 332.161152 Gflop/s    
    Theoretical Peak (per core) = 2.60 Gflop/s    
    Measured Speed (per core): 0.156 Gflop/s  
    L1d cache: 32K     
    L1i cache: 32K     
    L2 cache: 512K     
    L3 cache: 16384K     
    
    The Intel18 has 40 cores while AMD20 has 128 cores. A higher core means better parallel processing capabilities. AMD20 also has a higher clock speed which means faster processing speed for individual tasks. AMD20, hence has a higher theoretical peak performance than Intel18.      
            
    The measured speed is measured using matrix multiplication running on a single core on the processor.

    For N = 100, both architecture has significantly lower measured performance than theoretical peak performance. This is mainly due to the lack of parallelization in the matrix multiplication, and possibly power constraints set by HPCC. AMD20 also has slighly higer measured performance as compared to Intel18.

    The measured performance for multiple N's compare to peak is also significantly lower, and also running out of memory for larger N's. Both architecutres has an "almost" straight line graph for multiple N's.

# Part 2