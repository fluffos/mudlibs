// 软虹蛛索 

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("『软虹蛛索』只能对战斗中的对手使用。\n");
        
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        if((int)me->query_skill("wuxian-bianfa",1 ) < 100)
                return notify_fail("你的五仙鞭法等级不够，不能使用『软虹蛛索』。\n");
        if (me->is_busy())
        {
            return notify_fail("你正忙着呢。\n");
        }
        if( (!objectp(weapon = me->query_temp("weapon"))
      || (string)weapon->query("skill_type") != "whip") )
                return notify_fail("你必须使鞭才能使「软虹蛛索」。\n");
        if( (int)me->query("neili") < 1000  ) 
                return notify_fail("你的内力不够。\n");

        msg = WHT+ "$N使出『软虹蛛索』，连挥数鞭企图把$n的全身缠绕起来。\n" NOR;

        me->add_busy(2);
        //C-|C-=B+修改成B&B=C-
        if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 5, me, target)
         && F_KUNGFU->hit_rate( me->query_dex(), (int)target->query_dex(), 5, me, target) ) 
        {
                msg += WHT "结果$p被$P的鞭影缠绕住了全身！\n" NOR;
                F_KUNGFU->hit_busy( "body", (int)me->query_skill("wuxian-bianfa")/20+3, target );
        } else {
                msg += HIC "可是$p看破了$P的企图，险险避了开去，却惊出一身冷汗。\n" NOR;
                target->add_busy(1);
        }
        message_vision(msg, me, target);

        return 1;
}


