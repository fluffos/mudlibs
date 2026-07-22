// hanbing-zhenqi.c 寒冰真气
// Created by Numa 1999
// Modified by Numa 2000.1.5
// Modified by Numa 2000.1.25
// Modified by darken@SJ

#include <ansi.h>
inherit FORCE;
#include "/kungfu/skill/force.h"

int valid_enable(string usage) { return usage == "force" || usage=="strike" || usage =="parry"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");
        return 1;
}

void skill_improved(object me)
{
        int pl1,pl2;

        pl1 = me->query_skill("hanbing-zhenqi", 1);
        pl2 = me->query_skill("hanbing-shenzhang", 1);
        if (pl1>=220 && !me->query("ss/hbzq_220")){
                tell_object(me, HIW"\n忽然，你感觉体内寒气越聚越盛，全身似乎堕入冰窖，寒冷刺骨！\n"NOR);
                tell_object(me, HIW"\n过了一会，体内寒气逐渐聚在丹田处，全身精神为之一振，功力修为大大提升！\n"NOR);
                me->delete("ss/hb_improve");
                me->add("max_neili", pl1 + random(pl2));
                me->set("ss/hbzq_220", 1);
        }

}


int practice_skill(object me)
{
        if((int)me->query_skill("hanbing-zhenqi", 1) >= 200){
		if ((int)me->query_skill("hanbing-zhenqi", 1) < 220)
			return notify_fail("你的寒气过重，需要向左冷禅请教了。\n");
		if( (int)me->query("potential", 1) > 5
                 && (int)me->query("neili", 1) > 200){
			me->improve_skill("hanbing-zhenqi", (int)me->query_int());
                        me->add("neili", -100);
                        me->add("potential", -1*(1+random(3)));
                        return 1;
                }
                else
		return notify_fail("你现在的修为不足以提高寒冰真气了。\n");
        }
        else
	return notify_fail("你现在的寒冰真气修为只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
       return __DIR__"hanbing-zhenqi/" + func;
}

mapping exercise_msg(object me)
{
	return ([
		"status_msg" : HIW + me->name()+"脸上寒气浮现，隐隐有微光流动" NOR,
		"start_my_msg" : "你手捏剑诀，将寒冰真气提起在体内慢慢转动。\n",
		"start_other_msg" : HIB + me->name()+"摆了个盘膝打坐的姿势，全身笼罩在一片寒气之内。\n"NOR,
		"halt_msg" : "$N双眼一睁，极速压下内息站了起来。\n",
		"end_my_msg" : "你将寒冰真气按周天之势搬运了一周，感觉精神充沛多了。\n"NOR,
		"end_other_msg" : HIW"只见"+me->name()+"缓缓睁开双眼站起，浑身散发出一股冰冷的寒气。\n"NOR,
		"heal_msg" : HIW"$N运起寒冰真气，开始缓缓运气疗伤。\n"NOR,
		"heal_finish_msg" : HIY"$N内息一停，却见伤势已经全好了。\n"NOR,
		"heal_unfinish_msg" : "$N眉头一皱，“哇”地吐出一口瘀血，看来这伤还没有全好。\n",
		"heal_halt_msg" : "$N急急把内息一压，也不顾身上的伤势立即站了起来。\n",
	]);
}

