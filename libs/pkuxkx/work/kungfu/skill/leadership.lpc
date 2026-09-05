// leadership.c 为官之道
// 朝廷技能
 
#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if (me->query("class") != "officer")
        return notify_fail("你又没做官学这个干什么啊？\n");
        return 1;
}
