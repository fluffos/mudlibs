// sl_lunzi.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 2) {
                    tell_object(me, HIY "你轮值的时间已到，快回去复命(task ok)吧！\n" NOR);
me->set_temp("lunzhi_ok",1);
                return 0;
        }
        me->apply_condition("sl_lunzhi", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
