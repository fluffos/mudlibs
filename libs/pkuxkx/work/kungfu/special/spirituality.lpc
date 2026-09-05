// spirituality.c 灵气逼人


#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return CYN "灵气逼人" NOR; }

int perform(object me, string skill)
{
	if(me->query("age")<18)
		return notify_fail("你还未成年，不能使用特殊技能。\n");
        return notify_fail("这项技能能够使你灵性更高，不需要运用。\n");
}


