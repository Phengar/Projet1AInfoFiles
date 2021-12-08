# Projet1AInfoFiles
Projet d'informatique 1A Files d'attente - DAVAL Quentin - HUBINET Benjamin - 2021

## Structural choices
> As this project's purpose was to model a checkout line, which obviously is a modular structure. It is fair that we implemented a **Queue** like data structure from a linked list structure as for its modularity. A queue structure means that push are done towards queue tail and the queue pops affect queue head. Each node of the queue structure contains relevant data about a customer (i.e. : id : its unique Id, day : the current simulation day, at : its Arrival time, st : its Service begin time, et : its End time). All these datas are kept in a **Raw** structure. Moreover, we implemented a **Processed** data structure that gathers the simulation statistics, as in our opinion it was more relevant to hold them all in a single place (structure). Furthermore, as we could be asked to simulate the queue on a long period, it is mandatory to mind every memory access, especially writing in files. Thus we implemented a **Stack** structure which acts as some cache during the simulation, containing the previous days' clients. This structure actuates whenever a client is popped from the queue. As a consequence, the queue pop function takes in two arguments, a pointer on the **Queue** as well as a pointer on the **Stack**.
Once the simulation ends, the whole stack content is dumped in a .txt file.
And statistics are done and then displayed in the console.

## Modularity choices
> We tried to gather similar purpose functions in some .c/.h files, for reusability, clarity (quite mandatory in a group project). For instance 
- The random module : "*rand*" contains functions related to random number generation as well as a (crypto quality :p) seed generator
- *Stack* contains all functions acting on the **Stack** data structure : Push, pop, print, free, size
- *Queue* contains all functions acting on the **Queue** data structure : Push, pop (NB as stated earlier this func also acts on the stack), print, free, size
- *Data* regroups the definition of **Raw** and **Processed** data structures and print, free functions
- *Save* regroups functions that saves **Stack** contents, also we have tried to implement the possibility to use a raw data files in order to perform statistics later on. Unfortunately the function doesn't work as expected.

## Statistics analysis
> ICI
  
## Issues/ Problems
> We have tried to implement a function that could load a stack from a **Raw** data file, to later on perform some statistics with either some C function or program. Nonetheless, we have not been able to make this specific code work.

## Compiling and running the project
:warning: This project only compiles on a Linux system as the *rand* module function ```void getSeed()``` does a syscall : ```getrandom()``` in order to set a random generation seed.
Except that, it compiles under **gcc**
- Compiling :
```make main```
- Running :
```./main```

## Quick references :

> ⚠️ **.txt format : ``` "%d %d %d %d %d\n" ```. If it's a Raw data file it may contain few lines, compared to a Processed data file which contains a single line**
. In case of a **Raw** data file, you may encouter some -1 at the end of some rows, these values account for a client that has not been served.

| Module    | Function or Structure                   | Description     |
| :---      |    :----:                   |          ---:   |
| stack.h   | ```struct Stack : {Stack * next, Raw * data}```       | Stack structure   |
| stack.h   | ```void pop_stack(Stack ** s)```       | Pops top stack element      |
| stack.h   | ```void push_stack(Stack ** s, Raw * r)```       | Pushes r to top stack |
| stack.h   | ```int size_stack(Stack ** s)```      | Returns stack size      |
| stack.h   | ```void print_stack(Stack ** s)```      | Prints stack elements      |
| stack.h   | ```void free_stack(Stack ** s)```      | Frees stack from memory    |
| :---      |    :----:   |          ---: |
| queue.h   | ```struct Queue : {Queue * next, Raw * data}```       | Queue structure   |
| queue.h   | ```void pop_queue(Queue ** q, Stack ** s)```        | Pops top element and pushes it onto Stack s|
| queue.h   | ```void push_queue(Queue ** q, Raw * r)```       | Pushes r to queue bottom |
| queue.h   | ```void size_queue(Queue ** q)```      | Returns queue size     |
| queue.h   | ```void print_queue(Queue ** q)```      | Prints queue elements      |
| queue.h   | ```void free_queue(Queue ** q)```      | Frees queue from memory      |
| :---      |    :----:   |          ---: |
| data.h    | ```struct Raw : {id : Id, day : Day, at : Arrival time, st : Service begin time, et : End time}```       | Raw data structure, all types are int here   |
| data.h    | ```struct Processed : {mean_s, max_s, client_rate, client_both, mean_response_time}```       | Processed data structure, all types are int here|
| data.h    | ```void print_raw(Raw * r)```| Prints *r elements|
| data.h    | ```void print_processed(Processed * p)```| Prints *p elements|
| data.h    | ```void init_processed(Processed * p)```| Inits *p to a 0 vector|
| data.h    | ```void free_raw(Raw * r)```| Frees Raw from memory|
| data.h    | ```void free_processed(Processed * p)```| Frees Processed from memory|
| :---      |    :----:   |          ---: |
| save.h    | ```void save_raw(char * fname, Stack ** s)```       | Saves Stack elements **(Raw type elements)** to fname (.txt file)   |
| save.h    | ```void save_processed(char * fname, Processed * data)```    | Saves Processed p elements ⚠️(p is a **single** element) to fname (.txt file)|
| save.h    | ```void load_raw(char * fname, Stack ** s)```  - 🚧 **NOT WORKING**| Loads fname (.txt file) to the Stack s - 🚧 **NOT WORKING** |
| :---      |    :----:   |          ---: |
| rand.h    | ```void setSeed()```| Sets a random seed for proper random number generation|
| rand.h    | ```int random_int(int minserv, int maxserv)```| Generates a random integer between minserv and maxserv - uniform law|
| rand.h    | ```double random_unif()```| Generates a random number according the uniform law|
| rand.h    | ```double random_expo(double lamb)```| Generates a random value according the exponential law with a lambda of lamb|
| :---      |    :----:   |          ---: |
