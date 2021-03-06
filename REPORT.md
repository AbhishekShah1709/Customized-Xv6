##Report covering performance comparison between the default and 3 implemented policies

#DEFAULT :-

    Round Robin is used as default policy in xv6. In this policy, each process gets executed for certain ticks and then next process is executed for certain ticks and so on it continues till the end of the queue and then again it starts from the beginning. The benefit of this policy is that CPU is utilized optimally in this policy. The main benefit is that starvation doesn't occur because, for each round robin cycle, every process is given a fixed time to execute. So, no process is left behind.

    Disadvantage is that we can assign priority to the processes which is sometimes needed in certain scenarios.

#FCFS :-

    In FCFS policy, the process which arrives first is executed first. This policy works best when the processes arrive in the order of increasing CPU burst time.
    
    
    Disadvantage is that the process which has more CPU burst time arrives first then the process which arrive later and have very small CPU burst time suffer because they do not take much time to execute but still have to wait for a long time in the queue.

#PRIORITY :-

    In PRIORITY based policy the process having the least priority is executed first. This is advantageous in the sense that priority can be assigned to the processes in the order of their importance so that they can get executed accordingly. The priority of a process can be selected based on memory requirement or time requirement or user preference.

    Disadvantage of this policy is that a second policy is needed to decide if there are two processes having same priority.

#MULTILEVEL FEEDBACK QUEUE :-
    
    In this policy 5 different types of queues are kept. The one having more CPU burst time is pushed in the last priority queue which leaves behind interactive processes in the top priority queues. Advantage of this policy is that throughput is increased as the top priority queue contains the processes which requires minimum CPU time. 

    Disadvantage of the policy is that we need to check starvation condition for each process which takes time.


#COMPARISON :-

   The main disadvantage of Round Robin is that context switch occurs but that is anyway occuring in all other policies in xv6 OS. But, in Round Robin CPU is used most optimally so Round Robin is the best policy. 
