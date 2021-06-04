#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if(q->size == MAX_QUEUE_SIZE) return;
	else{
		q->size++;
		q->proc[MAX_QUEUE_SIZE] = proc;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	struct pcb_t * result = q->proc[0];
	for(int i = 1; i < q->size; i++){
		q->proc[i-1] = q->proc[i];
	}
	free(q->proc[q->size-1]);
	q->size--;
	return result;
	
}

