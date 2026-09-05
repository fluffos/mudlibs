
#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return HIR "天命神龙" NOR; }

int exclusive_special() { return 1; }

int max_level() { return 1; }

int perform(object me, string skill)
{
	if(me->query("age")<18)
		return notify_fail("你还未成年，不能使用特殊技能。\n");
    return notify_fail("这项技能使你在死亡时的损失降至极低，不需要运用。\n");
}
