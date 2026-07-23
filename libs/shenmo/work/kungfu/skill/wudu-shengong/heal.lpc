// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if ((int)me->query_skill("wudu-shengong", 1) < 30)
		return notify_fail("你的五毒神功修为还不够。\n");
	if( (int)me->query("neili") < 50 ) 
		return notify_fail("你的真气不够。\n");
       
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	write( HIW "你全身放松，五毒神功流转全身。\n" NOR);
	message("vision",
		HIW + me->name() + "面颊现出一片潮红，额头上沁出细细的汗珠。\n" NOR,
		environment(me), me);
       me->set_temp("nopoison", 1);
       me->apply_condition("yf_poison",0);
       me->apply_condition("nx_poison",0);
       me->apply_condition("x2_poison",0);
       me->apply_condition("xx_poison",0);
       me->apply_condition("ice_poison",0);
       me->apply_condition("ss_poison",0);
	write( HIW "你轻轻呼出一口气，将真气收归丹田，感觉精神好多了。\n" NOR);
	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
	return 1;
}
