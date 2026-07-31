// mahayana.c 大乘涅磐功
//create bye cuer
inherit SKILL;
void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int valid_learn(object me) 
{       
        int ji = (int)me->query_skill("mahayana",1); 
        if (me->query("class")!="bonze" && ji > 99 )
                return notify_fail("由于你不是佛门中人，心有俗念，不能领会佛门的高深武功。\n");
        if( ji > 9 && me->query("shen") < (int)(ji*ji*ji/4) && me->query("shen") < 500000 )
                return notify_fail("你的善行不够，无法领会大乘涅磐的精妙理论。\n");
        return 1;
}
int practice_skill(object me)
{       
        return notify_fail("大乘涅磐功只能靠学(learn)来提高。\n");
}
