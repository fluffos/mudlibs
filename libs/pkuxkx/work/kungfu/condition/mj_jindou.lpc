//明教筋斗,zine@pkuxkx 2013-2
inherit F_CLEAN_UP;
#include <ansi.h>
#include <condition.h>

int remove_eff(object target)
{
	int type,eff;
	type=target->query_temp("mj_jindou_eff");
	eff =target->query_temp("mj_jindou_value");
	if (type==1)
	target->add_temp("apply/dodge", -eff);
	if (type==2)
	target->add_temp("apply/attack_speed", -eff);
	if (type==3)
	target->add_temp("apply/dodge", eff);
	if (type==4)
	target->add_temp("apply/attack_speed", eff);
	target->delete_temp("mj_jindou_eff");
	target->delete_temp("mj_jindou_value");
	return 1;
}

int update_condition(object me, int duration)
{
	if( duration < 1 ) 
	{
		remove_eff(me);
		if (userp(me))
		tell_object(me,HIG+"圣火令法绝技【筋斗】的效果在你身上消失了。\n"+NOR);
		return 0;
	}
	if (userp(me)&&!me->query_temp("mj_jindou_value"))
	{
		tell_object(me,HIG+"圣火令法绝技【筋斗】的效果在你身上消失了。\n"+NOR);
		return 0;
	}
   me->apply_condition("mj_jindou", duration - 1);
   return CND_CONTINUE;
}
