#include <ansi.h>
// 斗折蛇行 
inherit SKILL; 
string type() { return "knowledge"; } 

int is_fmsk() { return 1; }
string family_name() { return "神龙教"; }

int valid_learn(object me)
{        
        if (me->query_skill("shedao-qigong", 1) < 180)
                return notify_fail("你蛇岛奇功火候不足，无法研习斗折蛇行。\n");        
        
        if( me->query("family/family_name") != family_name() )
                return notify_fail("气脉流转只能段氏皇族弟子方可研习。\n");

        if (me->query_skill("shedao-qigong", 1) < 
            me->query_skill("douzhe-shexing", 1) * 60 /100)
                return notify_fail("你蛇岛奇功修为不足，无法继续研习斗折蛇行。\n");

        return 1;
}

int difficult_level()
{
        return 2000;
}
