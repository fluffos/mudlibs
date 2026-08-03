#ifndef __TASK_H
#define __TASK_H

// AGENTS.md §8g variant: the field names below were the ORIGINAL content
// of this class (need_save/name/verb/target/event/begin_time/task_end),
// but system/std/task.lpc and system/feature/task.lpc -- the only two
// real users of `class task` in this lib -- exclusively access a
// completely different, PascalCase field set (TermType/KeyName/Verb/
// Target/Event/Birth/TaskEnd) that was never actually a member of this
// struct anywhere. This one mismatch cascaded into 45 of 144 lpcc-sweep
// failures (every file that transitively loads system/std/task.lpc).
// Fixed to match the fields the code actually uses.
class task
{
    int TermType;
    string KeyName;
    string Verb;
    string Target;
    mixed * Event;
    int Birth;
    int TaskEnd;
}

#define TASK_VERB           0
#define TASK_TARGET_NAME    1
#define TASK_OBJECT_NAME    2
#define TASK_SKILL_NAME     3
#define TASK_SKILL_LEVEL    4

#endif /* __TASK_H */
