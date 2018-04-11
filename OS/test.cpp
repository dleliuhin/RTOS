/*******************************/
/*           test.c            */
/*******************************/

#include <stdio.h>
#include <stdlib.h>

#include "rtos_api.h"


DeclareTask(Task1,1);
DeclareTask(Task2,2);
DeclareTask(Task3,3);

DeclareTask(Task6,1);
DeclareTask(Task7,3);
DeclareTask(Task8,5);
DeclareTask(Task9,7);
DeclareTask(Task10,2);
DeclareTask(Task11,4);

DeclareResource(Res1,5);
DeclareResource(Res2,5);
DeclareResource(Res3,5);
DeclareResource(Res4,4);

int main(void)
{
    printf("Hello!\n");

    //StartOS(Task1,Task1prior,"Task1");

    StartOS(Task6,Task6prior,"Task6");

    ShutdownOS();
    system ("pause");
    return 0;
}


TASK(Task1)
{
    printf("Start Task1\n");

    ActivateTask(Task2,Task2prior,"Task2");

    printf("Task1\n");

    TerminateTask();
}

TASK(Task2)
{
    printf("Start Task2\n");

    ActivateTask(Task3,Task3prior,"Task3");

    printf("Task2\n");

    TerminateTask();
}

TASK(Task3)
{
    printf("Start Task3\n");

    printf("Task3\n");

    TerminateTask();
}


TASK(Task6)
{
    printf("Start Task6\n");

    GetResource(Res4,"Res4");

    ReleaseResource(Res4,"Res4");

    GetResource(Res1,"Res1");

    //ActivateTask(Task7,Task7prior,"Task7");

    ReleaseResource(Res1,"Res1");

    printf("Task6\n");

    TerminateTask();
}

