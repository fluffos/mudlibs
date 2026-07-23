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
	extra = me->query_skill("six-finger",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「六脉惊神」只能在战斗中使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「六脉惊神」只能空手使用。\n");		

        if (me->query_skill("kurong-changong", 1)<70)
                return notify_fail("你的本门内功火候未到，！\n");
       	if(me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("没有枯荣禅功作为准备，无法使出！\n"); 
	 if( (int)me->query("neili") < 600 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("six-finger",1) < 180 )
                return notify_fail("你的六脉神剑火候不够，无法使用「六脉惊神」！\n");

        if( (int)me->query_skill("force",1) < 150 )
                return notify_fail("你的内功修为不够，无法使用「六脉惊神」！\n");
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra*2);
	weapon = me->query_temp("weapon");

        msg = CYN "$N心思涣乱，朝$n隔空遥指了几下，不料却使出了六脉剑法的精髓"HIY"[六脉惊神]"CYN"！" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------------------------少商剑！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = GRN   "-------------------------------商阳剑！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  MAG  "-------------------------------中冲剑！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL   "-------------------------------关冲剑！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT   "-------------------------------少泽剑！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLU   "-------------------------------少冲剑！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-extra);
	 me->add_temp("apply/damage",-extra*2);
        me->add("neili", -500);
        me->start_busy(3);

        return 1;
}

