// lucky.c 洪福齐天


#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIY "洪福齐天" NOR; }

int perform(object me, string skill)
{
	if(me->query("age")<18)
		return notify_fail("你还未成年，不能使用特殊技能。\n");
        return notify_fail("这项技能能够使你福缘更高，不需要运用。\n");
}

int active_level(object me)
{
	if (!objectp(me)) return 0;
	if (me->query("special_skill/lucky"))
	{
		if (me->query("special_level/lucky")>=2)
		{
			if (me->query("special_skill/sociability")) return 2;
			else return 1;
		}
		return 1;
	}
	return 0;
}

