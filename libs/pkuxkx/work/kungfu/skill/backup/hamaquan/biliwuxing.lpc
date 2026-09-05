#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("hamaquan",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「霹雳无形」只能在战斗中使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「霹雳无形」只能空手使用。\n");		
       
	 if( (int)me->query("neili") < 100 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("hamaquan",1) < 20 )
                return notify_fail("你的蛤蟆拳火候不够，无法使用「霹雳无形」！\n");

        if( (int)me->query_skill("force",1) < 100 )
                return notify_fail("你的内功修为不够，无法使用「霹雳无形」！\n");
	me->add_temp("apply/attack",extra/2);
	me->add_temp("apply/damage",extra/2);
	weapon = me->query_temp("weapon");

        msg = BLU "$N脚踩蛤蟆步，落身于丈尺外，稍作停顿，突然握拳扑向$n，犹如苍天霹雳雷霆之式！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra/2);
	 me->add_temp("apply/damage",-extra/2);
        me->add("neili", -100);
        me->start_busy(2);
        return 1;
}

