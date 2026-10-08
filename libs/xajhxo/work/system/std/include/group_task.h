#ifndef __GROUP_TASK_H
#define __GROUP_TASK_H

void SetLevel( int );
int GetLevel();
void SetMasterName( string );
string GetMasterName();
void TaskBegin( object );
void TaskSuccess( object );
void TaskFail( object );
int CanBegin( object );
int CanEnd( object );
protected void create();
protected void heart_beat();

#endif /* __GROUP_TASK_H */


