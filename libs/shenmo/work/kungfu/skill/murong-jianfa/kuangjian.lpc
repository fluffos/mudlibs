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
        extra = (int)me->query_skill("murong-jianfa",1);
        if ( extra < 120) return notify_fail("你的慕容剑法还不够纯熟！\n");
        if((int)me->query_skill("canhe-zhi", 1) < 100 )
                return notify_fail("你的指法还未练成，不能使用［快剑］！\n");        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［快剑］只能对战斗中的对手使用。\n");
        if ((int)me->query("neili")<400)
                return notify_fail("你的内力不够。\n"); 

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

        if (me->query_skill("shenyuan-gong", 1)<70)
                return notify_fail("你的本门内功火候未到，！\n");

        me->add("neili",-350);
        weapon = me->query_temp("weapon");
        message_vision(HIM"$N使出慕容剑法中的绝招［快剑］，一招连环六剑，手中的"+weapon->name()+"闪电般向$n攻出第一剑！\n\n" NOR,me,target);        

	me->add_temp("apply/attack", extra/6);	
	me->add_temp("apply/damage", extra);

        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIW"华山剑法！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIC"泰山剑法！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"衡山五神剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIY"恒山剑法！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIB"嵩山剑法！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
	me->add_temp("apply/attack", -extra/6);	
	me->add_temp("apply/damage", -extra);
        
        
        message_vision(WHT"$N连出六剑，结果$n被攻了个手忙脚乱！\n" NOR,me,target);
        me->start_busy(2);
      
        return 1;
}
