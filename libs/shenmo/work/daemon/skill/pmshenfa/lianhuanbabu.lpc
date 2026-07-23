// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("pmshenfa",1);
	if ( extra < 60) return notify_fail("你的［飘渺身法］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［连环八步］只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	message_vision(HIC"$N脚踩天魔 地魔 人魔 三连环，环绕着$n转个不停！\n"NOR,me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
	message_vision(RED"结果$N被扰得眼花潦乱，接应不暇！\n"NOR,target);
	target->start_busy(5);
	me->start_busy(1);
	}
	else{
	message_vision(YEL"结果$N自己转了个头晕眼花！\n"NOR,me);
	me->start_busy(1);
	}
	return 1;
}
