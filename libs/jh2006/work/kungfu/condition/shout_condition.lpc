// shout_condition.c 

#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
        if (duration < 2) {
		tell_object(me, HIY "你又可以纵声长啸了。\n" NOR);
		return 0;
	}
        me->apply_condition("shout_condition", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "shout";
}

