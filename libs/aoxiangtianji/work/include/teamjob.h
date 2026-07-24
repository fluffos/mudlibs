// teamjob.h
// QUEST基础对象
#define TEAMJOB_OB       "/std/misc/teamjob"
// 任务对象的函数
varargs string name();
varargs string id();
// 功能函数
varargs void   set_name(string name);
varargs void   set_id(string id);
// 状态机函数
string  query_status();
void    change_status(string new_state);
// 任务对象的系统状态
#define TEAMJOB_CREATE            "created" /* 任务创建     */
#define TEAMJOB_READY             "ready"   /* 任务就绪     */
#define TEAMJOB_ONGOING           "ongoing" /* 任务进行中   */
#define TEAMJOB_FINISH            "finish"  /* 任务完成     */
#define TEAMJOB_ERROR             "error"   /* 任务错误状态 */
// 任务对象的系统事件
#define TEAMJOB_TIMEOUT           "timeout" /* 任务超时     */
// 在创建状态最长的停留时间
#define TEAMJOB_CREATE_PERIOD     10
// 在结束状态最长的停留时间
#define TEAMJOB_FINISH_PERIOD     1
