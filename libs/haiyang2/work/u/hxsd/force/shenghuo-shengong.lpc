// shenhuo-shengong.c
// 4/5/97  -qingyun
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

//#include "force.h"

int valid_learn(object me)
{
        if (me->query_skill("force", 1) > 9)
        //		return valid_public(me);
	return notify_fail("你的基本内功还需要进一步提高。\n");
        if (
        me->query_skill("bahuang-gong",1)
	|| me->query_skill("beiming-shengong",1)
	|| me->query_skill("bibo-shengong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong-dafa",1)
	|| me->query_skill("huntian-qigong",1)
	|| me->query_skill("hunyuan-yiqi",1)
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
me->query_skill("shenyuan-gong",1)   ||
me->query_skill("huashan-neigong",1)   ||
me->query_skill("zixia-shengong",1) ||
me->query_skill("xuantian-wuji",1)  ||
me->query_skill("guiyuan-tunafa",1) )  return notify_fail("你不先散了别派内功，怎能学圣火神功？！\n");
 return 1;
}

int practice_skill(object me)
{
	return notify_fail("圣火神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D("shenghuo-shengong/") + func;
}
mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIR + me->name()+"神情严肃，周身宛如一团火焰" NOR,
    "start_my_msg" : "你盘膝而坐，双手垂于胸前成火焰状，深吸口气，让经络中的真气化做一股灼流缓缓涌入丹田。\n",
    "start_other_msg" : me->name()+"盘膝而坐，双手在前胸搭住，神情严肃，周身仿如一团火焰般相仿。\n",
    "halt_msg" : "$N周身微微颤动，长出口气，站了起来。\n",
    "end_my_msg" : "你将周身内息贯通经脉，缓缓睁开眼睛，站了起来。\n",
    "end_other_msg" : "只见"+me->name()+"睁开眼睛，站了起来，头顶凝聚的白气慢慢飘散开。\n",
    "heal_msg" : HIW"$N盘膝而坐，双手十指张开，举在胸前，作火焰飞腾之状，运起"RED"圣火神功"HIW"开始疗伤。\n"NOR,
    "heal_finish_msg" : HIW"$N脸上流光浮现，一声：“焚我残躯，熊熊圣火，生亦何欢，死亦何苦？”，缓缓站起。\n"NOR,
    "heal_unfinish_msg" : "$N神态庄严，缓缓站起身来，但脸上血红，看来伤势还没有完全恢复。\n",
    "heal_halt_msg" : "$N脸颊胀红，头顶热气袅袅上升，猛地吸一口气，挣扎着爬了起来。\n",
    ]);
}
