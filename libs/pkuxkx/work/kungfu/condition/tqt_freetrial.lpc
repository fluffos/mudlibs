// findfeng.c

#include <login.h>
#include <ansi.h>
 int update_condition(object me, int duration)
{
	string str;
	if (duration < 1) 
	{
		str=me->query("tqt/free_trial");
		if (me->query("tqt/freetrial")==1)
		{
			me->delete(str);
		}
		else
		{
			me->delete_skill(str);
		}
		me->delete("tqt/free_trial");
		me->delete("tqt/freetrial");
		tell_object(me,BLINK+HIR+"试用结束，你试用的铜雀台武功被删除了。\n"NOR);
		me->save();
		return 0;
	}
	me->apply_condition("tqt_freetrial", duration - 1);
	return 1;
}
