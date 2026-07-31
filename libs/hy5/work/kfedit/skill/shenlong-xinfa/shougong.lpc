// shougong.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	if(me->query_temp("sld/shougong")==1)
		return 0;
	if(me->query_temp("sld/wudi")==1) {
		me->set_temp("sld/shougong",1);
		message_vision(CYN"$N缓缓收回内力，眼中的红光慢慢暗淡下来。\n"NOR,me);
	}
	else	{
		return notify_fail("你现在无法收功。\n");
	}

	return 1;
}
