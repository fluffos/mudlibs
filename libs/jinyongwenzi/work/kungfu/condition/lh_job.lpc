#include <ansi.h>

int update_condition(object me, int duration)
{

	if (duration < 2){
       tell_object(me, HIY "一个浑厚的声音直透你的耳骨，你的值勤时间已经到了。\n" NOR);
       me->delete_temp("lh_teacher");  
        return 0;
       }
        me->apply_condition("lh_job", duration - 1);
        return 1;
}

string query_type(object me)
{
	return "job";
}
