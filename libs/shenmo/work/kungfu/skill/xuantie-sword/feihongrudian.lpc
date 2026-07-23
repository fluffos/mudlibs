#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	int extra,i,time;
	string msg;
	extra = me->query_skill("xuantie-sword",1);
	time = extra/40; 
	if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「飞虹如电」只能在战斗中使用。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");
	if( userp(me) && (string)weapon->query("id") != "xuantiesword" )
		return notify_fail("你手中拿的不是玄铁剑。\n");
	if((int)me->query_skill("sword") < 205)
		return notify_fail("你的剑法修为不够， 目前不能使用飞虹如电! \n");
	weapon = me->query_temp("weapon");
	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");
	msg = HIR  "$N半空中猛吸一口真气，踏月随波，手中的"+ weapon->name()+  HIR"闪电般地化作一道金虹向$n卷来！" NOR;
	message_vision(msg,me,target);
	me->add_temp("apply/attack",extra/5);
	me->add_temp("apply/damage",extra/5);
	for(i=1;i<=(int)time;i++)
	{
	msg =  YEL "$N人意无情，剑气纵横！\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
        me->add_temp("apply/attack",-extra/5);
        me->add_temp("apply/damage",-extra/5);
	me->add("neili",-500);
	me->start_busy(5);
	return 1;
}
