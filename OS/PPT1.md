What is an OS?
    like a govt, it performs no useful functions by itself and just provides and env within which other programs can do useful work.

    The OS provides proper means for proper use of the resources such as hardware, software and data in the operation of a computer system.

    Its like an intermediary program between user(s) and the computer hardware.

    #GOALS:
        1. Execute user programs and make solving problems easier.
        2. Make the computer system //convenient// to use.
        3. Use the computer hardware in an //efficient// manner.


Computer System Structure-
    1. Hardware-    
        Provides basic computing resources.
        ex- CPU, Memory, I/O devices.
    2. OS-  
        controls and coordinates use of h/w among 
        various applications and users.
    3. Application Programs-    
        define the way in which system 
        resources are used to solve the computing problems of users.
    4. Users- 
        People, machines, other computers etc.

What Operating System do?

    1. Convenience 
    2. Resource allocation and control program

Kernel-
    The one program running at all instances in a computer is the kernel part of OS.
    Everything else is either System Program(ships with OS but not kernel) or Application Program(all programs not associated with OS).

Middleware-
    A set of software frameworks that provide additional services such as databases, multimedia, graphics etc.

Computer System Organization-
    Operation-
        One or more CPUs, device controllers connect through common bus providing access to shared memory.

        I/O devices and CPU can execute concurrently.

        A device controller is a system that handles the incoming and outgoing signals of the CPU by acting as a bridge between CPU and the I/O devices. 

        A device controller's local buffer is a temporary storage area for data. The CPU moves data between the local buffer and the main memory using the system bus, which is a collection of wires that allows data to be sent.

        Each device controller is in charge of a particular device type.

        Each device controller has a local buffer.

        Each device controller has a OS Device Driver to manage it.

        CPU moves data from/to main memory to/from local buffers.

        I/O is from device to local buffer of controller.
            (1. The device (e.g., a hard drive) has data to send to the computer.
            2. This data is first transferred to the local buffer of the device's controller.
            3. The data waits in this buffer until the controller can transfer it to the computer's main memory.)

        Device controller informs CPU that it has finished its operation by causing an interrupt.

