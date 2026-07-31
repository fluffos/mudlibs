// zangfoyin.c 古秘术·太荒掌

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string query_name() { return "古秘术·"ZJBR"太荒掌"; }
string *pfm_type() { return ({ "hand", }); }

int perform(object me, object target)
{
	object weapon, weapon2;
	int damage;
	int count, wx;
	string msg;
	int ap, dp;

	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「古秘术·太荒掌」只能对战斗中的对手使用。\n");
	if ((int)me->query_skill("shanggu-mijing", 1) < 200)
		return notify_fail("你的上古秘经不够娴熟，不会使用「古秘术·太荒掌」。\n");
	if ((int)me->query_skill("force") < 300)
		return notify_fail("你的内功修为不够高，难以运用「古秘术·太荒掌」。\n");
if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");
	msg = HIC "$N" HIC "运内力于手大喝一声，使出上古秘经绝学「古秘术·太荒掌」向$n攻去，只见$n的面前出现了一尊流着血泪的十丈大佛！"NOR"\n";

	me->add("neili", -1500);
	ap = me->query_skill("hand")+ me->query_skill("force"); 
	dp = target->query_skill("dodge") + target->query_skill("force");
			  
	if (ap / 2 + random(ap) > dp/2+random(dp/2))
	{		
		damage = me->query_skill("shanggu-mijing", 1);
		wx = me->query("int")+me->query_int()/2;
		damage = damage*(1000+wx-20)/100;
		
		me->add_temp("apply/attack", damage);
		me->add_temp("apply/damage", damage);
		
		me->add("neili", -1000);

		for(int i =0;i<18;i++) {
			if (! me->is_fighting(target))
				break;
			COMBAT_D->do_attack(me, target, weapon, 0);
		}
		me->add_temp("apply/attack", -damage);
		me->add_temp("apply/damage", -damage);
				
		if (objectp(weapon2=target->query_temp("weapon")) && random(100) < (wx/2+10)) {
			msg += HIR "$n" HIR "一声惨叫口吐鲜血向后飞去，手中兵刃应声而落。"NOR"\n";
			weapon2->move(environment(target), 1);
		}
		else
			msg += HIR "$n" HIR "一声惨叫口吐鲜血向后飞去。"NOR"\n";
		
		me->start_busy(random(1)+1);
	} else 
	{
		msg += HIC "可是$p" HIC "身手敏捷，巧妙的躲过了$P"
		       HIC "的攻击！"NOR"\n";
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
