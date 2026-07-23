// sanjue.c  达摩剑 [达摩三绝剑]
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	string msg;
        int extra;
        extra = me->query_skill("tianyu-qijian",1);

	 if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「达摩三绝剑」只能在战斗中使用。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");
	if((int)me->query_skill("hunyuan-yiqi",1) < 60)
		return notify_fail("你的混元一气功的修为不够, 不能使用这一绝技 !\n");
	if((int)me->query_skill("sword") < 135)
		return notify_fail("你的剑法修为不够， 目前不能使用达摩三绝剑! \n");
	weapon = me->query_temp("weapon");
	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");
	
	extra = me->query_skill("damo-jian",1) / 20;
	extra += me->query_skill("damo-jian",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	msg = HIG "$N使出达摩剑的绝技「达摩三绝剑」，身法陡然加快！\n" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIC  "$N身形加快，反手又是一剑！ \n" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "$N身形逆转，朝着$n又是一剑！ \n" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

	me->add("neili", -150);
	me->start_busy(2);
	return 1;
}
