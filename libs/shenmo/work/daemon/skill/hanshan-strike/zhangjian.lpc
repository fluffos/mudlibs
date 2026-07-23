#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,bonus, exp_bonus;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［掌剑］只能对战斗中的对手使用。\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "只能空手施展。\n");
        extra = me->query_skill("hanshan-strike",1) ;
        if( extra < 90) return notify_fail("你的［寒山掌法］还不够熟练！\n");
        
        bonus=extra/3;
         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("你的冰雪心法修为不够。\n");

         if((int)me->query_skill("snow-zhang",1) < 150)
                return notify_fail("你的飞雪映梅掌修为不够。\n");

         if((int)me->query_skill("hanshan-strike",1) < 50)
                return notify_fail("你的这门武功修为不够。\n");
        
        exp_bonus= me->query("combat_exp")/1000*extra/5000;
        if (exp_bonus>extra) exp_bonus=extra;
        
        bonus = bonus + exp_bonus;
        
        if (bonus> 300) bonus=300;
        
        me->add_temp("apply/attack", bonus);
        me->add_temp("apply/damage", bonus);
        msg = HIM  "$N双掌互相交错，突一纵身，双手化掌为剑疾向$n"NOR+HIM"削去！" NOR;
        if (random(3)==0) target->start_busy(3);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N一侧身，一肘撞向$n"NOR+HIY"的面门！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (extra>110) {
        msg = HIW  "$N又一反身，双掌急向$n"NOR+HIW"砍去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        if (extra>150) {
        msg = HIR  "$N左手横胸，右手忽一亮掌，蓄力已久的［掌剑］破空向$n"NOR+HIR"刺去！" NOR;
        me->add_temp("apply/attack", bonus);
        me->add_temp("apply/damage", bonus);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if (random(2)==0 ) 
{
        message_vision( MAG "$N被掌法产生的幻象所迷惑,显得两眼迷茫...， 伴随着重重的一声闷哼，一股血气从顶门喷涌而出！\n" NOR,target);
        target->receive_wound("qi",bonus*8);
}
        me->add_temp("apply/attack", -bonus);
   me->add_temp("apply/damage", -bonus);
        }
        me->add_temp("apply/attack", -bonus);
        me->add_temp("apply/damage", -bonus);
me->start_busy(3);
me->add("neili", -250);
        return 1;
}      
