//Edit by cloth 2000-09-19
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("tianyu-qijian",1);
        if ( extra < 200) return notify_fail("你的天羽奇剑还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［天羽狂舞］只能对战斗中的对手使用。\n");
        if ((int)me->query("neili")<450)
                return notify_fail("你的内力不够。\n"); 
	if(((int)me->query_skill("bahuang-gong", 1) < 160 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 160 ))
		return notify_fail("你的本门内功不够娴熟。\n");

        me->add("neili",-350);
        weapon = me->query_temp("weapon");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

if (!me) return 0;
if (!target) return 0;
        message_vision(HIM"$N使出天羽奇剑中的绝招［天羽狂舞］，一招连环六剑，手中的"+weapon->name()+"闪电般向$n攻出第一剑！\n\n" NOR,me,target);        
	extra = me->query_skill("tianyu-qijian",1) / 10;
	extra += me->query_skill("tianyu-qijian",1) /10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIR"第二剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIC"第三剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIY"第四剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIG"第五剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIM"第六剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIW"最后一剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        if (me->query("combat_exp")> target->query("combat_exp")/3 )
        {                
        msg = HIC "一道生死符"+HIM+"打中$n的身上,$n只觉得伤口一冷！\n"NOR;   
                message_vision(msg, me, target);
		target->apply_condition("ss_poison", 35);
                if (!target->is_busy())
                target->start_busy(2);
        }
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 3)
        {                
        msg = HIY "一道生死符"+HIM+"打中$n的身上,$n只觉得伤口一冷！\n"NOR;   
                message_vision(msg, me, target);
		target->apply_condition("ss_poison", 35);
                if (!target->is_busy())
                target->start_busy(2);
        }
        if (random(me->query_skill("force")) > target->query_skill("force") / 3)
        {                
        msg = HIR "一道生死符"+HIM+"打中$n的身上,$n只觉得伤口一冷！\n"NOR;   
                message_vision(msg, me, target);
		target->apply_condition("ss_poison", 35);
                if (!target->is_busy())
                target->start_busy(2);
        }
       
        
        message_vision(WHT"$N连出七剑，结果$n被攻了个手忙脚乱！\n" NOR,me,target);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

        me->start_busy(3);


        return 1;
}

