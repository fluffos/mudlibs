// sociability.c 长袖善舞


#include <ansi.h>

inherit F_CLEAN_UP;

string name() { return RED "长袖善舞" NOR; }

int perform(object me, string skill)
{
        if(me->query("age")<18)
                return notify_fail("你还未成年，不能使用特殊技能。\n");
        return notify_fail("这项技能能够使你交际能力更强，不需要运用。\n");
}
