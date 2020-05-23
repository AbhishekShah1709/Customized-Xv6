# INTRODUCTION

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).xv6 loosely follows the structure and style of v6, 
but is implemented for a modern x86-based multiprocessor using ANSI C.

## ``` PRIORITY BASED ``` SCHEDULER

Priority scheduling is a method of scheduling processes based on priority.
In this method, the scheduler chooses the tasks to work as per the priority, 
which is different from other types of scheduling, for example, a simple
round robin.

Priority scheduling involves priority assignment to every process, and
processes with higher priorities are carried out first, whereas tasks with
equal priorities are carried out on a round robin basis. An example of a 
general-priority-scheduling algorithm is the shortest-job-first (SJF) algorithm.


## ``` FIRST-COME-FIRST-SERVE ``` SCHEDULER

In FCFS policy, the process which arrives first is executed first. It will work
best when incoming processes are short and there is no need for the processes to
execute in a specific order.


## ``` MULTILEVEL FEEDBACK QUEUE ``` SCHEDULING

In this policy 5 different types of queues are kept. The one having more CPU
burst time is pushed in the last priority queue which leaves behind interactive
processes in the top priority queues.If a process uses too much CPU time, it will
be moved to a lower-priority queue. Similarly, a process that waits too long in a 
lower-priority queue may be moved to a higher-priority queue.


## ``` waitx ``` SYSTEM CALL

``` waitx ``` system call returns the number of context switches performed from
 **RUNNING** to **WAITING** and number of context switches performed during the
 **RUNNING** state and total number of context switches.
 

## ``` chpr ``` SYSTEM CALL

``` chpr ``` system call sets the priority of the process and
returns the old priority of the process.


## ``` getpinfo ``` SYSTEM CALL

``` getpinfo ``` system call returns some basic information about each process: its process ID, 
total run time, how many times it has been chosen to run, which queue it is currently
on 0, 1, 2, 3 or 4 (check Task 2 part c) and ticks received in each queue.


## In defs.h
* Declared function for made syscalls waitx, setpriority, getpinfo.
* Added struct proc_stat.

## In proc.c
* Added function for syscalls waitx, setpriority, getpinfo.
* Added scheduling algorithms.
* Added required functions and struct to implement queue.
* Added iniatialise function in userinit function.
* Initialised struct proc variables in allocproc.
* Changed necessary variables for schduler implementation.
* Added queue no value in printf of procdump.

## In proc.h
* Added useful variables in struct proc.

## In syscall.h
* Added declaration of sys_waitx, sys_set_priority, sys_getpinfo.
* Added them in static int array syscalls.

## In syscall.h
* Added #define for SYS_waitx, SYS_set_priority, SYS_getpinfo.

## In sysproc.h
* Added functions sys_waitx, sys_set_priority, sys_getpinfo.

## In trap.c 
* Added necesarry variable for scheduler in trap function.

## In user.h
* Added declaration of function for syscalls waitx, setpriority, getpinfo.
* Declared struct proc_stat.

## In user.S
* Added definition for calling syscall waitx, setpriority, getpinfo.

## New files added
* benchmark.c
    * Run it by command benchmark <n>.
    * Open OS by setting appropriate value of scheduler variable. Then run benchmark.
    * It shows pid of creation time as it creates them and wait time and run time when ends them.

* fcfs.c
    * This is test for fcfs Scheduling.

* mlfq_test.c
    * This is test for MLFQ Scheduling.
* REPORT.pdf
    * This gives detailed comparison between different scheduling algorithm.
