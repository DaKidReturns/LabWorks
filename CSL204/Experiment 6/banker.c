#include<stdio>
//#include<>

int **
get_process(){
    
}

void main(){
    get_process();
    int *proc_list = get_safe_sequence();
    if (proc_list != NULL){
        print_sequence(proc_list);
    }
    else{
        printf("It is in a dead lock state.");
    }
}
