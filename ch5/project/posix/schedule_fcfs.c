#include <stdio.h>
#include <stdlib.h>
#include "schedulers.h"
#include "list.h"
#include "cpu.h"

static struct node* p_fifo;
static size_t s_task_count = 0;

static void schedule_cb(Task* t) {
    run(t, t->burst);
    delete(&p_fifo, t);
}

void add(char *name, int priority, int burst) {
   printf("adding!\n"); 
   Task *t = malloc(sizeof(Task));
   t->name = name;
   t->tid = s_task_count++;
   t->priority = priority;
   t->burst = burst;
   insert(&p_fifo, t);
}

void schedule() {
   printf("scheduling!\n"); 
   traverse_cb(p_fifo, schedule_cb);
}

void fifo_traverse() {
    traverse(p_fifo);
}
