// taixuan.c 太玄劲

#include <ansi.h>

inherit F_SSERVER;
 
string query_name() { return "太玄劲"; }

int perform(object me, object target)
{
	string msg;
	int count;
	int lvl;
	int i;
 
	if (! target)
	{
		me->clean_up_enemy();
		target = me->select_opponent();
	}
	count = 0;
	if (! target || ! me->is_fighting(target))
		return notify_fail("「太玄劲」只能对战斗中的对手使用。\n");
		
 	/*if (me->query_skill_prepared("unarmed") != "taixuan-gong")
		return notify_fail("你没有准备使用太玄功，无法施展「太玄劲」。\n");*/
		
	if (objectp(me->query_temp("weapon")))
		return notify_fail("施展「太玄劲」必须空手！\n");
	
	if (me->query_temp("taixuan")>time()) return notify_fail("你上一招未使完！\n");

	if ((int)me->query("neili") < 150)
		return notify_fail("你的真气不够，无法施展「太玄劲」！\n");

	if ((int)me->query_skill("force") < 200)
		return notify_fail("你的内功火候不够，难以施展「太玄劲」！\n");

	if ((lvl = (int)me->query_skill("taixuan-gong", 1)) < 100)
		return notify_fail("你的太玄神功还不到家，无法使用太玄劲！\n");

    if (! living(target))
	      return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

	msg = HIY "$N" HIY "一声呼喝，飞身扑上前来，双手虚虚实实的抓向$n"
	      HIY "！"NOR"\n";

	if (lvl / 2 + random(lvl) > target->query_skill("parry") / 2)
	{
		msg += HIR "$n" HIR "见了$N" HIR "这般奇妙的招数，大"
		       "吃一惊，一时间想不好该如何招架！"NOR"\n";
		count = lvl / 3;
		target->add_temp("apply/parry", -count);
		target->add_temp("apply/dodge", -count);
	}

	message_combatd(msg, me, target);
	me->add("neili", -120);

	for (i = 0; i < 6; i++)
	{
		if (! me->is_fighting(target))
			break;

		if (random(3) == 1 && ! target->is_busy())
			target->start_busy(1);

		COMBAT_D->do_attack(me, target, 0, 0);
	}
me->set_temp("taixuan",time()+15);
	//me->start_busy(1 + random(5));
	target->add_temp("apply/parry", count);
	target->add_temp("apply/dodge", count);
	return 1;
}
