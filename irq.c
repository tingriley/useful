#include<stdio.h>
#include<string.h>

#define MAX_TASK 100
typedef void (*callback_function)(void);
typedef struct task{
    callback_function callback;
    char task_string[100];
} task_t;

task_t task_queue[MAX_TASK];

int w_idx = 0;
int r_idx = 0;
int pending_task = 0;


void push_task_to_queue(callback_function ptr, char * task_string){
    if(pending_task == MAX_TASK){
        printf("Task Queue is full!!\n");
    }
    else{
        task_queue[w_idx].callback = ptr;
        memcpy(task_queue[w_idx].task_string, task_string, strlen(task_string));
        w_idx++;
        pending_task++;

        printf("push %s\n\n", task_string);
    }
}

task_t pop_task_from_queue(){
    task_t t = {.callback=NULL, .task_string = ""};
    if(pending_task){
        pending_task--;
        t = task_queue[r_idx++];
        printf("pop %s\n", t.task_string);
    }
    else{
        printf("Task Queue is empty!!\n");
    }
    return t;
}

void first_callback(){
    printf("execute %s\n\n", __FUNCTION__);
}

void second_callback(){
    printf("execute %s\n\n", __FUNCTION__);
}

void third_callback(){
    printf("execute %s\n\n", __FUNCTION__);
}

void execute_task(){
    task_t t = pop_task_from_queue();
    t.callback();
}

int main(){
    push_task_to_queue(first_callback, "1st call back"); 
    push_task_to_queue(second_callback, "2nd call back"); 
    push_task_to_queue(third_callback, "3rd call back"); 

    int pending = pending_task;
    for(int i = 0; i < pending; i++){
        execute_task();
    }

    return 0;
}

