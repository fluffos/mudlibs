// same_family_killed

#include <ansi.h>

int update_condition(object me, int duration)
{
	object ob;
	
	if(duration < 1)
	{
		tell_object(me, "同门对你下达的追杀令已经撤消了。\n");
		return 0;
	}
	me->apply_condition("same_family_killed", duration - 1);
	return 1;
}