// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("meng-steps",1);
	if ( extra < 50) return notify_fail("你的［幻梦步法］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［幻影千重］只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	message_vision( HIR "$N的身影突然一变十、十变百、百变千，$n早被$N的千重幻影围住！\n" NOR ,me,target);
	if(random((int)me->query("combat_exp"))+(int)me->query("combat_exp")/4 > (int)target->query("combat_exp")/2)
	{
	message_vision(HIW "结果$N目眩神弛，心惊肉跳！\n"NOR,target);
	target->start_busy(3);
	}
	else{
	message_vision("结果$N并不慌张！\n",target);
	me->start_busy(2);
	}
	return 1;
}

