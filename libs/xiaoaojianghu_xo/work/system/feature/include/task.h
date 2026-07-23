#ifndef T__TASK_H
#define T__TASK_H

void AddTask( string, class task );
void AddTaskObject( string, object );
class task GetTask( string );
int  DeleteTask( mixed );
string GetTaskName( string );
int  GetTaskBirth( string );
int  GetTaskTime( string );
varargs void SetTaskEnd( string,int );
int  GetTaskEnd( string );
void SetTaskLevel( string,int );
int  GetTaskLevel( string );
varargs void eventTaskBegin( string, string );
varargs void eventTaskEnd( string, mixed, mixed );
void eventQuit();
void eventLogin();
void RestoreTask();
int CanTask( string );

nosave void create();
nosave void heart_beat();

#endif /* T__TASK_H */

