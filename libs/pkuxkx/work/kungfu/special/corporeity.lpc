// corporeity.c 固本培元


#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIC "固本培元" NOR; }

int perform(object me, string skill)
{
        if(me->query("age")<18)
                return notify_fail("你还未成年，不能使用特殊技能。\n");
		if (me->query("special_level/corporeity")>=2)
			return notify_fail("这项技能够使你修炼的效果更好、支持更高的内力值，不需要运用。\n");
		else 
			return notify_fail("这项技能够使你体质更好，修炼的效果更高，不需要运用。\n");
}

int active_level(object me)
{
	if (!objectp(me)) return 0;
	if (me->query("special_skill/corporeity"))
	{
		if (me->query("special_level/corporeity")>=2)
		{
			switch (me->query("special_level/corporeity"))
			{
				case 4: if (me->query("special_skill/constitution"))
					{
						if (me->query("special_level/constitution")>=2) return 4;
						else return 3;
					}
					else return 2;
				case 3: if (me->query("special_skill/constitution")) return 3;
						else return 2;
				case 2: return 2;
			}
		}
		return 1;
	}
	return 0;
}

int maxneili_level4()
{
	return 40;
}

int maxneili_level3()
{
	return 25;
}

int maxneili_level2()
{
	return 10;
}