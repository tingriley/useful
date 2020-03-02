#include<cstdio>
#include<cstring>
using namespace std;

#define MAX_TASK 100

typedef void (*callback_function)(void);
template<class p_type, int size>

class task_info{
    public:
        p_type callback;
        char string[size];
};


class task_queue{
    public:
        task_queue(){
            w_idx = 0;
            r_idx = 0;
            pending_task = 0;
        }

        task_info<callback_function, 100> queue[MAX_TASK];
        int w_idx;
        int r_idx;
        int pending_task;
};


task_queue tq;

void push_task_to_queue(callback_function ptr, char * task_string){
    if(tq.pending_task < MAX_TASK){
        tq.queue[tq.w_idx].callback = ptr;
        strcpy(tq.queue[tq.w_idx].string,  task_string);
        tq.w_idx++;
        tq.pending_task++;

        printf("push %s\n", task_string);
    }
    else{
        printf("Task queue is full\n");
    }
}


task_info<callback_function, MAX_TASK> pop_task_from_queue(){
    task_info<callback_function, 100> task;
    if(tq.pending_task){
        tq.pending_task--;
        task = tq.queue[tq.r_idx++];
        printf("pop %s\n", task.string);
    }
    else{
        printf("Task queue is empty\n");
    }
        return task;
}


void test(){
    printf("TEST\n");
}


int main(){
    push_task_to_queue(test, "1st callback");
    push_task_to_queue(test, "2nd callback");
    task_info<callback_function, MAX_TASK> t;
    int pending = tq.pending_task;
    for(int i = 0; i < pending+1; i++){
        t = pop_task_from_queue();
        t.callback();
    }
    return 0;
}

