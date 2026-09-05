// throw.c 抽髓掌施毒
// By Yzuo 97.04

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object obj;
	string msg;

	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

	if( !target || !target->is_character() )
		return notify_fail("施毒只能对对手使用。\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 40 )
		return notify_fail("你的化功大法不够娴熟，不能施毒。\n");

	if( (int)me->query_skill("chousui-zhang", 1) < 40 )
		return notify_fail("你的抽髓掌不够娴熟，不能施毒。\n");

	if ( !(objectp(obj=present("corpse", environment(me))) 
        || objectp(obj=present("corpse", me))
        || objectp(obj=present("Skeleton", environment(me)))
        || objectp(obj=present("Skeleton", me)) ) )
		return notify_fail("你周围没有尸体。\n");

	msg = CYN "$N顺手抓起尸体，将毒质运于其上，掷向$n。\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("chousui-zhang",1))
          > random(target->query_skill("dodge") ) ) {
		msg += CYN " 结果$p被$P攻了个正着！\n" NOR;
            target->receive_damage("qi",(int)me->query_skill("chousui-zhang",1), me);
            target->receive_wound("qi",15 + random(10), me);
            target->receive_wound("jing", 10, me);
            target->set_temp("death_cond_origin/xx_poison", me);
            target->apply_condition("xx_poison", random(me->query_skill("chousui-zhang",1)/10) + 1 +
			target->query_condition("xx_poison"));
			if (!target->is_busy()) target->start_busy(1 + random(2));
	message_combatd(msg, me, target);
	COMBAT_D->report_status(target);

	} else {
		msg += "可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(4);
		message_combatd(msg, me, target);
	}
	if( !target->is_killing(me->query("id")) ) target->kill_ob(me);
		destruct(obj);
	return 1;
}
