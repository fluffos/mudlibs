// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,a;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［狗急跳墙］只能对战斗中的对手使用。\n");

               if( objectp(me->query_temp("weapon")) )
              return notify_fail("你必须空手使用！\n");
              
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("你的内力不够。\n");
        if ( (int)me->query("neili") < 1500)
                return notify_fail("你的真气不够。\n");


	weapon = me->query_temp("weapon");
	extra = me->query_skill("xiaoyaoyou",1) / 20;
		 msg = YEL "$N凌空一跳，身形如被逼急的野狗，双脚一前一后，狠命地向$n踢出！" NOR;
    COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);   
if (extra>200) extra=200;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
a=extra/2;
if (a> 12) a=12;
	for(i=0;i<a;i++)
	{
	msg = HIR  "$N身随意转，轻轻一纵踢出第"+chinese_number(i+1)+ "脚！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili", - 30);
	}
	me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
