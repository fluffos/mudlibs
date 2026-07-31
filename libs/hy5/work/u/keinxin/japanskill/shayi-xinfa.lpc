#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}


int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 30)
                return notify_fail("你的基本内功火候还不够，无法领会杀意心法。\n"); if ( 
 me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
	|| me->query_skill("jiuyang-shengong",1)
	|| me->query_skill("kuihua-xinfa",1)
	|| me->query_skill("kurong-changong",1)
	|| me->query_skill("linji-zhuang",1)
	|| me->query_skill("longxiang",1)
 	|| me->query_skill("shenlong-xinfa",1)
	|| me->query_skill("taiji-shengong",1)
	|| me->query_skill("xiantian-qigong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yijinjing",1)
	|| me->query_skill("yunv-xinfa",1)
	|| me->query_skill("yunlong-shengong",1)   ||
me->query_skill("shenghuo-shengong",1)    ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("shenyuan-gong",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) ) return notify_fail("你不先散了别派内功，怎能学杀意心法？！\n");
	return 1;
}

int practice_skill(object me)
{
       return notify_fail("杀意心法只能用学(learn)的来增加熟练度。\n");
              
}

string exert_function_file(string func)
{
        return __DIR__"shayi-xinfa/" + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIB + me->name()+"杀意四起，眼神凌厉。" NOR,
    "start_my_msg" : HIR"眼神变得凌厉，四周杀意四起，真气开始在体内运转。\n"NOR,
    "start_other_msg" : me->name()+"全身收缩，全部的力量发挥了出来，眼神中的杀意无比凌厉。\n",
    "halt_msg" : "$N眉头松展，杀意消失，恢复了平时的模样。\n",
    "end_my_msg" : "无尽的杀意缓缓散入全身，睁开眼，长吐了一口气。\n",
    "end_other_msg" : "只见"+me->name()+"的眼睛允满杀意，但马上又恢复了原状。\n"
          ]);
}
