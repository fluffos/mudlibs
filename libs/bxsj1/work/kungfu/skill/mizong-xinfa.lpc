// /kungfu/skill/mizong-xinfa
// by dubei
// mizong-xinfa.c 密宗心法

 
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        int lvl;
        
        lvl = (int)me->query_skill("dacheng-fofa", 1);
        
        if(me->query("gender") == "无性" && lvl > 10)
                return notify_fail("你刚听一会儿，觉得无法领悟密宗心法。\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("密宗心法只能靠学习来提高。\n");
}