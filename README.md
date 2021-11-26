# Projet1AInfoFiles
Projet d'informatique 1A Files d'attente

| Module    | Function                    | Description     |
| :---      |    :----:                   |          ---:   |
| stack.h   | <struct> Stack : {Stack * next, Raw * data}       | Stack structure   |
| stack.h   | void pop_stack(Stack ** s)        | Pops top stack element      |
| stack.h   | void push_stack(Stack ** s, Raw * r)       | pushes r to stack top |
| stack.h   | int size_stack(Stack ** s)      | Returns stack size      |
| stack.h   | void print_stack(Stack ** s)      | prints stack elements      |
| :---      |    :----:   |          ---: |
| queue.h   | <struct> Queue : {Queue * next, Raw * data}       | Queue structure   |
| queue.h   | void pop_queue(Queue ** q, Stack ** s)        | Pops top element and pushes it onto Stack s|
| queue.h   | void push_queue(Queue ** q, Raw * r)       | pushes r to queue bottom |
| queue.h   | void print_queue(Queue ** q)      | prints queue elements      |
| :---      |    :----:   |          ---: |
| data.h    | <struct> Raw : {id : Id, day : Day, at : Arrival time, st : Service begin time, et : End time}       | Raw data structure, all types are int here   |
| data.h    | <struct> Processed : {mean_s, max_s, client_total, angry_client, mean_service_time}       | Processed data structure, all types are int here|
| data.h    | void print_raw(Raw * r)| Prints *r elements|
| data.h    | void print_processed(Processed * p)| Prints *p elements|
| :---      |    :----:   |          ---: |
| save.h    | void save_raw(char * fname, Stack ** s)       | Save Stack (Raw) elements to fname (.txt file)   |
| save.h    | void save_processed(char * fname, Processed * data)    | Save Processed p (/!\ p is a single element) elements to fname (.txt file)|
| save.h    | void load_raw(char * fname, Stack ** s) | load fname (.txt file) to the Stack s |
| save.h    | /!\ .txt format : "%d %d %d %d %d\n". If it's a Raw data file it may contain few lines|
| :---      |    :----:   |          ---: |
