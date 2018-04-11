#include <stdio.h>
#include "sys.h"
#include "rtos_api.h"
//Постановка системного события
void SetSysEvent(TEventMask mask)
{
    printf("SetSysEvent: %i\n", mask);
    work_events |= mask;
    int task = HeadTask;
    while (true) {
        if(TaskQueue[task].task_state == TASK_WAITING && (work_events & TaskQueue[task].waiting_events))
        {
            TaskQueue[task].waiting_events &= !mask;
            work_events &= !mask;
            TaskQueue[task].task_state = TASK_READY;
            Dispatch();
            break;
        }
    task = TaskQueue[task].next;
    if(task == HeadTask)
        break;
    }
}
//---------------------------------------------------
//Получение системного события для данной задачи
void GetSysEvent(int task, TEventMask* mask)
{
    *mask = work_events;
}
//Ожидание системного события
void WaitSysEvent(TEventMask mask)
{
    printf("")
}
