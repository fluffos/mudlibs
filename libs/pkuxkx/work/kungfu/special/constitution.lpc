// constitution.c 镇蕴七星


#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIC "镇蕴七星" NOR; }

int perform(object me, string skill)
{
	if(me->query("age")<18)
		return notify_fail("你还未成年，不能使用特殊技能。\n");
        return notify_fail("这项技能能够使你打坐效率更高，不需要运用。\n");
}

int active_level(object me)
{
	if (!objectp(me)) return 0;
	if (me->query("special_skill/constitution"))
	{
		if (me->query("special_level/constitution")>=2)
		{
			switch (me->query("special_level/constitution"))
			{
				case 4: if (me->query("special_skill/corporeity"))
					{
						if (me->query("special_level/corporeity")>=2) return 4;
						else return 3;
					}
					else return 2;
				case 3: if (me->query("special_skill/corporeity")) return 3;
						else return 2;
				case 2: return 2;
			}
		}
		return 1;
	}
	return 0;
}

int neili_heal_level4()
{
	return 300*95/10;
}

int neili_heal_level3()
{
	return 200*95/10;
}

int neili_heal_level2()
{
	return 100*95/10;
}