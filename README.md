# Philosophers
In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes

Overview
Here are the things you need to know if you want to succeed this assignment:
• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
• There are also forks on the table. There are as many forks as philosophers.
• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
• Every philosopher needs to eat and should never starve.
• Philosophers don’t speak with each other.
• Philosophers don’t know if another philosopher is about to die.
• No need to say that philosophers should avoid dying!

The task is to write a program that simulates the dining philosophers problem, which involves a number of philosophers sitting at a table and alternately thinking and eating. The program should comply with the following rules:

Global variables are not allowed.
The program should take the following arguments:
number_of_philosophers: The number of philosophers and forks.
time_to_die: The time (in milliseconds) it takes for a philosopher to die if they haven't eaten.
time_to_eat: The time (in milliseconds) it takes for a philosopher to eat while holding two forks.
time_to_sleep: The time (in milliseconds) a philosopher spends sleeping.
[number_of_times_each_philosopher_must_eat]: Optional argument specifying the number of times each philosopher must eat before the simulation stops. If not specified, the simulation stops when a philosopher dies.
Each philosopher is assigned a number from 1 to number_of_philosophers.
Philosopher 1 sits next to philosopher number number_of_philosophers, and any other philosopher N sits between philosopher N-1 and philosopher N+1.
Regarding program logs:

State changes of a philosopher should be formatted with a timestamp and the corresponding action (e.g., taking a fork, eating, sleeping, thinking, or dying).
Each state message should be displayed separately.
The announcement of a philosopher's death should be displayed no more than 10 ms after the actual time of death.
Data races should be avoided, ensuring thread safety.
The mandatory part of the program must adhere to the following additional rules:

Each philosopher should be implemented as a thread.
There should be one fork between each pair of philosophers. If there is only one philosopher, there should be only one fork on the table.
Mutexes should be used to protect the state of each fork and avoid duplication.
These rules define the requirements for implementing the dining philosophers problem, including thread management, fork allocation, and proper logging of philosopher actions and deaths.
