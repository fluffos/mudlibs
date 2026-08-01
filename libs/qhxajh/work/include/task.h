#ifndef __TASK_H
#define __TASK_H

class task {
  int need_save;
  string name;
  string verb;
  string target;
  mixed *event;
  int begin_time;
  int task_end;
}

#define TASK_VERB           0
#define TASK_TARGET_NAME    1
#define TASK_OBJECT_NAME    2
#define TASK_SKILL_NAME     3
#define TASK_SKILL_LEVEL    4

#endif /* __TASK_H */
