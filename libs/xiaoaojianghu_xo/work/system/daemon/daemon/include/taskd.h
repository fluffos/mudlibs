#ifndef __TASKD_H__
#define __TASKD_H__

//#define TASK_DIR                "/system/task/"
#define TASK_TIME               2

nosave void create();

void RehashTask();
varargs void TaskBegin(object, string, string);
void DestructTask(string);
object FindTask(string);

object * SearchTasks(string, int);

private string find_task_index(object);
private string compile_task(object, mixed);
private void load_task(string, string *);
private object find_task_object(string, int, string);

#endif /* __TASKD_H__ */

