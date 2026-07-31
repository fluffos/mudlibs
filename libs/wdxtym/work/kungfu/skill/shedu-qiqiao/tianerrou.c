// leidong 雷动九天
// by winder 98.12

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "天鹅"ZJBR"肉"; }
//string *pfm_type() { return ({ "force", }); }

int perform(object me)
{
	int skill, count, count1;

	if ((int)me->query_temp("tianerrou"))
		return notify_fail("你已经在运功中了。\n");

	if ((int)me->query("neili") < 500)
		return notify_fail("你现在的真气不够。\n");
	
	if ((int)me->query_skill("hamagong", 1) < 30)
		return notify_fail("你的蛤蟆功的修为不够 !\n");

	skill = (int)me->query_skill("shedu-qiqiao", 1);
	//if ((int)me->query_skill("shedu-qiqiao", 1) < 80)
	if (skill < 300)
		return notify_fail("你的修为还不够。\n");

	me->add("neili", -400);
	message_combatd(HIM "$N" HIM "深深吃了一口天鹅肉，"
			"，出手越来越重！"NOR"\n", me);

	count = skill / 10;

	if (me->is_fighting())
		me->start_busy(3);

	me->add_temp("str", count*2);
	//me->add_temp("dex", count);
	me->set_temp("tianerrou", 1);
	me->start_call_out((: call_other,  __FILE__, "remove_effect", me, count :), skill / 3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("tianerrou"))
	{
		me->add_temp("str", -amount);
		//me->add_temp("dex", -amount);
		me->delete_temp("tianerrou");
		tell_object(me, CYN "你的蛤蟆功运行完毕，将内力收回丹田。"NOR"\n");
	}
}
