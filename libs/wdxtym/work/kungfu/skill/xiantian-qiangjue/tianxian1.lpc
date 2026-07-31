// zuida.c 少林醉棍 先天枪诀

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount, int amount1);

string query_name() { return "弑神"ZJBR"诛仙"; }

int perform(object me, object target)
{
	object weapon;	
  	string msg;
	int count, count1, cnt, skill;
	
	if (! me->is_fighting())
		return notify_fail("「弑神诛仙」只能在战斗中使用。\n");

	if (! objectp(weapon = me->query_temp("weapon")) ||
	    (string)weapon->query("skill_type") != "spear")
		return notify_fail("你使用的武器不对。\n");

	if ((int)me->query_temp("tianxian-qiangjue"))
		return notify_fail("你已经在运功中了。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经运起内功加力了，没有更多的内力使用先天枪诀。\n");

	if ((int)me->query_str() < 35)
		return notify_fail("你现在的臂力不够，目前不能使用此绝技！\n");

	if ((int)me->query_skill("force") < 600)
		return notify_fail("你的内功火候不够，难以施展此项绝技！\n");

	if ((int)me->query_skill("spear") < 300)
		return notify_fail("你的枪法修为不够，不会使用此项绝技！\n");

	if ((int)me->query("neili") < 1000)
		return notify_fail("你的真气不足！\n");

	msg = HIY "$N" HIY "使出先天枪诀的绝技「弑神诛仙」，臂"
	      "力陡然增加, 枪法陡然加快！"NOR"\n";

   	message_combatd(msg, me, target);
	skill = me->query_skill("tianxian-qiangjue",1);
	cnt =(int)( (int)me->query_condition("drunk") * 25 / 1);
	count = me->query("str") * random(cnt + 2);
	count1 = me->query("dex") * random(cnt + 2);

	me->add_temp("str", count);
	me->add_temp("dex", count1);
	me->set_temp("tianxian-qiangjue", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect",
			   me, count, count1 :), skill * 25 / 1);

	me->add("neili", -1000);
   	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	if ((int)me->query_temp("tianxian-qiangjue"))
	{
		me->add_temp("str", -amount);
		me->add_temp("dex", -amount1);
		me->delete_temp("tianxian-qiangjue");
		tell_object(me, "你的先天枪诀运功完毕，将内力收回丹田。\n");
	}
}
