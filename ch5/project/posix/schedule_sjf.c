#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "cpu.h"
#include "task.h"
#include "list.h"
#include "schedulers.h"

static struct node* p_sjf;
static size_t s_task_count = 0;

void add(char *name, int priority, int burst) {
   printf("adding!\n"); 
   Task *t = malloc(sizeof(Task));
   t->name = name;
   t->tid = s_task_count++;
   t->priority = priority;
   t->burst = burst;
   insert(&p_sjf, t);
}

static void run_shortest_job() {
    size_t shortest_burst = -1;
    Task* shortest_job = NULL;
    struct node* temp = p_sjf;
    while (temp != NULL) {
        if ((unsigned)temp->task->burst < shortest_burst) {
            shortest_burst = temp->task->burst;
            shortest_job = temp->task;
        }
        temp = temp->next;
    }

    if (shortest_job) {
        run(shortest_job, shortest_job->burst);
        delete(&p_sjf, shortest_job);
    }
}

void schedule() {
    while (p_sjf != NULL) {
        run_shortest_job();
    }
}

void sjf_traverse() {
    traverse(p_sjf);
}
