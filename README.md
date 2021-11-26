# Projet1AInfoFiles
Projet d'informatique 1A Files d'attente - DAVAL Quentin - HUBINET Benjamin - 2021

## Quick references :

> ⚠️ **.txt format : ``` "%d %d %d %d %d\n" ```. If it's a Raw data file it may contain few lines.**

| Module    | Function or Structure                   | Description     |
| :---      |    :----:                   |          ---:   |
| stack.h   | ```struct Stack : {Stack * next, Raw * data}```       | Stack structure   |
| stack.h   | ```void pop_stack(Stack ** s)```       | Pops top stack element      |
| stack.h   | ```void push_stack(Stack ** s, Raw * r)```       | Pushes r to top stack |
| stack.h   | ```int size_stack(Stack ** s)```      | Returns stack size      |
| stack.h   | ```void print_stack(Stack ** s)```      | Prints stack elements      |
| :---      |    :----:   |          ---: |
| queue.h   | ```struct Queue : {Queue * next, Raw * data}```       | Queue structure   |
| queue.h   | ```void pop_queue(Queue ** q, Stack ** s)```        | Pops top element and pushes it onto Stack s|
| queue.h   | ```void push_queue(Queue ** q, Raw * r)```       | Pushes r to queue bottom |
| queue.h   | ```void print_queue(Queue ** q)```      | Prints queue elements      |
| :---      |    :----:   |          ---: |
| data.h    | ```struct Raw : {id : Id, day : Day, at : Arrival time, st : Service begin time, et : End time}```       | Raw data structure, all types are int here   |
| data.h    | ```struct Processed : {mean_s, max_s, client_total, angry_client, mean_service_time}```       | Processed data structure, all types are int here|
| data.h    | ```void print_raw(Raw * r)```| Prints *r elements|
| data.h    | ```void print_processed(Processed * p)```| Prints *p elements|
| :---      |    :----:   |          ---: |
| save.h    | ```void save_raw(char * fname, Stack ** s)```       | Saves Stack elements **(Raw type elements)** to fname (.txt file)   |
| save.h    | ```void save_processed(char * fname, Processed * data)```    | Saves Processed p elements ⚠️(p is a **single** element) to fname (.txt file)|
| save.h    | ```void load_raw(char * fname, Stack ** s)``` | Loads fname (.txt file) to the Stack s |
| :---      |    :----:   |          ---: |
