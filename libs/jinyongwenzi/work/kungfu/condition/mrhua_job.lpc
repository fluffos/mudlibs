// mrhua_job.c 

#include <login.h>
#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
            //  me->delete_temp("mrhua");
              me->delete_temp("yanpopo");
              me->delete_temp("mark/ok");
              me->delete_temp("mark/还了");
              me->delete_temp("mark/次");
              tell_object(me,HIY"突然一个家丁跳了出来，大声喝道：你怎么比猪还慢，任务被取消了。\n"NOR);
              me->clear_condition("mrhua_job");
                  }
        if (!duration) return 0;
        me->apply_condition("mrhua_job", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
