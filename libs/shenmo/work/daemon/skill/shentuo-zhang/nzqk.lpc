 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int mine,yours;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［扭转乾坤］只能对战斗中的对手使用。\n");
		
	if ((int)me->query_skill("shentuo-zhang", 1) < 180)
		return notify_fail("你的神驼雪山掌不够娴熟。\n");
	                        
	if ((int)me->query("neili") < 200)
		return notify_fail("你现在真气不够。\n");

        mine = (int) me->query("combat_exp");
        yours = (int) target->query("combat_exp");
        message_vision(HIW"\n$N突然暴喝一声：扭－－转－－乾－－坤！！！\n\n",me);
        if(random(mine) > yours)
        {
                //me->add("force_factor",yours/2);
                msg= HIY "$N将神驼雪山掌中的［扭转乾坤］使出，双掌夹带着$n的内力击向$n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                target->start_busy(3);
               
                //me->add("force_factor",-yours/2);
        }               
        else
        {
                //target->add("force_factor",mine/2);
                msg= HIY "$N趁着$n暴喝之际，单腿直踢，以迅捷无比的速度功向$n！" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                //target->add("force_factor",-mine/2); 
        }
        
	      msg = RED  "右一掌！" NOR;
	      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "左一掌！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "上一掌！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "下一掌！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "前一掌！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "后一掌！！！！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = RED  "最后一掌!!!!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -300);
         me->start_busy(2);
        return 1;
}   
