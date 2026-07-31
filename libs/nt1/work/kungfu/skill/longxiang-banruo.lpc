// longxiang-banruo.c 雪山 龙象般若功
// by Lonely

#include <ansi.h>
inherit FORCE;
int valid_force(string force) { return 1; }        
int query_neili_improve(object me)   
{
        int lvl;  
        lvl = (int)me->query_skill("longxiang-banruo", 1);  
        return lvl * lvl * 22 * 15 / 100 / 200;  
}


int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
        int i = (int)me->query_skill("longxiang-gong", 1);
        int t = (int)me->query_skill("lamaism", 1);
 

        if (me->query("str") < 28) 
                return notify_fail("你的臂力不足，不能学龙象般若功。\n"); 

        if ((string)me->query("class") != "lama")
                return notify_fail("你不是喇嘛，学不了高深的龙象般若功。\n");

        if ( me->query("gender") == "无性" )
                return notify_fail("你无根无性，阴阳不调，难以领会高深的龙象般若功。\n");
          
        if (i < 200 && t <= i)
                return notify_fail("你的密宗心法修为不够，无法领会更高深的龙象般若功。\n");

        return ::valid_learn(me); 

}

void skill_improved(object me)
{
        int i = (int)me->query_skill("longxiang-boruo", 1);   

        if (i == 20)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第一层了。\n");
        if (i == 40)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第二层了。\n");
        if (i == 60) 
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第三层了。\n");
        if (i == 80)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第四层了。\n");
        if (i == 100)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第五层了。\n");
        if (i == 120)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第六层了。\n");
        if (i == 140)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第七层了。\n");
        if (i == 160)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第八层了。\n");
        if (i == 180)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第九层了。\n");
        if (i == 200)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第十层了，已经具备了十龙十象的大力。\n");                   
        if (i == 220)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第十一层了。\n");
        if (i == 240)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第十二层了。\n");
        if (i == 260)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了融会贯通的境界，只怕天下已无人是你的对手了。\n");
}

string exert_function_file(string func)
{
        return __DIR__"longxiang-banruo/" + func;
}

mapping curing_msg(object me)
{
        return ([
                "apply_short"   : "闭目垂眉，入定运气。",
                "start_self"    : "闭目运气，体内气息流动，在各脉运转调理伤势。\n",
                "finish_other"  : "睁开眼来，脸现红润。\n",
        ]);
}

int practice_skill(object me)
{

        return notify_fail("你的龙象般若功修为不够，只能用学(learn)的来增加熟练度。\n");
}

