// sleep.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	mapping my = me->query_entire_dbase();
	int step,sum;
	
	if (my["max_neili"] > (int)me->query_skill("force") * 10 && my["max_neili"] >100)
	{
		sum = my["max_neili"] - (int)me->query_skill("force") * 10;
		step = (int)(sum/30);
		if (step < 5) step = 5;
		if (sum<=step) step = sum;
		me->add("max_neili",0-step);
		tell_object(me,HIR+"你感觉你的内力修为似乎弱了一些，似乎现在的内功无法支撑这么高的内力上限了。\n"+NOR);
		if (step==sum) return 0;
		me->apply_condition("neili_reduce",1);
		return 1;
	} 
	else return 0;
}
