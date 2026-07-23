#ifndef __TASKD_H__
#define __TASKD_H__

#define TASK_REHASH_TIME                10 
#define TASK_TIME                       300 

void eventRehashTask();
void eventDestructTask( object );
void TaskRestore( object, string, string );
varargs void TaskBegin( object, string, string ); 

nosave void create();

private object * get_group_task( string, int );
private object load_task( string, int, string );
private string get_task_index( object );

#endif /* __TASKD_H__ */


