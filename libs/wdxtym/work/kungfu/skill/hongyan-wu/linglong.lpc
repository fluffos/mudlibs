#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount, int amount1);

string query_name() { return "玲"ZJBR"珑"; }

int perform(object me, object target)
{
	object weapon;  
	string msg;
	int count, skill;

	if ((int)me->query_temp("ling_long"))
		return notify_fail("你已经运起「玲珑」了。\n");

	if ((int)me->query_skill("hongyan-wu", 1) < 120)
		return notify_fail("你的红颜玲珑舞还不够娴熟，难以施展此项绝技！\n");

	if ((int)me->query_dex() < 30)
		return notify_fail("你的身法不够使用「玲珑」绝技！\n");

	if ((int)me->query_skill("force", 1) < 50)
		return notify_fail("你的内功火候不够，难以施展此项绝技！\n");

	if ((int)me->query_skill("dodge", 1) < 50)
		return notify_fail("你的轻功修为不够，不会使用此项绝技！\n");

	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力修为不够使用「玲珑」！\n");

	if ((int)me->query("neili") < 250)
		return notify_fail("你此时的内力不足！\n");

	msg = HBCYN "$N" HBCYN "运起玲珑真气，朱唇轻起：冷然一身落红尘，真颜非颜是吾身。紧接着玉手一展，翩翩起舞，身形渐虚，整个人好似已进入另一个天地。"NOR"\n";
	
	message_combatd(msg, me, target);
	skill = me->query_skill("hongyan-wu", 1);

	count = skill / 30;

	if (me->is_fighting())
		me->start_busy(2);

	//me->add_temp("str", count);
	me->add_temp("dex", count);
	me->set_temp("ling_long", 1);
	me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), skill / 1);

	me->add("neili", -200);
	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	if ((int)me->query_temp("ling_long"))
	{
		//me->add_temp("str", -amount);
		me->add_temp("dex", -amount);
		me->delete_temp("ling_long");
		tell_object(me, "你的「玲珑」运功完毕，将内力收回丹田。\n");
	}
}
