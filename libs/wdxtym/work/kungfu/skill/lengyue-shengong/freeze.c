// freeze.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me);

string query_name() { return "冷月"ZJBR"刺骨"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int ap;
	int dp;
	int damage;
	string msg;

	if (target == me || ! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}

	if (! me->is_fighting(target))
		return notify_fail("你只能用寒气攻击战斗中的对手。\n");

	if (me->query_skill("lengyue-shengong", 1) < 150)
		return notify_fail("你的冷月神功火候不够，无法运用寒气。\n");

	if ((int)me->query("neili") < 1000)
		return notify_fail("你的内力不够！");

	if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIW "$N" HIW "默运冷月神功，一股寒气迎面扑向$n"
	      HIW "，四周登时雪花飘飘。"NOR"\n";

	ap = me->query_skill("force");
	dp = target->query_skill("force");

	me->start_busy(2);

	if (ap / 2 + random(ap) > dp)
	{
		damage = ap + random(ap / 3);
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage, me);
		if (target->query("neili") > damage)
			target->add("neili", -damage);
		else
			target->set("neili", 0);

		msg += HIG "$n" HIG "忽然觉得一阵透骨寒意，霎时间"
		       "浑身的血液几乎都要凝固了。"NOR"\n";
		if (! target->is_busy())
			target->start_busy(1);

		target->set_temp("lengyue-shengong_freeze", 1);
		target->start_call_out((: call_other, __FILE__, "remove_effect", target :),
				       me->query_skill("lengyue-shengong") / 5);

	} else
		msg += HIY "$n" HIY "感到一阵寒意自心底泛起，连忙"
		       "运动抵抗，堪勘无事。"NOR"\n";

	message_combatd(msg, me, target);

	return 1;
}

void remove_effect(object me)
{
	if ((int)me->query_temp("lengyue-shengong_freeze"))
	{
		me->delete_temp("lengyue-shengong_freeze");
		tell_object(me, HIY "你感到身边的寒气渐渐散去了。"NOR"\n");
	}
}

