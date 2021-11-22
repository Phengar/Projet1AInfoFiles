// Queue Structure
typedef struct {
	struct node * next;
	int id;
} Queue;

void push(Queue ** q, int offset);

void pop(Queue ** q, char * fname);

void print(Queue ** q);
