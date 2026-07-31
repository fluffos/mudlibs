// kuang.c 天意刀

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "天意"ZJBR"刀"; }

int perform(object me, object target)
{
	object weapon;
	string msg;
	int count;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! target || ! me->is_fighting(target))
		return notify_fail("「天意刀」只能对战斗中的对手使用。\n");
 
	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "blade")
		return notify_fail("「天意刀」开始时必须拿着一把刀！\n");


	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够，无法施展天意刀！\n");

	if (me->query_skill("martial-cognize") < 300)
		return notify_fail("你的武学修养还不到家，无法使用「天意刀」！\n");

	if ((int)me->query_skill("force") < 100 )
		return notify_fail("你的内功火候不够！\n");

       if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIC "$N" HIC "大喝一声，手中的" + weapon->name() +
	      HIC "犹如狂风疾电一般劈向$n" HIC "！\n"
	      HIC "霎时间只见十八道刀气层层叠叠如波浪般汹涌而起，$n"
	      HIC "只觉得呼吸登时不畅。"NOR"\n";
	message_combatd(msg, me, target);
	me->add("neili", -100);

	count = me->query_skill("blade") / 2;
	me->add_temp("apply/attack", count);

	for (i = 0; i < 18; i++)
	{
		if (! me->is_fighting(target))
			break;
		COMBAT_D->do_attack(me, target, weapon, 0);
	}


	me->add_temp("apply/attack", -count);
	me->start_busy(1 + random(6));
	return 1;
}
