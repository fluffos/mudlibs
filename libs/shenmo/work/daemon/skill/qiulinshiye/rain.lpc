// tie@fengyun
#include <ansi.h>
#include <combat.h>


inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("biyun-xinfa",1);
	if ( extra < 50) return notify_fail("你的［碧云心法］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［雨雾］只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经迷失方向！\n");
	message_vision( HIY "$N左手往$n一挥，唐门的雨雾发了出去！\n" NOR ,me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
	message_vision("结果$N被雨雾撒的不知方向！\n",target);
            target->apply_condition("ill_dongshang",55);
            target->apply_condition("ill_fashao", 55);
            target->apply_condition("ill_kesou", 55);
            target->apply_condition("ill_shanghan", 55);
            target->apply_condition("ill_zhongshu", 55);	
	target->start_busy(5);
	}
	else{
	msg = "可惜$N看出了$n的雨雾，向你迅然攻击！";
	me->start_busy(1);
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
	return 1;
}
