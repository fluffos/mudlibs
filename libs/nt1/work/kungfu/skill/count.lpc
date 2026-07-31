
// count.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
        if ((int)me->query("int") < 35)
                return notify_fail("你的悟性不够，无法学习深奥的阴阳八卦。\n");
                
        if ((int)me->query_skill("literate", 1) < 100)
                return notify_fail("你连读书写字都没学好，还谈什么阴阳八卦？\n");

        if ((int)me->query_skill("literate", 1) < (int)me->query_skill("count", 1))
                return notify_fail("你的读书写字水平有限，无法掌握更深奥的阴阳八卦。\n");

        if ((int)me->query_skill("count", 1) > 399 && me->query("family/family_name") != "桃花岛")
                return notify_fail("阴阳八卦传授你到这就够了，如果想深造就必须加入桃花岛！\n");

        return 1;

}


