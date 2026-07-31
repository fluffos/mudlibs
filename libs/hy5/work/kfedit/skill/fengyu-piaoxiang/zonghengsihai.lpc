// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("fengyu-piaoxiang",1);
	if ( extra < 70) return notify_fail("你的［风雨飘香步］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［纵横四海］只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	message_vision( HIY "$N身形突然加快，如同天助，潇洒倜倘又有纵横四海之气势！\n" NOR ,me,target);
	if(random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
	message_vision(HIB "结果$N缚手缚脚，一筹莫展！！\n"NOR,target);
	target->start_busy(5);
	}
	else{
	message_vision("结果$N并不慌张！\n",target);
	me->start_busy(2);
	
	}
	return 1;
}

