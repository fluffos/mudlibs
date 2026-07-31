// yuxiao.c 碧海潮生按玉箫

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h"

int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("碧海潮生按玉箫只能对战斗中的对手使用。\n");

	if( (int)me->query_skill("yuxiao-jian", 1) < 80 )
		return notify_fail("你的玉箫剑法不够娴熟，无法使用碧海潮生按玉箫。\n");

	weapon = me->query_temp("weapon");
//	if (!weapon || !(weapon->id("xiao")))
//		return notify_fail("你手里的兵器不是箫，无法使用碧海潮生按玉箫。\n");

	if ( (int)me->query("neili") < 120)
		return notify_fail("你的内力不够，无法使用碧海潮生按玉箫。\n");

	msg = CYN "$N将箫凑到嘴边，吹得两下，从箫筒里突然射出一道青光，直扑$n。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
		msg += "$n躲闪不及，正中前胸！\n";
		damage = (int)me->query_skill("yuxiao-jian", 1);
		damage += random(damage * 2 / 3);
		if (damage > target->query("neili") / 10)
			damage -= target->query("neili") / 15;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
//                msg += damage_msg(damage, "刺伤");
//                msg += "( $n" + eff_status_msg(p) + " )\n";
		if( damage < 100 ) msg += HIY"$n的胸前衣襟已经侵出了鲜血。\n"NOR;
        	else if( damage < 200 ) msg += HIR"$n胸前现出了一个又长又深的伤口！\n"NOR;
        	else msg += RED"竟然洞穿了$n的身体，$n手捂伤口，“哇”的一声吐出了一口鲜血。\n"NOR;
	} 
	else {
		msg += "可惜$n早已防备了$N的这招，向旁边一跃，躲开了这个暗器，但对暗器来势如此迅猛也不自禁地露出一丝惧意。\n" NOR;
	}
	message_vision(msg, me, target);
	me->add("neili", -90);
	me->start_busy(1);

	return 1;
}
