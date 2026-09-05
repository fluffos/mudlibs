// athanasy.c 凤凰涅磐


#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIY "凤凰涅磐" NOR; }

int perform(object me, string skill)
{
	if(me->query("age")<18)
		return notify_fail("你还未成年，不能使用特殊技能。\n");
        return notify_fail("这项技能能够使你命更大，不需要运用。\n");
}

int active_level(object me)
{
	if (!objectp(me)) return 0;
	if (me->query("special_skill/athanasy"))
	{
		if (me->query("special_level/athanasy")>=3)
		{
			if (me->query("special_skill/constitution") && me->query("special_skill/intellect"))
				return 3;
			else {
				if (me->query("special_skill/intellect")) return 2;
			}
		}
		else
		{
			if ((me->query("special_level/athanasy")>=2)&&(me->query("special_skill/intellect")))
				return 2;
		}
		return 1;
	}
	return 0;
}

