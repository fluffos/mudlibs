// dacheng-fofa.c 大乘佛法
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        int lvl;
        
        lvl = (int)me->query_skill("dacheng-fofa", 1);
        
        if(me->query("gender") == "无性" && lvl > 10)
                return notify_fail("你刚听一会儿，便觉心智迷糊，原来你既没有阴柔之气，无法领会大乘佛法中高深莫侧的变化之道。\n");
        return 1;
}

int practice_skill(object me)
{       
        return notify_fail("大乘佛法只能靠学习来提高。\n");
}
