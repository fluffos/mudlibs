// strategy.c 兵法战策
// 朝廷官员技能

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if (me->query("class") != "officer")
        return notify_fail("你又没做官学这个干什么啊？\n");
        return 1;
}
