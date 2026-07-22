// mj_tasting.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) 
		{
		tell_object(me, HIY "你的动作太慢,任务被取消了。\n" NOR);
        me->delete_temp("huang_job_target");
        return 0;
		}
        if (!duration) return 0;
        me->apply_condition("huang_mission", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
