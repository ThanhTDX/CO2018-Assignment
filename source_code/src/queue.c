#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	

	//if queue is empty, automatically assign the process
	if (empty(q)) 
	{
		q->proc[0] = proc;
		q->size += 1;
		return;
	}

	//Holding
	while (q->size >= MAX_QUEUE_SIZE);
	
	//Finding index to put process (PS with FIFO)
	q->size += 1;
	for (int index = q->size - 1; index > 0; index--)
	{
		//Check if the priority of index i-1 is lower than index
		//So that when that process is done, proc will be the next process
		if (q->proc[index-1]->priority <= proc->priority)
		{
			q->proc[index] = proc;
			break;
		}
		//Else shift right
		else
			q->proc[index] = q->proc[index-1];
		//When every process is shifted right, proc[0] = proc
		if (index == 1)
			q->proc[0] = proc;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (empty(q)) return NULL;
	struct pcb_t *proc = q->proc[0];

	//Shifting processes to the left
	for (int i = 0; i < q->size - 1; i++)
	{
		q->proc[i] = q->proc[i+1];
	}
	q->size -= 1;
	return proc;
}

