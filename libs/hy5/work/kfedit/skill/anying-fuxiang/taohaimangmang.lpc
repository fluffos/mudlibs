#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("anying-fuxiang",1);
	if ( extra < 90) return notify_fail("你的［暗影浮香步］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［桃海茫茫］只能对战斗中的对手使用。\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在内力不足！\n");     
        if( me->query_skill("bibo-shengong",1) < 80)
return notify_fail("你的碧波神功修为火候未到，施展「桃海茫茫」只会伤及自身！\n");

	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	message_vision(HIM"$N身形骤然加快，四周顿起一阵桃花似海，绕$n飞舞不停！\n"NOR,me,target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) 
	{
	message_vision("结果$N被扰得眼花潦乱，接应不暇！\n",target);
	me->start_busy(1);
	target->start_busy(4);
	}
	else{
	me->start_busy(4);
	msg = "可惜$N看出了$n的身法，向你迅然攻击！";
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
me->add("neili", -150);
	return 1;
}
