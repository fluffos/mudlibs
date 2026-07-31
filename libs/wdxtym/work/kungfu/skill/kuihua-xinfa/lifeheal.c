// lifeheal.c

#include <ansi.h>
string query_name() { return "葵花"ZJBR"他疗"; }
int exert(object me, object target)
{

        if ((!target)||target->query("id")==me->query("id"))
                return notify_fail("你要用真气为谁疗伤？\n");

        if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法运功疗伤！\n");

  	 if( (int)me->query_skill("kuihua-xinfa",1) < 20)
		return notify_fail("你的葵花心法还不够精熟。\n");

        if( (int)me->query("max_neili") < 300)
                return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("neili") < 100)
                return notify_fail("你的真气不够。\n");

        if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");

        message_combatd(
                HIR "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
                "过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
                me, target );

    target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
    target->add("qi", 10 + (int)me->query_skill("force")/4 );
    if( userp(target) && (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
    if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi")*5 ) target->set("qi", (int)target->query("max_qi"));
    me->add("neili", -100);
    return 1;
}

