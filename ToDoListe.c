#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LETTERS 512
int taskCount = 0;
int completedTasks= 0;

struct TODOLIST {
    char Tasks[MAX_LETTERS];
    int completed; // done = 1 , not-done = 0
};

void addTask(struct TODOLIST tasks[MAX_TASKS]) {
    int numberOfTasks;
    printf("How much of tasks do you want to add ?\n");
    scanf("%d" , &numberOfTasks);
    getchar();
    int i;
    for (i = 0 ; i < numberOfTasks ; i++) {
        printf("Enter task %d : \n  " , i + 1);
        fgets(tasks[i].Tasks , MAX_LETTERS , stdin);
        tasks[i].completed = 0;
        taskCount++;
        tasks[i].Tasks[strcspn(tasks[i].Tasks , "\n")] = '\0';
    }
}

int showTasks(struct TODOLIST tasks[MAX_TASKS]) {
    char choose;
    int i;
    int num = 0;
    char done;
    if (taskCount == 0) {
        printf("You don't any tasks");
    } else {
        printf("What do you want to show ?\n  a- Completed tasks.\n  b- Incompleted tasks.\n  c- All tasks.\n");
        scanf("%c" , &choose);
        if (choose == 'a') {
            printf("Your completed tasks :\n");
            for (i = 0 ; i < taskCount ; i++) {
                num++ ;
                if (tasks[i].completed == 1) {
                    if (completedTasks == 0) {
                        printf("You don't complate any task .");
                    } else {
                        printf("     %d : %s.\n" ,num , tasks[i].Tasks);
                    }
                }
            }
        } else if (choose == 'b') {
            printf("Your incomplet tasks :\n");
            for (i = 0 ; i < taskCount ; i++) {
                num++ ;
                if (tasks[i].completed == 0) {
                    printf("     %d : %s.\n" , num , tasks[i].Tasks);
                }
            }
        } else if (choose == 'c') {
            printf("You all tasks : \n");
            for (i = 0 ; i < taskCount ; i++) {
                num++;
                if (tasks[i].completed == 0) {
                    done = 'a' ;
                } else if (tasks[i].completed == 1) {
                    done = 'b';
                }
                printf("     %d : %s . %c \n" , num , tasks[i].Tasks , done);
            }
        }
        
    }
    return 1;
}

int main() {
    struct TODOLIST todolist[MAX_TASKS];
    int choice;
    
    do {
        printf("\n==========Tasks==========\n");
        printf(" 1-   Add  Tasks.\n");
        printf(" 2-   Show Tasks.\n");
        printf(" 3-   Edit Tasks.\n");
        printf(" 4-   Exit.\n");
        printf("Enter number of what do you want : ");
        scanf("%d" , &choice);
        getchar();

        if (choice == 1) {
            addTask(todolist);
        } else if (choice == 2) {
            showTasks(todolist);
        } else if (choice == 3) {
            printf("%d" , choice);
        } else if (choice == 4) {
            printf("You are exit.");
            break;
        }
    } while (choice != 4);

    return 0;
}