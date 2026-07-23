#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object obj;
	string msg;
	int damage;
        int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
        
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("倚天屠龙功只能对战斗中的对手使用。\n");

	if((int)me->query_str() < 30)
		return notify_fail("你臂力不够,不能使用这一绝技!\n");

        if ((int)me->query_skill("yitian-tulong", 1) < 199)
                return notify_fail("你的「倚天屠龙功」火候太浅。\n");

        if ((int)me->query_skill("anranxiaohun-zhang", 1) > 1)
                return notify_fail("你有「黯然消魂掌」用不了这个!\n");


        if ((int)me->query_skill("taiji-shengong", 1) < 250)
                return notify_fail("你的「太极神功」火候太浅。\n");

        if ((int)me->query_skill("taiji-quan", 1) < 250)
                return notify_fail("你的「太极拳」火候太浅。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

	if((int)me->query("neili") < 800)
		return notify_fail("你内力现在不够, 不能使用倚天屠龙! \n");

	extra = me->query_skill("yitian-tulong",1) / 3;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", (extra+200));

	msg = HIY "$N长啸一声：" + YEL "武林至尊、宝刀屠龙。号令天下，莫敢不从。倚天不出，谁与争锋？\n" + HIY "手中两般武器发出无穷罡气，或如灵蛇盘腾，或如猛兽屹立，须臾间二十四字一齐写毕。\n"NOR;
        message_vision(msg, me, target);
	msg = HIW "接招！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIY "倚！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIY "天！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIY "屠！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIY "龙！\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add("neili",-300);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -(extra+200));
        me->start_busy(2);
	if (random(me->query("combat_exp")) > target->query_skill("combat_exp")/3 )
	{
		
		damage = (int)me->query_skill("yitian-tulong", 1);
		
                damage = 100 + damage + random(damage/2);
		
		target->receive_damage("qi", damage*2);
		target->receive_wound("qi", damage);
                me->add("neili", -damage/2);
		
		if( damage < 100 )
			msg = HIY"结果$n受到$N的内力反震，闷哼一声。\n"NOR;
        else if( damage < 200 )
			msg = HIY"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
        else if( damage < 300 )
			msg = RED"结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
		else
			msg = HIR"结果$n被$N的内力一震，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
		
	}
	message_vision(msg, me, target);

	return 1;
}
