User Mode vs Kernel Mode-
    1. Privileges: User mode is restricted and limited, while kernel mode has full access and control over the system.
    2. Purpose: User mode is for running user applications, whereas kernel mode is for executing core OS functions.
    3. Protection: User mode operations are isolated from the system’s core, reducing the risk of damage. Kernel mode operations have no such isolation, which is why careful management is essential.
    4. Error Handling: Errors in user mode generally only affect the running process, whereas errors in kernel mode can have system-wide consequences.

Kernel-
    The core part of an OS, manages system resources and provides essential services.

Operating system operations-
    1. Bootstrap program-
        Simple code to initialize the system, load the kernel.
    2. Kernel Loads
    3. Starts system daemons(services provided outside of the kernel).
    4. Kernel interrupt drivenoperation(h/w and s/w)-
        a. Hardware interrupt by one of the devices.
        b. Software interrupt(exception or trap)
            1. software error(divided by zero)
            2. request for OS service- system call
            (When a system call is made, it intentionally triggers a trap to transition from user mode to kernel mode, where the operating system can safely execute privileged instructions. This trap is a controlled way for the OS to take over execution and perform the requested service.)
            3. Others are infinite loops and stuff


Evolution of Operating Systems-

### 1.Simple Batch System
- **Definition**: A Simple Batch System is an early type of operating system that executes batches of jobs without direct interaction with the user.
  
### Key Features
- **Job Collection**: Jobs (tasks or programs) are collected into batches, which are then processed sequentially.
- **No Direct Interaction**: Users submit jobs to the system, often using punch cards or similar input methods, and cannot interact with the jobs during execution.
- **Job Scheduling**: Jobs are scheduled and executed one after another, typically in the order they are received (first-come, first-served).
- **Single Stream**: Only one job runs at a time, utilizing the entire CPU until it completes or requires I/O.
- **CPU Utilization**: Early batch systems aimed to keep the CPU busy by automatically moving to the next job when a current job was waiting for I/O operations.
- **Turnaround Time**: Often high due to waiting in the job queue and the lack of prioritization.

### Advantages
- **Simplified Operation**: Easy to implement and manage, with straightforward job scheduling.
- **Maximizes CPU Usage**: Reduces idle time of the CPU by automatically processing the next job when possible.

### Disadvantages
- **Long Turnaround Time**: Users experience delays as jobs are processed sequentially, and there’s no immediate feedback.
- **No Interaction**: Lack of interactivity means users must wait until the entire job completes to see results or correct errors.
- **Inefficient Resource Use**: Not optimal for resource utilization as each job has the entire system’s resources, even when not fully needed.

### Examples
1. IBM OS/360  
2. GM-NAA I/O  
3. Compatible Time-Sharing System (CTSS)  
4. Atlas Supervisor





### 2.Multiprogramming Systems

Multiprogramming systems are an advanced type of operating system designed to improve the utilization of the CPU by allowing multiple programs to be loaded into memory and executed simultaneously. Here are the key points:

### Key Features
- **Multiple Programs in Memory**: Multiple programs are kept in memory at the same time, and the CPU switches between them to maximize utilization.
- **Concurrent Execution**: The system manages the execution of multiple programs, ensuring that the CPU is never idle by executing another program when the current one is waiting for I/O operations.
- **Job Scheduling**: The operating system uses scheduling algorithms to determine which program to execute next, based on factors like priority and resource availability.
- **Resource Sharing**: Programs share system resources like memory, CPU, and I/O devices, managed by the OS to prevent conflicts and ensure efficiency.
- **Improved CPU Utilization**: By keeping the CPU busy with multiple tasks, multiprogramming systems significantly increase overall system efficiency.

### Advantages
- **Increased Throughput**: More jobs are processed in less time, as the CPU efficiently switches between tasks.
- **Reduced Idle Time**: The CPU is kept busy almost constantly, minimizing idle time and improving overall performance.
- **Better Resource Utilization**: Multiprogramming maximizes the use of system resources, including memory and I/O devices.

### Disadvantages
- **Complexity**: Managing multiple programs and resources requires sophisticated scheduling and memory management algorithms.
- **Potential for Resource Contention**: Multiple programs can compete for limited resources, leading to potential conflicts or bottlenecks.
- **Security and Isolation**: Ensuring that programs do not interfere with each other or access unauthorized resources adds to the system’s complexity.

### Examples of Multiprogramming Systems
- **IBM OS/360** (later versions)
- **UNIX**
- **Multics**

Multiprogramming systems were a significant step forward in operating system design, paving the way for more advanced concepts like multitasking and time-sharing, which further enhanced system performance and user interaction.






### 3.Time-Sharing Systems

Time-sharing systems are a type of operating system that allows multiple users to interact with a computer system simultaneously, sharing its resources effectively and providing each user with the impression of having their own dedicated machine. Here's an overview:

### Key Features
- **Multi-User Interaction**: Supports multiple users who can access the system concurrently, often via terminals.
- **Time Slicing**: The CPU time is divided into small time slices, and each active user or process gets a slice in turn, giving the appearance of simultaneous execution.
- **Rapid Context Switching**: The system rapidly switches between processes, maintaining the state of each process and resuming it during its next time slice.
- **Interactive Use**: Designed for interactive tasks, allowing users to input commands and receive immediate feedback, which is ideal for applications like text editing, calculations, and file management.
- **Resource Allocation**: Manages resources dynamically, ensuring fair distribution among all active users and processes to prevent any single process from monopolizing the system.

### Advantages
- **Improved User Experience**: Users feel like they have their own dedicated system, enhancing productivity and responsiveness.
- **Efficient Resource Utilization**: Maximizes CPU and resource usage by keeping the system busy with multiple interactive tasks.
- **Reduced Idle Time**: Minimizes idle time as the system constantly switches between tasks, keeping the CPU and other resources in use.
- **Job Prioritization**: Allows prioritization of tasks, ensuring that critical or high-priority processes get more CPU time if needed.

### Disadvantages
- **Complexity in Scheduling**: Requires sophisticated scheduling algorithms to manage multiple users and processes efficiently.
- **Overhead from Context Switching**: Frequent switching between tasks can introduce overhead, slightly reducing overall performance.
- **Resource Contention**: Multiple users may compete for limited resources, potentially leading to slowdowns or contention issues.

### Examples of Time-Sharing Systems
- **UNIX**: One of the most popular time-sharing systems, used widely in academic and business environments.
- **MULTICS (Multiplexed Information and Computing Service)**: An early and influential time-sharing system that introduced many key concepts used in modern operating systems.
- **DEC TOPS-10**: A time-sharing system developed by Digital Equipment Corporation, widely used on PDP-10 mainframe computers.
- **CTSS (Compatible Time-Sharing System)**: One of the first time-sharing systems, developed at MIT, which laid the groundwork for subsequent systems.

Time-sharing systems revolutionized computing by making powerful computing resources accessible to multiple users, enhancing productivity and paving the way for the development of modern interactive operating systems.






### 4.Parallel Systems
Parallel systems involve multiple processors working together within a single machine to perform tasks simultaneously, enhancing performance and speed. Here's a summary:

#### Key Features
- **Multiple Processors**: Uses multiple CPUs or cores within the same computer system.
- **Shared Memory**: Processors typically share the same memory space, allowing for easy data communication and synchronization.
- **Tight Coupling**: Processors are tightly coupled, often on the same motherboard, with fast interconnections.
- **Concurrent Execution**: Tasks are divided and executed simultaneously across multiple processors, improving speed and efficiency.
- **Used For**: High-performance computing tasks like scientific simulations, complex calculations, and real-time processing.

#### Advantages
- **Increased Speed**: Parallel execution reduces the time required for complex computations.
- **Resource Efficiency**: Maximizes the utilization of system resources like CPU, memory, and I/O.
- **Scalability**: Can be scaled by adding more processors or cores to enhance performance.

#### Disadvantages
- **Complex Programming**: Writing software to effectively utilize multiple processors can be complex.
- **Synchronization Issues**: Requires careful handling of shared resources to avoid conflicts and ensure correct results.

#### Examples
- **Supercomputers**: Systems like IBM Blue Gene, Cray systems.
- **Multi-core Processors**: Modern CPUs with multiple cores that handle parallel tasks.






### 5.Distributed Systems
Distributed systems consist of multiple independent computers (nodes) that work together over a network to achieve a common goal. These systems operate in a loosely coupled manner.

#### Key Features
- **Multiple Independent Nodes**: Systems are composed of different computers that communicate via a network.
- **Distributed Memory**: Each node has its own memory, and communication between nodes is done through message passing.
- **Loose Coupling**: Nodes are loosely connected, often geographically dispersed, with communication via network protocols.
- **Scalability and Fault Tolerance**: Can easily scale by adding more nodes and offer better fault tolerance as failure of one node doesn’t bring down the entire system.
- **Used For**: Applications like cloud computing, distributed databases, and global web services.

#### Advantages
- **Scalability**: Easily scaled by adding more nodes, providing flexibility in handling increasing loads.
- **Fault Tolerance**: System can continue functioning even if some nodes fail, improving reliability.
- **Resource Sharing**: Enables sharing of resources like storage, processing power, and data across multiple nodes.

#### Disadvantages
- **Complexity**: More complex to design, implement, and maintain due to issues like network latency, data consistency, and synchronization.
- **Security**: Distributed nature makes it more vulnerable to security breaches and requires robust security measures.

#### Examples
- **Internet**: The largest distributed system, connecting millions of computers worldwide.
- **Hadoop**: A distributed computing framework used for large-scale data processing.
- **Google’s Search Engine**: Uses distributed computing across thousands of servers to deliver search results efficiently.






### 6.Real-Time Systems

Real-time systems are operating systems designed to process data and provide outputs within a guaranteed time frame, suitable for applications that require immediate or predictable responses.

### Key Features
- **Deterministic Response**: Real-time systems guarantee responses within a defined time limit, which is critical for time-sensitive applications.
- **Task Prioritization**: Tasks are prioritized, ensuring that high-priority tasks get immediate attention.
- **Minimal Latency**: The system is optimized for minimal latency to ensure timely task execution.
- **Reliability and Predictability**: Ensures consistent and predictable behavior, which is essential for applications where timing is critical.

### Types of Real-Time Systems
1. **Hard Real-Time Systems**:
   - **Definition**: Systems where missing a deadline is unacceptable and could lead to catastrophic consequences.
   - **Examples**: Airbag control systems in cars, medical devices like pacemakers, and industrial control systems.
   
2. **Soft Real-Time Systems**:
   - **Definition**: Systems where deadlines are important but not absolutely critical, and occasional deadline misses can be tolerated without severe consequences.
   - **Examples**: Video streaming, online gaming, and multimedia applications.

### Advantages
- **Timeliness**: Guarantees task completion within specified time limits, making it ideal for critical applications.
- **Predictability**: Offers consistent performance, crucial for applications where timing is a strict requirement.
- **Reliability**: High reliability and availability, often required in safety-critical systems.

### Disadvantages
- **Complexity**: Developing and maintaining real-time systems is complex due to the need for precise timing and resource management.
- **Limited Flexibility**: Real-time constraints can limit the flexibility of the system in handling unexpected workloads or varying task demands.
- **Resource Intensive**: Requires careful management of resources to meet timing constraints, which can be resource-intensive and costly.

### Applications
- **Industrial Automation**: Control systems for manufacturing processes, robotics, and assembly lines.
- **Embedded Systems**: Systems embedded within consumer electronics, automotive control units, and medical devices.
- **Telecommunications**: Systems that handle real-time data transmission, such as call processing in telephony.
- **Aerospace and Defense**: Flight control systems, missile guidance, and radar processing systems.

### Examples of Real-Time Operating Systems (RTOS)
- **VxWorks**: Widely used in embedded systems, aerospace, and automotive industries.
- **RTLinux**: A real-time variant of the Linux operating system for applications requiring deterministic responses.
- **QNX**: Known for its microkernel architecture, often used in automotive and industrial applications.

### Summary
Real-time systems are essential for applications where timing and predictability are critical. They are designed to process inputs and provide outputs within strict time constraints, ensuring that tasks are completed reliably and on time. These systems are used extensively in industries where safety, efficiency, and responsiveness are paramount.






### What does virtual memory do?

### Virtual Memory in Operating Systems

Virtual memory is a memory management technique that creates an illusion of a large, contiguous memory space for applications, even if the physical memory (RAM) is limited. It enables systems to handle more processes and larger programs efficiently. Here's how it works and what it does:

### Key Functions

1. **Extended Address Space**:
   - **Definition**: Provides applications with a large, continuous address space that exceeds the actual physical memory available.
   - **Benefit**: Allows programs to use more memory than physically installed, improving the ability to run large applications or multiple applications simultaneously.

2. **Paging and Segmentation**:
   - **Paging**: Divides the virtual address space into fixed-size pages and maps them to physical memory frames. This enables efficient use of memory and simplifies memory management.
   - **Segmentation**: Divides memory into variable-sized segments, each representing different logical units of a program, such as code, data, or stack.

3. **Swapping**:
   - **Definition**: Moves data between physical memory and a storage device (usually a hard disk or SSD) when physical memory is full.
   - **Benefit**: Allows the system to handle more processes than can fit into physical memory by temporarily storing less frequently used data on disk.

4. **Isolation and Protection**:
   - **Definition**: Provides each process with its own virtual address space, isolating it from other processes.
   - **Benefit**: Protects processes from interfering with each other and prevents unauthorized access to memory.

5. **Efficient Memory Utilization**:
   - **Definition**: Utilizes physical memory more efficiently by only loading necessary pages or segments into RAM and keeping the rest on disk.
   - **Benefit**: Optimizes the use of physical memory and reduces the likelihood of running out of RAM.

### Advantages

1. **Increased Flexibility**:
   - **Application Size**: Applications can be larger and more complex since they are not limited by physical memory constraints.
   - **Multiple Applications**: Multiple applications can run simultaneously without requiring each to fit entirely into physical memory.

2. **Improved System Stability**:
   - **Isolation**: Processes are isolated from each other, which helps prevent one process from crashing or corrupting another.
   - **Security**: Improves security by preventing unauthorized access to memory spaces of other processes.

3. **Simplified Memory Management**:
   - **Abstraction**: Simplifies programming by providing a uniform address space and managing the details of physical memory allocation.

### Disadvantages

1. **Performance Overhead**:
   - **Swapping Costs**: Moving data between physical memory and disk can introduce latency and reduce system performance.
   - **Page Faults**: Frequent page faults (when the system must retrieve data from disk) can slow down performance.

2. **Disk Space Usage**:
   - **Storage Requirements**: Requires sufficient disk space to store the swapped-out data, which can be a concern for systems with limited storage capacity.

### Examples

- **Modern Operating Systems**: Most contemporary operating systems, such as Windows, Linux, and macOS, use virtual memory techniques to manage system memory efficiently.

### Summary

Virtual memory enhances an operating system's capability by allowing applications to use more memory than physically available, improving system stability, and providing better isolation and protection between processes. While it introduces some performance overhead due to swapping and additional management, the benefits in terms of flexibility and efficient memory utilization make it a fundamental component of modern operating systems.



### Dual Mode Operation- 

Dual mode operation allows OS to protect itself and other system components.
1. User Mode   
2. Kernel Mode

# Mode Bit-
    Its provided by the hardware.
    Provides ability to distinguish between when the user code is running and when the kernel code is running.
    a. User code running -> mode bit is "user"(1)
    b. kernel code running -> mode bit is "kernel"(0)

System call changes mode to kernel, return from call and resets to user.







### Process Management-

1. A process is a program in execution.
    Program- Passive entity.
    Process- Active entity.
2. Process needs resources to accomplish its task-
    CPU, memory, I/O, Files
    Initialization data
3. Process termination requires reclaim of any reusable resources.

4. Single threaded process has one program counter(PC) specifying the location of next instruction to br=e executed.

5. Multi-threaded has one Program counter per thread.

6. Typically, system has many processes. 
    a. some User
    b. some OS running concurrently on one or more CPU.







### Process Management Activities

OS is responsible for these activities-

1. Creating/deleting both user and system processes.
2. Suspending and resuming processes.
3. Providing mechanisms for process synchronization.
4. Providing mechanisms for process communication.
5. Providing mechanisms for deadlock handling.
