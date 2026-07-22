// huayu.c 漫天花雨

#include <ansi.h>
inherit F_SSERVER;
string perform_name(){ return CYN"漫天花雨"NOR; }

int perform(object me, object target)
{
	string msg, *limbs, limb;
	object weapon;
	int damage, num, lvl, p, ap, dp;

	if( !target ) target = offensive_target(me);

	if( !objectp(target)
	 || !target->is_character() 
	 || !me->is_fighting(target))
		return notify_fail("漫天花雨只能对战斗中的对手使用。\n");

	if (!(me->query("thd/perform") & 16))
		return notify_fail("你虽然听说过“漫天花雨”这一招，可是却未获传授。\n");

	lvl = me->query_skill("tanzhi-shentong", 1);

	if (lvl < 120)
		return notify_fail("你的弹指神通不够娴熟，无法使用漫天花雨。\n");

	if (me->query_skill("throwing", 1) < 120)
		return notify_fail("你的基本暗器不够娴熟，无法使用漫天花雨。\n");

	if ( me->query_skill_mapped("parry") != "tanzhi-shentong"
	|| me->query_skill_mapped("throwing") != "tanzhi-shentong")
		return notify_fail("你现在的情况，无法使用漫天花雨。\n");

	if ( me->query_skill("bihai-chaosheng", 1) < 120 )
		return notify_fail("你的碧海潮生功等级不够，无法使用漫天花雨。\n");

	weapon = me->query_temp("weapon");

	if (!weapon)
		return notify_fail("漫天花雨必须装备暗器才能使用。\n");

	if ((num = weapon->query_amount()) < lvl / 20)
		return notify_fail("你掏了掏背囊，发现里面的暗器已经不够使用漫天花雨的要求了！\n");

	if (me->query("neili") < 1000)
		return notify_fail("你的内力不够，无法使用漫天花雨。\n");

	if (me->query("jingli") < 900)
		return notify_fail("你的精力不够，无法使用漫天花雨。\n");

	msg = HIW"\n$N双手在背囊里一抓，抓出" + CHINESE_D->chinese_number(lvl / 20) + weapon->query("base_unit") + weapon->query("name") + HIW"来，运用指力漫天地弹了出去，$n只觉眼前似乎在下一场暗器雨！\n"NOR;

	damage = lvl * 2 + (int)me->query_skill("bihai-chaosheng", 1);
	damage *= 3;
	damage += random(damage);
	if ( damage > 4000 )
		damage = 4000 + (damage -4000 )/10;

	ap = me->query("combat_exp")/1000 * me->query_str(1);
	dp = target->query("combat_exp")/1000 * target->query_dex(1);

	if (target->is_busy())
		dp -= dp/3;

	if (random(ap + dp ) > dp ) {
		limbs = target->query("limbs");
		limb = limbs[random(sizeof(limbs))];
		msg += "$n躲闪不及，“噗噗”地几声，被几道暗器击中！\n";
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3+random(damage/3), me);
		me->add("neili", -400);
		me->add("jingli", -100);
		p = (int)target->query("eff_qi") * 100 / (int)target->query("max_qi");
		msg += COMBAT_D->damage_msg(damage, "刺伤");
		msg = replace_string( msg, "$l", limb);
		msg = replace_string( msg, "$w", weapon->name());
		msg += "( $n" + COMBAT_D->eff_status_msg(p) + " )\n";
	}
	else {
		me->add("neili", -150);
		me->add("jingli", -50);
		msg += "$n吓得赶忙抱头团身，万分狼狈地向旁边一滚，方才堪堪地躲了过去。\n" NOR;
		target->add_busy(random(2));
	}
	message_vision(msg, me, target);
	me->start_perform(2, "「漫天花雨」");
	me->start_busy(random(2));
	if (num == lvl / 20) {
		weapon->unequip();
		tell_object(me, "\n你的" + weapon->query("name") + "用完了！\n");
	}
	weapon->add_amount(-(lvl/20));
	return 1;
}

int help(object me)
{
        write(CYN"\n弹指神通之「漫天花雨」："NOR"\n\n");
        write(@HELP
        要求：  当前内力 1000 以上；
                当前精力 900 以上；
                弹指神通 120 级以上；
                碧海潮生功 120 级以上；
                激发暗器为弹指神通；
                激发招架为弹指神通；
                装备一定数量的暗器且需经得黄药师的指点。

HELP
        );
        return 1;
}
