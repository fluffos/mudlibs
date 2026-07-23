// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	extra = me->query_skill("demon-steps",1);
	if ( extra < 30) return notify_fail("你的［如意人魔连环八步］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［连环八步］只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	message_vision("$N脚踩连环，环绕着$n转个不停！\n",me,target);
	if(random((int)me->query("combat_exp"))+(int)me->query("combat_exp")/4 > (int)target->query("combat_exp")/2)
	{
	message_vision("结果$N被扰得眼花潦乱，接应不暇！\n",target);
	target->start_busy(3);
	}
	else{
	message_vision("结果$N自己转了个头晕眼花！\n",me);
	me->start_busy(2);
	}
	return 1;
}
