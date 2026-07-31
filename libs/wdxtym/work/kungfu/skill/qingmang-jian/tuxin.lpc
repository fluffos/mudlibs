//tuxin.c -「青蟒吐信」
// Modified by Venus Oct.1997
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
string query_name() { return "青蟒"ZJBR"吐信"; }
int perform(object me, object target)
{
	int extra,damage;
	object weapon;
	string msg;
	extra=me->query_skill("qingmang-jian",1);
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("你只能对战斗中的对手使用「青蟒吐信」。\n");
	if (me->is_busy()) 
		return notify_fail("你现在正忙着呢！\n");
	if( (int)me->query_skill("qingmang-jian",1) < 100)
		return notify_fail("你目前功力还使不出「青蟒吐信」。\n");
	if (!objectp(weapon = me->query_temp("weapon"))|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if (me->query_skill_mapped("sword") != "qingmang-jian")
		return notify_fail("你没正确激发该技能 。\n");
	if( (int)me->query("neili") < 200 )
		return notify_fail("你的内力不够。\n");
	me->add("neili", -100);
	msg = HIC"$N脸上青光一闪，剑光闪动，犹如蟒蛇吐信一般，刷刷刷连出三招！"NOR;
	message_vision(msg, me, target);
	damage = extra + random(extra);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		target->receive_damage("qi", damage,me);
//		target->receive_wound("qi", damage);
	if (userp(me) && me->query("env/no_combat_msg")<4) tell_object(me, HIW"该绝招对敌人气血的外伤为"+ damage +"。\n" NOR);
	me->start_busy(2);
	
	return 1;
}

