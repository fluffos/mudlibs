// autosave.c
// writed by shadow

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object link_ob;

	if (duration != 1)
	{
		link_ob = me->query_temp("link_ob");
		if (link_ob) link_ob->save();
		me->save();
//		tell_object(me, HBBLU HIG "【存盘精灵】" HIY " 您的资料已自动存盘了。\n" NOR);
		me->clear_condition("autosave");
	return 1;

	}
	else
		me->clear_condition("autosave");
	return 1;
}
