# Operating Systems

This repository contains two main sections: **Linux Basic Shell Commands** and **Operating System Algorithms**, providing essential knowledge for command-line operations and OS algorithm implementations.

---

## Linux Basic Shell Commands

A comprehensive guide to essential Linux commands, covering directory navigation, file manipulation, and system monitoring.

### Features
- Detailed explanations and examples of commands:
  - `pwd`, `ls`, `mkdir`, `rm`, `cp`, `nano`, etc.
  - System commands like `uname`, `whoami`, `uptime`.
- Ideal for beginners and professionals enhancing their Linux command-line skills.

<p align="center">
  <img src="https://github.com/ar-sayeem/Operating-System/blob/main/img/img-demo-linux.JPG"/>
</p>

---

## Algorithms

#### 1. CPU Scheduling Algorithm

This part of the project involves the comparison between two CPU scheduling algorithms:
1. **Priority Scheduling (Preemptive)**: Executes processes based on their priority. Interrupts the current process if a higher-priority one arrives.
2. **Round Robin (RR)**: Executes processes cyclically with a user-defined time quantum, ensuring fairness.

<p align="center">
  <img src="https://github.com/ar-sayeem/Operating-System/blob/main/img/img-cpu-scheduling.JPG"/>
</p>

**Results**:
- **Priority Scheduling**: Effective for real-time systems but may cause starvation for low-priority processes.
- **Round Robin**: Ensures fairness but requires optimal time quantum tuning.

---

#### 2. Page Replacement Algorithm

This section implements three page replacement strategies:
1. **First-In-First-Out (FIFO)**: Replaces the oldest page.
2. **Least Recently Used (LRU)**: Replaces the least recently accessed page.
3. **Optimal (OPT)**: Replaces the page not used for the longest time.

<p align="center">
  <img src="https://github.com/ar-sayeem/Operating-System/blob/main/img/img-page-replacement.JPG" alt="Page Replacement Algorithm"/>
</p>

**Results**:
- **OPT**: Minimizes page faults but impractical due to its predictive nature.
- **LRU**: Outperforms FIFO in reuse-heavy scenarios.
- **FIFO**: Simple but may struggle with older pages still in use.

---

#### 3. Banker's Algorithm

A method to avoid deadlocks in systems by ensuring safe resource allocation.

**Steps**:
1. Calculate the **Need Matrix**: Subtract allocated resources from maximum required resources.
2. Determine the **Safe Sequence**: Verify if resource allocation keeps the system in a safe state.

<p align="center">
  <img src="https://github.com/ar-sayeem/Operating-System/blob/main/img/img-banker's-algo.JPG" alt="Banker's Algorithm"/>
</p>

**Results**:
- Ensures deadlock avoidance but requires predefined resource limits, limiting flexibility in dynamic systems.

---

## Conclusion

### Linux Commands
A robust toolkit for efficient command-line operation.

### Operating System Algorithms
- **CPU Scheduling**: Priority Scheduling excels in critical tasks; Round Robin is fair with careful tuning.
- **Page Replacement**: OPT is ideal; LRU offers practical performance; FIFO is straightforward but may lag.
- **Banker's Algorithm**: Effective for deadlock avoidance in static resource environments.
