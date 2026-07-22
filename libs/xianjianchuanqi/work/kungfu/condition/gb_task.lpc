// xx_task.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {  
           tell_object(me, BLU"听人说好象有只丝绸之路商队要出发了！\n"NOR);      
           me->delete_temp("rob_start", 1);
           me->delete_temp("gb_rob");
           me->delete_temp("gb_job2");
           me->delete_temp("j");      
           return 0;
        }
        me->apply_condition("gb_task", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
