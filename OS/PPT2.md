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
