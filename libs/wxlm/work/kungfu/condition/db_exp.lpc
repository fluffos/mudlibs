
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

	if(environment(me)&&environment(me)->query("owner_special")&&environment(me)->query("sleep_room"))
	        return CND_CONTINUE;
        me->apply_condition("db_exp", duration - 1);
        
        if(random(30)==1)
	{
		tell_room(environment(me), me->name() + "看起来神采飞扬精神充沛。\n", ({ me }));
		tell_object(me, HIG"在天灵丹的作用下，你感觉做任何事都是事半功倍。"NOR"\n");
	}

        if( duration < 1 ) 
        {
        	tell_object(me, HIR"你觉得精神有些疲惫，成长速度又慢了下来。"NOR"\n");
        	return 0;
        }
        return CND_CONTINUE;
}

string query_type(object me)
{
	return "db_exp";
}
