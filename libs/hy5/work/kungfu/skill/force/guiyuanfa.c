// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{
int qi;
    if ((!target))
		return notify_fail("你要用真气为谁疗伤？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");


        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

	if ((int)me->query_skill("force", 1) < 300)
		return notify_fail("你的内功修为还不够。\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_qi") >= (int)target->query("max_qi") 
	&& (int)target->query("eff_jing") >= (int)target->query("max_jing"))
		return notify_fail( target->name() + "并未受伤！\n");

        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("你已经在运九阴中了。\n");

        if (me->query_skill_mapped("force") == "jiuyin-zhengong")
                return notify_fail("你内功已经在运九阴中了。\n");
		      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大伏魔拳的特殊攻击「伏魔」！\n");
	message_combatd(
		HIG "$N坐了下来运起内功，将手掌贴在$n背心，贯通所学的内功武学开始运功疗伤....\n\n"
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );

	qi=500 + (int)me->query_skill("force")/2;
	
	if (me->query("zhuanshen"))
qi=qi*2;

if (me->query("zhuanbest"))
qi=qi*2;

if (me->query("4zhuan"))
qi=qi*2;

if (qi>me->query("max_qi",1)) qi=me->query("max_qi",1);
	
	target->receive_curing("qi", qi );
	target->add("qi", qi );
	
	if( userp(target) && (int)target->query("qi") > (int)target->query("eff_qi") ) target->set("qi", (int)target->query("eff_qi"));
	if( !userp(target) && (int)target->query("qi") > (int)target->query("max_qi")*5 ) target->set("qi", (int)target->query("max_qi"));


if (qi>me->query("max_jing",1)) qi=me->query("max_jing",1);
	target->receive_curing("jing", qi );
	target->add("jing", qi );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)target->query("eff_jing"));
	me->add("neili", -300);
        if (random(3)==1) target->start_busy(1);
	return 1;
}
