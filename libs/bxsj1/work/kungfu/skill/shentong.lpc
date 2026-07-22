// 神通  shentong.c

#include <ansi.h>
inherit F_SSERVER;

string perform_name(){ return HIW"弹指神通"NOR; }

int perform(object me, object target)
{
	int damage, p, ap, dp;
	object weapon, weapon1;
	string msg, dodge_skill, *limbs, limb;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character()
	 || !me->is_fighting(target)
	 || environment(target)!=environment(me))
		return notify_fail("弹指神通只能对战斗中的对手使用。\n");

	if(  me->query_skill("tanzhi-shentong", 1) < 120 )
		return notify_fail("你的弹指神通还未到火候，使不出来弹指神通。\n");

	if(  me->query_skill("bihai-chaosheng", 1) < 120)
		return notify_fail("你的碧海潮生功还未到火候。\n");

	if(  me->query_skill("throwing", 1) < 120 )
		return notify_fail("你的基本暗器还未到火候，使不出来弹指神通。\n");

	if(  me->query("max_neili", 1) < 1600 )
		return notify_fail("你的内功修为不足以使出弹指神通绝技。\n");

	if(  me->query("neili", 1) < 500 )
		return notify_fail("你的内力不足以使出弹指神通绝技。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	 && (int)me->query_skill("tanzhi-shentong", 1) < 160)
		return notify_fail("你现在无法使用弹指神通。\n");

	if(weapon && (weapon->query("skill_type") != "throwing"
	 || me->query_skill_mapped("throwing") != "tanzhi-shentong"))
		return notify_fail("你现在的武器无法使用弹指神通。\n");

	if( me->query_skill_mapped("parry") != "tanzhi-shentong"
	 || me->query_skill_prepared("finger") != "tanzhi-shentong")
	 	return notify_fail("你现在无法使用弹指神通。\n");

	if(weapon)
		msg = HIW"\n只见$N双肩微晃，凝力于指，将"+weapon->name()+HIW+"化作一道闪光从$P手中射出，直奔$n而去！\n"NOR;
	else
		msg = GRN"\n$N暗运内劲于指，看准机会对着$n一弹，一丝气劲激射而出，点向$p胸前大穴！\n"NOR;

	limbs = target->query("limbs");
	limb = limbs[random(sizeof(limbs))];
	weapon1 = target->query_temp("weapon");

	ap = me->query("combat_exp", 1) /1000 * me->query_skill("tanzhi-shentong", 1);
	dp = target->query("combat_exp", 1)/ 1000 * target->query_skill("dodge", 1);

	if ( random( ap + dp ) > dp ) {
		if( weapon && weapon1 ) {
			weapon1->unequip();
			weapon1->move(environment(target));
			target->reset_action();
			me->add("neili", -150);
			target->add_busy(2);
			msg += HIR"$n只觉得手臂一麻，已被$N的"+weapon->name()+HIR+"打中了穴道，不由自主地把手中的"+weapon1->name()+HIR+"坠地！\n"NOR;
			me->start_perform(2, "弹指神通");
		}
		else {
			damage = me->query_skill("tanzhi-shentong", 1) * 3;
			damage += me->query_skill("throwing",1) * 2;
			damage += random(damage);

			if(me->query("neili") > target->query("neili")*2)
				damage *= 2;

			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/3, me);

			if(weapon)
				target->receive_wound("qi", random(damage/2), me);

			target->add_busy(1 + random(2));

			p = (int)target->query("eff_qi") * 100 / (int)target->query("max_qi");
			msg += COMBAT_D->damage_msg(damage, "刺伤");
			msg += "( $n" + COMBAT_D->eff_status_msg(p) + " )\n";
			msg = replace_string(msg, "$l", limb);
			msg = replace_string(msg, "$w", weapon?weapon->name():"弹指剑气");
			me->add("neili", -200);
			me->add("jingli", -100);
			me->start_perform(3, "弹指神通");
		}
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		me->start_perform(2, "弹指神通");
	}
	message_vision(msg, me, target);
	me->add("neili", -150);
	me->add("jingli", -80);
	me->start_busy(random(2));
	return 1;
}

int help(object me)
{
        write(HIW"\n弹指神通之「弹指神通」："NOR"\n\n");
        write(@HELP
        要求：  最大内力 1600 以上；
                当前内力 500 以上；
                碧海潮生功 120 级以上；
                基本暗器 120 级以上；
                空手使用需要弹指神通 160 级以上；
                持兵器使用需弹指神通 120 级以上。
                基本指法 120 级以上。
                激发指法为弹指神通。
                激发招架为弹指神通。

HELP
        );
        return 1;
}
