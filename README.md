# Operating-System

## Codes Explanation

### Algorithms Used in this Repo

### 1. CPU Scheduling Algorithm

This part of the project involves the comparison between two CPU scheduling algorithms:
1. **Priority Scheduling (Preemptive)**: Processes are executed based on their priority. If a higher-priority process arrives, it interrupts the current process.
2. **Round Robin (RR)**: Processes are executed in a cyclic order with a user-defined time quantum, ensuring that each process gets an equal share of CPU time.

<p align="center">
  <img src="https://github.com/ar-sayeem/Operating-System/raw/main/img-cpu-scheduling.JPG" alt="CPU Scheduling Comparison"/>
</p>

### Results:

- **Priority Scheduling** works well for real-time systems but may lead to starvation for lower-priority processes.
- **Round Robin** ensures fairness, but its performance depends on the time quantum chosen. A smaller time slice leads to increased overhead.


### 2. Page Replacement Algorithm

This section covers the implementation of three page replacement algorithms:
1. **First-In-First-Out (FIFO)**: Replaces the oldest page in memory.
2. **Least Recently Used (LRU)**: Replaces the least recently used page.
3. **Optimal (OPT)**: Replaces the page that will not be used for the longest time.

<p align="center">
  <img src="https://github.com/ar-sayeem/Operating-System/raw/main/img-page-replacement.JPG" alt="Page Replacement Algorithm"/>
</p>

### Results:

- **OPT** provides the best performance by minimizing page faults but is impractical in real systems due to its need to predict future page references.
- **LRU** performs better than **FIFO**, especially in systems where pages are reused frequently.
- **FIFO** is simple but can perform poorly when older pages are still in use.


### 3. Banker's Algorithm

The Banker's Algorithm is used to avoid deadlock in systems by ensuring that resource allocation leaves the system in a safe state.

### Steps:

1. **Need Matrix Calculation**: The need matrix is derived by subtracting the allocated resources from the maximum required resources for each process.
2. **Safe Sequence**: The algorithm checks if a safe sequence exists for resource allocation, ensuring the system will not enter a deadlock state.

<p align="center">
  <img src="https://github.com/ar-sayeem/Operating-System/raw/main/img-banker's-algo.JPG" alt="Banker's Algorithm"/>
</p>

### Results:

- The Banker's Algorithm ensures safe resource allocation but requires predefined resource limits, which may not be suitable for dynamic systems.
---

### Conclusion

Each algorithm has its strengths and weaknesses:
- **CPU Scheduling Algorithms**: Priority Scheduling is suitable for critical tasks but suffers from starvation. Round Robin is fair but may require careful tuning of the time quantum.
- **Page Replacement Algorithms**: OPT is theoretically ideal, while LRU provides a practical solution with better performance than FIFO.
- **Banker's Algorithm**: Useful for deadlock avoidance but requires static resource limits.
