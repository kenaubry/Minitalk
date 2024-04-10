# Minitalk
# Data exchange program using UNIX signals

Minitalk no bitwise :

* Uses MALLOC to store each character of the message translated into binary in a string

Minitalk :

* Doesn't manipulate memory, only uses of bitwise to send messages between a client and a server.
* Some resources for bitwise : 
  - https://en.wikipedia.org/wiki/Bitwise_operation
  - https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
                   
Natives functions used :

* malloc (allocate memory)
* kill (send signal to a process)
* usleep (suspend execution for microsecond intervals)
* getpid (get process identification)
* signal (signal handling)
* pause (wait for signal)
