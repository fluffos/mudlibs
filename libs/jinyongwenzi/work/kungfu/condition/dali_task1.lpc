// dali_task1.c
// dubei done 98 6

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
		tell_object(me, HIY "段王爷对你很是失望，已经找人重新送信了，你任务失败。\n" NOR);
                me->delete_temp("dali_targets");
                me->delete_temp("dali_didian");
                me->delete_temp("dali_time");
                me->clear_condition("dali_task1");
                me->add("dali_job1",-1);
                return 0;
	}
        if (!duration) return 0;
        me->apply_condition("dali_task1", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
