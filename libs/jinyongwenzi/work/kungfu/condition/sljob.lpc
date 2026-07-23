#include <ansi.h>
int update_condition(object me, int duration)
{
        if (duration < 1) {               
		tell_object(me, HIY "你感觉胸中充满浩然正气，心中为之一震。\n" NOR);
		return 0;
                }
         me->apply_condition("sljob", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
