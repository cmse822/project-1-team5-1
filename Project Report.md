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
    lscpu returns the information for entire cluster, but techinically we are only running on one CPU in the entire cluster.     
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
    Avg. Measured Speed (per core): 0.0946 Gflop/s      
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
    Avg. Measured Speed (per core): 0.156 Gflop/s  
    L1d cache: 32K     
    L1i cache: 32K     
    L2 cache: 512K     
    L3 cache: 16384K     
    
    The Intel18 has 40 cores while AMD20 has 128 cores. A higher core means better parallel processing capabilities. AMD20 also has a higher clock speed which means faster processing speed for individual tasks. AMD20, hence has a higher theoretical peak performance than Intel18. The measured speed is measured using matrix multiplication running on a single core on the clusters.

    For N = 100, both architecture has significantly lower measured performance than theoretical peak performance. This is mainly due to the lack of parallelization in the matrix multiplication, and possibly power constraints set by HPCC. AMD20 also has slighly higer measured performance as compared to Intel18.

    The average measured performance for multiple N's compare to peak is also significantly lower, and also running out of memory for larger N's. Both architecutres has a peak performance at N in range (100, 900) and slowly decreasing as size of N gets larger.

# Part 2

2. 
We ran the Empirical Roofline Model on 2 architectures on HPCC: intel 18 and amd 20. The empirical plots that we got are below:


<img src="part2/intel18_roofline.pdf" width="50%" height="auto">

<img src="part2/amd20_roofline.png" width="50%" height="auto">

3. **Peak performances, bandwidths, and ridgeline:**
The above Roofline plots illustrate the relationship between operational intensity and the performance of the computing architecture – GFLOPS/s / FLOPS/byte.  Value labels of each red line correspond to the maximum memory bandwidth available at cache levels L1, L2, and DRAM – this being the rate data can be read or written to memory from the CPU.  The different cache levels have a theoretical maximum memory bound bandwidth of 56.4, 37.4 and 20.5 GB/s for L1, L2 and DRAM, respectively. The peak theoretical performance for FP64 – the double-precision operations is 12.3 GLOPS/sec. Intersections of L1, L2, and DRAM and the horizontal peak performance line are the ridge-line points that highlight the moment when arithmetic/operational intensity is constrained by the machine’s computing ability, rather than its memory bandwidth.  Hence, by attempting to keep more of a tasks workload in the higher-level caches, like L1, we can approach the peak performance and, thus, efficiency for that machine.

 $$Arithmetic Intensity = \frac{Peak Performance(GFLOPs/sec)}{Bandwidth(GB/sec)}$$
Hence,
 $L1CacheRidgepoint = \frac{12.3 GFLOPs/sec}{56.4 GB/s} = 0.218 FLOPS/byte$

$L2CacheRidgepoint = \frac{12.3 GFLOPs/sec}{37.4.4 GB/s} = 0.328 FLOPS/byte$

$DRAMCacheRidgepoint = \frac{12.3 GFLOPs/sec}{20.5 GB/s} = 0.6 FLOPS/byte$

4.**Consider the four FP kernels in "Roofline: An Insightful Visual Performance Model for Floating-Point Programs and Multicore Architectures" (see their Table 2). Assuming the high end of operational (i.e., "arithmetic") intensity, how would these kernels perform on the platforms you are testing? What optimization strategy would you recommend to increase performance of these kernels?**

5. **Address the same questions in (4) for the four kernels given in the Warm-up above.**


6. **Compare your results for the roofline model to what you obtained for the matrix-matrix multiplication operation from Part 1. How are the rooflines of memory bandwidth related to the features in the algorithmic performance as a function of matrix size?**

(Based on the spoiler alert he gave in the class, the punchline to the answer is): To maximize the efficiency of your system’s workload in computing matrix- matrix multiplication, making the cache size correspond closely to the row/column size of the matrix improves the spatial locality of the data within memory.  If the dimensions of the rows/columns fit within the first cache, for example, the number of cache misses will decrease – this is specifically relevant since much of the matrix rows/cols are reused in matrix-matrix multiplication.  The strategy to accomplish this, as the paper mentions, is called blocking.  This strategy could improve the efficiency of matrix multiplication by making more efficient use of the CPU cache by dividing the matrices into smaller pieces that fit in the cache and thus do not need to be repeatedly accessed in lower levels of memory due to improved spatial and temporal locality. (**Results specific to our experiments next need to be commented on**).