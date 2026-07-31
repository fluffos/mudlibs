#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}


int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够，无法领会神元功。\n"); if ( 
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
me->query_skill("shayi-xinfa",1)||
me->query_skill("biyun-xinfa",1)||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("bingxue-xinfa",1)||
me->query_skill("wudu-shengong",1)||
me->query_skill("guiyuan-tunafa",1) ) return notify_fail("你不先散了别派内功，怎能学神元功？！\n");
	return 1;
}

int practice_skill(object me)
{
       return notify_fail("神元功只能用学(learn)的来增加熟练度。\n");
              
}

string exert_function_file(string func)
{
        return __DIR__"shenyuan-gong/" + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIB + me->name()+"眼神凌厉，神态极为凝重。" NOR,
    "start_my_msg" : "你随意一站，双手缓缓抬起，深吸一口气，真气开始在体内运转。\n",
    "start_other_msg" : me->name()+"随意在那里一站，双手缓缓抬起，眼神开始变的凌厉起来。\n",
    "halt_msg" : "$N眉头一皱，急速运气，把手放了下来。\n",
    "end_my_msg" : "你将真气在体内沿脉络运行了一圈，缓缓纳入丹田，放下手，长吐了一口气。\n",
    "end_other_msg" : "只见"+me->name()+"的眼睛慢慢闭上，立刻睁开，把手放下，长吐了一口气。\n"
          ]);
}
