// huayu.c 漫天花雨

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h"

int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, num, lvl, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("漫天花雨只能对战斗中的对手使用。\n");

	lvl = (int)me->query_skill("tanzhi-shentong", 1);
	if (lvl < 120) return notify_fail("你的弹指神通不够娴熟，无法使用漫天花雨。\n");

//	weapon = me->query_temp("weapon");
//	if (!weapon) return notify_fail("漫天花雨必须装备暗器才能使用。\n");
//	if ((num = weapon->query_amount()) < lvl / 20) 
//		return notify_fail("你掏了掏背囊，发现里面的暗器已经不够使用漫天花雨的要求了！\n");

	if ( (int)me->query("neili") < 450)
		return notify_fail("你的内力不够，无法使用漫天花雨。\n");

	msg = CYN "$N双手在背囊里一抓，抓出一大把喑器来，运用指力漫天地弹了出去，$n只觉眼前似乎在下一场暗器雨！\n";

	damage = lvl * 2 + (int)me->query_skill("bibo-shengong", 1);
	damage += random(damage / 2);
	damage = damage + 300;
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
		msg += "$n躲闪不及，“噗噗”地几声，被几道暗器击中！\n";
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n只觉得眼前一花，漫天的暗器打了他一身！\n" ;
//                msg += damage_msg(damage, "刺伤");
//                msg += "( $n" + eff_status_msg(p) + " )\n";
	} 
	else {
		msg += "$n吓得赶忙抱头团身，万分狼狈地向旁边一滚，方才堪堪地躲了过去。\n" NOR;
	}
	message_vision(msg, me, target);
	me->add("neili", -350);
	me->start_busy(2);
//	if (num == lvl / 20) {
//		weapon->unequip();
//		tell_object(me, "\n你的" + weapon->query("name") + "用完了！\n");
//	}
//	weapon->add_amount(-(lvl/20));

	return 1;
}
