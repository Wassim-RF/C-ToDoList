#include <stdio.h>
#include <string.h>

// متغيرات ثابتة
#define MAX_TASKS 100 // عدد الأقصى للمهام
#define MAX_LETTERS 512 // عدد الحروف الأقصى في كل مهمة
// متغيرات نحتاجها في كل الكود و في معضم الدوال 
int taskCount = 0; // عدد المهام المسجلة بعد كل إضافة نظيف 1
int completedTasks = 0; // عدد المهام التي أنهيتها و عند الإنتهاء من مهمة نظيف 1
int incompletedTasks = 0; // عدد المهام الغير منجزة

// الهكل الخاص بالمهام
struct TODOLIST {
    char Tasks[MAX_LETTERS]; // المهمة
    int completed; // هل المهمة مكتملة أم لا إذا كان نعم تساوي 1 إذا لا تساوي 0
};
// دالة خاصة بإظافة مهمة
void addTask(struct TODOLIST tasks[MAX_TASKS]) {
    // إدخال عدد المهام التي يريد إضافتها
    int numberOfTasks;
    printf("How much of tasks do you want to add ?\n");
    scanf("%d" , &numberOfTasks);
    getchar();
    int i;
    // إدخال المهام 
    for (i = 0 ; i < numberOfTasks ; i++) {
        printf("Enter task %d : \n  " , i + 1);
        fgets(tasks[i].Tasks , MAX_LETTERS , stdin);
        tasks[i].completed = 0; // أدخل أن المهمة لم تنجز 
        taskCount++; // أضافة 1 لعدد المهام
        incompletedTasks++; // أظف 1 لعدد المهام الغير منجزة
        tasks[i].Tasks[strcspn(tasks[i].Tasks , "\n")] = '\0';
    }
}
// دالة خاصة بعرض المهام
int showTasks(struct TODOLIST tasks[MAX_TASKS]) {
    char choose;
    int i;
    int num = 0;
    char done;
    printf("You have :   %d tasks , %d completed tasks , %d incompleted tasks .\n" , taskCount , completedTasks , incompletedTasks);
    if (taskCount == 0) // إذا لم تكن سجلت أي مهمة
    {
        printf("You don't any tasks");
    } else // إذا كانت لديك مهام في الذاكرة
    {
        // اختيار ماذا تريد أن تفعل 
        printf("What do you want to show ?\n  a- Completed tasks.\n  b- Incompleted tasks.\n  c- All tasks.\n");
        scanf("%c" , &choose);
        if (choose == 'a') // إظهار المهام التي أنجزتها
        {
            printf("Your completed tasks :\n");
            for (i = 0 ; i < taskCount ; i++) {
                num++ ;
                if (tasks[i].completed == 1) // لو كانت المهمة منجزة
                {
                    if (completedTasks == 0) // إذا لم تنجز أي مهمة
                    {
                        printf("You don't complate any task .");
                    } else // إذا كنت أنهيت مهمة
                    {
                        printf("     %d : %s.\n" ,num , tasks[i].Tasks);
                    }
                }
            }
        } else if (choose == 'b') // أظهار المهام التي لم تنجزها
        {
            printf("Your incomplet tasks :\n");
            for (i = 0 ; i < taskCount ; i++) {
                num++ ;
                if (tasks[i].completed == 0) // إذا لم تكن المهمة منجزة
                {
                    if (incompletedTasks == 0) // إذا كانب المهام الغير منجزة تساوي 0
                    {
                        printf("You are complet all tasks");
                    } else // إذا كنت لم تنجز و لو مهمة واحدة
                    {
                        printf("     %d : %s.\n" , num , tasks[i].Tasks);
                    }
                }
            }
        } else if (choose == 'c') // إظهار كل المهام
        {
            printf("You all tasks : \n");
            for (i = 0 ; i < taskCount ; i++) {
                num++;
                if (tasks[i].completed == 0) {
                    done = '❌' ; // المهام الغير منجزة
                } else if (tasks[i].completed == 1) {
                    done = '✔'; // المهام المنجزة
                }
                printf("     %d : %s . %c \n" , num , tasks[i].Tasks , done);
            }
        } else // إذا اخترت خيار غير موجود
        {
            printf("This choice not found .");
        }
        
    }
    return 1;
}

int main() {
    struct TODOLIST todolist[MAX_TASKS];
    int choice;
    
    while (choice)
    {
        // ماذا تختار أن تفعل
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
    }
    

    return 0;
}