#ifndef S__TASK_H
#define S__TASK_H

#define     SHORT_TERM          0
#define     LONG_TERM           1
#define     HEART_BEAT_TIME     5

void SetExistenceTime( int );
void SetTermType( mixed );
int  GetTermType();
void SetTaskType( int );
int  GetTaskType();
void SetKeyName( string );
string GetKeyName();
void SetGroupName( string );
string GetGroupName();
void SetAct( string, mapping );
class act GetAct( string );
void SetTaskEvent( mapping );
void SetRelativeTasks( string * );

void TaskBegin( object );
void TaskSuccess( object );
void TaskFail( object );
varargs void TaskEnd( object );

nosave void create();
nosave void heart_beat();

void AddProposer( object );
void AddExecutor( object );
int IsFollower();
mixed GetBonus( string );

class task GetTask();
private int  check_time( int, string );
private int * parse_time( string );
private int  check_site( mixed, string );
private void parse_event( string );
private class act init_act( mapping );
private void task_bonus( object, mixed );

#endif  /* S__TASK_H */


